void adjust(int k, int v) {
    for(; k <= n; k += LSOne(k))
        ft[k] += v;
}

