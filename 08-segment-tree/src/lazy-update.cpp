// i, j: update range
// dx: by how much to increment
void update(int p, int L, int R, int i, int j, int dx) {
    // inside  update range
    if (i <= L && R <= j) {
        lazy[p] += dx;
        propagate(p, L, R); // to update st[p]
        return;
    }
    // outside update range
    if (i >= R || L >= j) return;

    propagate(p, L, R);
    update(2*p+1, L, (L+R)/2, i, j, dx);
    update(2*p+2, (L+R)/2, R, i, j, dx);

    st[p] = st[2*p+1] + st[2*p+2];
}
