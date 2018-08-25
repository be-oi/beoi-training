// TODO: test this code
void split(pnode t, int X, pnode* l, pnode* r) {
	if(!t)
		*l = *r = 0;
	if(t->key > X)
		split(t->l, X, l, &t->l), *r = t;
	else
		split(t->r, X, &t->r, r), *l = t;
}
