// TODO: test this code
void split(pnode t, int X, pnode& l, pnode& r, int before = 0) {
	if(!t) {
		l = r = 0;
		return;
	}
	int key = before + size(t->l);
	if(key < X)  split(t->r, X, t->r, r, before+size(t->l)+1), l = t;
	else         split(t->l, X, l, t->l, before             ), r = t;
	update_size(t);
}
