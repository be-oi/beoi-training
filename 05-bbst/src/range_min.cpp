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
	split(t, r+1, b, c);
	split(b, l, a, b);
	int result = get_min(b);
	merge(b, a, b);
	merge(t, b, c);
	return result;
}
