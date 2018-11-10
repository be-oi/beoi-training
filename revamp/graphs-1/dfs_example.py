file_output = open("dfs_example.tex", "w")


V = []
V.append((1, 0, 0))
V.append((2, 2.5, 1.3))
V.append((3, 1.6, -0.25))
V.append((4, 1.8, -1.5))
V.append((5, 1.3, -2.65))
V.append((6, -0.4, -2.1))
V.append((7, 3.8, 0.2))
V.append((8, 3.2, -1.9))
V.append((9, 2.7, -2.85))
V.append((10, 2.5, -1.75/2))

E = []

E.append((1, 2))
E.append((1, 3))
E.append((1, 4))
E.append((1, 5))
E.append((1, 6))
E.append((2, 7))
E.append((3, 7))
E.append((3, 4))
E.append((4, 5))
E.append((4, 6))
E.append((4, 8))
E.append((4, 10))
E.append((5, 6))
E.append((5, 9))
E.append((7, 8))
E.append((7, 10))
E.append((8, 9))

vis = [False for i in range(len(V))]

node_act = -1
edge_act = -1


F, T = 0, 0

def dfs(i):
	global edge_act, node_act, F, T
	if vis[i]:
		return
	else:
		vis[i] = True
		edge_act = -1
		node_act = i
		print_graph()

		for j in range(len(E)):
			f, t = E[j]
			if f == i+1:
				node_act = i
				edge_act = j
				F = f
				T = t
				print_graph()
				dfs(t-1)
			if t == i+1:
				node_act = i
				edge_act = j
				F = t
				T = f
				print_graph()
				dfs(f-1)

		node_act = i
		edge_act = -1
		print_graph()


def print_graph():
	global edge_act, node_act, F, T
	file_output.write("\\begin{frame}{DFS : Example}\n")
	file_output.write("\\begin{figure}\n")
	file_output.write("\\center\n")
	file_output.write("\\begin{tikzpicture}[scale=1.3] \n")

	file_output.write("\\node[shape=circle, draw=red, 	ultra thick, scale=1.5pt, label={Current}] (U) at (-3, 1) {}; \n")
	file_output.write("\\node[shape=circle, draw=green,  ultra thick, scale=1.5pt, label={Visited}] (U) at (-3, 0) {}; \n")
	file_output.write("\\node[shape=circle, draw=black, ultra thick, scale=1.5pt, label={Unvisited}] (U) at (-3, -1) {}; \n")

	for v in V:
		name, x, y = v
		if name - 1 == node_act:
			file_output.write("\\node[shape=circle,draw=red, ultra thick] (" + str(name) + ") at (" + str(x) + "," + str(y) + ") {" + str(name) + "}; \n")
		elif vis[name - 1]:
			file_output.write("\\node[shape=circle,draw=green, ultra thick] (" + str(name) + ") at (" + str(x) + "," + str(y) + ") {" + str(name) + "}; \n")
		else:
			file_output.write("\\node[shape=circle,draw=black, ultra thick] (" + str(name) + ") at (" + str(x) + "," + str(y) + ") {" + str(name) + "}; \n")

	for j in range(len(E)):
		if j != edge_act:
			t, f = E[j]
			file_output.write("\\path [-,very thick, draw=black] ("+str(f)+") edge  ("+str(t)+");\n")


	if edge_act != -1:
		file_output.write("\\path [->,very thick, draw=red] ("+str(F)+") edge  ("+str(T)+");\n")
		

	file_output.write("\\end{tikzpicture} \n")
	file_output.write("\\end{figure} \n")
	file_output.write("\\end{frame} \n")

dfs(0)
