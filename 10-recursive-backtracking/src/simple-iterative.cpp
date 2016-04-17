// count the number of pairs (a, b) (natural numbers)
// such that a + b == c
unsigned countSumPairs(unsigned c) {
    unsigned num = 0;
    for (unsigned a = 0; a <= c; a++) {
        for (unsigned b = 0; b <= c; b++) {
            if (a + b == c)
                ++num;
        }
    }
    return num;
}
