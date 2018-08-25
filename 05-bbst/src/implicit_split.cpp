// TODO: test this code
void split(pnode t, int X, pnode& l, pnode& r, int before = 0) {
	if(!t)
		l = r = 0;
	int key = before + size(t->l);
	if(key > X)
		split(t->l, X, l, t->l, before), r = t;
	else
		split(t->r, X, t->r, r, before+size(t->l)+1), l = t;
	update_size(t);
}
