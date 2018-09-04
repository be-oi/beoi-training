// TODO: test this code
void insert(pnode& t, pnode it) {
	if(!t)                 t = it;
	else if(t.pr < it.pr)  split(t, it->l, it->r), t = it;
	else                   insert(it->key > t->key ? t->r : t->l, it);
}
// TODO: test this code
void insert(pnode& t, pnode it) {
	pnode a, b;
	split(t, it->val, a, b);
	merge(it, a, it); merge(t, it, b);
}
