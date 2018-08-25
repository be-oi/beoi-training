// TODO: test this code
int size(pnode t) {
	return t ? t->size : 0;
}
void update_size(pnode t) {
	if(!t) return;
	t->size = size(t->l) + 1 + size(t->r);
}
