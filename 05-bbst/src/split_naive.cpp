// TODO: test this code
void split(pnode t, int X, pnode* l, pnode* r) {
	if(!t) return;
	if(t->key < X) {
		*l = t;
		pnode newt = t->r; t->r = 0;
		split(newt, X, &t->r, r);
	} else {
		*r = t;
		pnode newt = t->l; t->l = 0;
		split(newt, X, l, &t->l);
	}
}
