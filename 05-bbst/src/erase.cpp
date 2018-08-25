// TODO: test this code
void erase(pnode& t, int X) {
	if(!t)
		return; // Not found
	if(t->key == X)
		merge(t, t->l, t->r);
	else
		erase(X > t->key ? t->r : r->l, X);
}
