// p is array index of current node, 
// [L..R] is current segment, 
// [i..j] is search interval 
int query(int p, int L, int R, int i, int j) {
    // inside  query range
    if(L >= i && R <= j) return st[p];
    // outside query range
    if(i >  R || j <  L) return -1;

    // compute the min position in the left 
    // and right part of the interval
    int p1 = query(2*p, L, (L+R)/2, i, j);
    int p2 = query(2*p+1, (L+R)/2+1, R, i, j);

    // if we try to access segment outside query
    if(p1 == -1) return p2;
    if(p2 == -1) return p1;
    return (A[p1] <= A[p2]) ? p1 : p2;
}

