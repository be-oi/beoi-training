void build(int p, int L, int R) {
    if(L == R)
        // leaf node
        st[p] = L;
    else {
        // build children
        build(2*p, L, (L+R)/2);
        build(2*p+1, (L+R)/2+1, R);
        // take minimum among them
        int p1 = st[2*p], p2 = st[2*p+1];
        st[p] = (A[p1] <= A[p2]) ? p1 : p2;
    }
}

