int rsq(int i) {
    int sum = 0;
    for(; i > 0; i -= LSOne(i))
        sum += ft[i];
    return sum;
}
