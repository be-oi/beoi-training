// TODO: test this code
int find_index(pnode& t, int X, int before=0) {
	if(!t)
		return -1; // Not found.
	else if(t->key == X)
		return before + size(t->r);
	else
		return find_index(t->key < X ? t->r : t->l, X,
		before + (t->key < X ? size(t->r) + 1 : 0));
}
