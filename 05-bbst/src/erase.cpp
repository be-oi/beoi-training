// TODO: test this code
void erase(pnode& t, int X) {
	if(!t)           return; // Not found
	if(t->key == X)  merge(t, t->l, t->r);
	else             erase(X > t->key ? t->r : t->l, X);
}
// TODO: test this code
void erase(pnode& t, int X) {
	pnode a, b, c;
	split(t, X->val+1, b, c);
	split(b, X->val, a, b);
	merge(t, a, c);
}
