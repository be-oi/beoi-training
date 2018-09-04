// TODO: test this code
void merge(pnode& t, pnode l, pnode r) {
	if(!l || !r)          t = l ? l : r;
	else if(l.pr > r.pr)  merge(l->r, l->r, r), t = l;
	else                  merge(r->l, l, r->l), t = r;
}

