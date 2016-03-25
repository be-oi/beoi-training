void update(int p, int L, int R, int i, int j, int k) {
    propagate(p, L, R);

    if(i > R || j < L) return;
    if(L >= i && R <= j) {
        lazy[p] = k;
        return;
    }

    update(2*p, L, (L+R)/2, i, j, k);
    update(2*p+1, (L+R)/2+1, R, i, j, k);

    st[p] = st[2*p] + st[2*p+1];
}

