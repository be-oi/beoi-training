// i is the node that is to be updated
void update(int p, int L, int R, int i) {
    // if leaf node
    if(L == R) return;
    // if i is in segment
    if(i >= L && i <= R) {
        // if new value is smaller, update
        if(A[i] <= A[st[p]])
            st[p] = i;
        update(2*p, L, (L+R)/2, i);
        update(2*p+1, (L+R)/2+1, R, i);
    }
}

