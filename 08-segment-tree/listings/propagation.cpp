void propagate(int p, int L, int R) {
    if(lazy[p] != 0) {
        st[p] += (R-L+1)*lazy[p];

        if(L != R) {
            lazy[2*p] += lazy[p];
            lazy[2*p+1] += lazy[p];
        }

        lazy[p] = 0;
    }
}


