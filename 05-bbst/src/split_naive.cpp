// TODO: test this code
void split(pnode t, int X, pnode* l, pnode* r) {
	if(!t) return;
	if(t->key > X) {
		pnode newt = t->l; t->l = 0;
		*r = t;
		split(newt, X, l, &t->l);
	} else {
		pnode newt = t->r; t->r = 0;
		*l = t;
		split(newt, X, &t->r, r);
	}
}
