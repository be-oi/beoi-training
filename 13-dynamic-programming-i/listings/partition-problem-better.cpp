int canDo[n][S][S];
// undefined: -1
// we cannot divide evenly from that state: 0
// we can    divide evenly from that state: 1
int S; // sum of the v[i]

bool solve(int i, int given1, int given2) {
    if(i == n) { // all goodies have been considered
        int given3 = S - given1 - given2;
        return given1 == given2 && given2 == given3;
    }
    if(canDo[i][given1][given2] != -1) {
        // the state (i, given1, given2) has already been visited
        return canDo[i][given1][given2];
    } else {
        bool giveTo1 = solve(i+1, given1 + v[i], given2);
        bool giveTo2 = solve(i+1, given1, given2 + v[i]);
        bool giveTo3 = solve(i+1, given1, given2);
        // save the value for later
        canDo[i][given1][given2] = giveTo1 || giveTo2 || giveTo3;
        return canDo[i][given1][given2];
    }
}


