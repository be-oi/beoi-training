int query(int p, int L, int R, int i, int j) {
    propagate(p, L, R);

    if(i > R || j < L) return 0;
    if(L >= i && R <= j) return st[p];

    return query(2*p, L, (L+R)/2, i, j) 
         + query(2*p+1, (L+R)/2+1, i, j);
}

