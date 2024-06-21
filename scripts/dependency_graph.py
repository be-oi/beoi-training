#!/usr/bin/env python3
import sys, os, re, collections, shutil, subprocess

BASEDIR = os.path.abspath(os.path.join(os.path.dirname(__file__), os.path.pardir))

Unit = collections.namedtuple("Unit", ["idx", "name", "dir"])

def get_units():
    def make_unit(tpl):
        return Unit(int(tpl[0]), *tpl[1:])

    unit_re = r"(\d+). \[(.+)]\(([^)]+)\)"
    with open(os.path.join(BASEDIR, "README.md")) as f:
        main_readme = f.read()
    return dict((tpl[2], make_unit(tpl)) for tpl in re.findall(unit_re, main_readme))


def get_dependencies(unit, units):
    dep_re = r"\[.*\]\(\.\./([^)]*)\)"
    try:
        with open(os.path.join(BASEDIR, unit.dir, "README.md")) as f:
            readme_content = f.read()
    except IOError:
        sys.stderr.write("Cannot find README file for '%s'\n" % unit.name)
        return []
    deps = [] 
    used = set()
    for dep in re.findall(dep_re, readme_content):
        if dep not in units:
            sys.stderr.write("Unknown dependency: %s\n" % dep)
            continue
        if units[dep].idx not in used:
            deps.append(units[dep])
            used.add(units[dep].idx)
    return deps


def all_deps(deps, unit):
    if unit.idx in all_deps.cache:
        return all_deps.cache[unit.idx]
    s = set()
    for d in deps[unit]:
        s |= all_deps(deps, d)
        s.add(d)
    return all_deps.cache.setdefault(unit.idx, s)
all_deps.cache = {}

def eliminate_transitive_deps(dep_dict):
    for unit, deps in dep_dict.items():
        transitive = set()
        for d in deps:
            transitive |= all_deps(dep_dict, d)
        for t in transitive:
            if t in deps:
                deps.remove(t)

def summarize_single(u):
    return "%02d-%s" % (u.idx, "".join(t[0].upper() for t in u.dir.split("-") if t and t.isalpha()))

def summarize(units):
    return dict((summarize_single(u), u) for u in units.values())

def build_dot(dependencies):
    edges = [(summarize_single(u), summarize_single(v)) for u in sorted(dependencies) for v in sorted(dependencies[u])]
    dot_edges = "\n".join('"%s" -> "%s"' % e for e in edges)
    return "digraph {\n%s\n}" % dot_edges

def add_links(svg, summarized):
    def replace(tpl):
        total, title = tpl.groups()
        title = title.replace("&#45;", "-")
        return "<a xlink:href=\"%s\">%s</a>" % (summarized[title].dir, total)

    node_regex = r'(<g[^>]*>\s*<title>([^<]*)</title>\s*<ellipse[^/]*/>\s*<text[^>]*>[^<]*</text>\s*</g>)'
    return re.sub(node_regex, replace, svg)

def toposort(G, node=None, vis=None):
    if vis is None:
        vis = set()

    if node is None:
        res = []
        for node in sorted(G, key=lambda n: n.idx):
            res += toposort(G, node, vis)
        return res
    else:
        if node in vis: return []
        vis.add(node)

        res = []
        for neigh in sorted(G[node], key=lambda n: n.idx):
            res += toposort(G, neigh, vis)
        res.append(node)
        return res

if __name__ == "__main__":
    # Find the graphviz dot executable
    dot_location = shutil.which("dot")
    if not dot_location:
        sys.stderr.write("Cannot find the 'dot' executable, please install graphviz\n")
        sys.exit(1)

    # Parse main readme
    units = get_units()

    # Build the dependency_graph, parsing unit readme's
    dependencies = dict((u, get_dependencies(u, units)) for _, u in units.items())

    # Eliminate dependencies of the form a->c where a->b and b->c
    eliminate_transitive_deps(dependencies)

    # A graphviz representation
    dot_graph = build_dot(dependencies)

    # Make the svg
    pipe = subprocess.Popen([dot_location, "-Tsvg"], stdin=subprocess.PIPE, stdout=subprocess.PIPE)
    (svg, _) = pipe.communicate(bytes(dot_graph, "utf-8"))

    # Add hyperlinks to the units in the svg
    # Doesn't seem to work in github unfortunately (maybe with gh-pages)
    svg = add_links(str(svg, "utf-8"), summarize(units))

    # Write the svg
    with open(os.path.join(BASEDIR, "dependency_graph.svg"), "w") as out:
        out.write(svg)

    # Svg is not displayed in the readme on the repo, so we use a png
    pipe = subprocess.Popen([dot_location, "-Tpng"], stdin=subprocess.PIPE, stdout=subprocess.PIPE)
    (png, _) = pipe.communicate(bytes(dot_graph, "utf-8"))
    with open(os.path.join(BASEDIR, "dependency_graph.png"), "wb") as out:
        out.write(png)

    # Some toposorting
    # We might want something else for the reporting
    print()
    print("Recommended order:")
    for unit in toposort(dependencies):
        print(" ", "Unit %s:" % unit.idx, unit.name)
