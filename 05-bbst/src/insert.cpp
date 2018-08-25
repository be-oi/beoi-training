// TODO: test this code
void insert(pnode& t, pnode it) {
	if(!t)
		t = it;
	else if(t.pr < it.pr)
		split(t, it->l, it->r), t = it;
	else
		insert(it->key > t->key ? t->r : t->l, it);
}
