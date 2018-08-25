// TODO: test this code
void reverse(pnode t) {
	if(!t) return;
	t->rev = !t->rev;
}
void propagate(pnode t) {
	if(!t) return;
	if(t->rev) {
		reverse(t->l); reverse(t->r);
		swap(t->l, t->r); t->rev = false;
	}
}
void range_reverse(pnode& t, int l, int r) {
	pnode a, b, c;
	split(t, l-1, a, b);
	split(b, r, b, c);
	reverse(b);
	merge(b, b, c);
	merge(t, a, b);
}
