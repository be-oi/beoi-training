// TODO: test this code
int get_min(pnode t) {
	return t ? t->min : INF;
}
void update_min(pnode t) {
	// call after split, merge, insert, erase
	if(!t) return;
	t->min = min(min(get_min(t->l), get_min(t->r)), t->val);
}
int rmq(pnode& t, int l, int r) {
	pnode a, b, c;
	split(t, l-1, a, b);
	split(b, r, b, c);
	int result = get_min(b);
	merge(b, b, c);
	merge(t, a, b);
	return result;
}
