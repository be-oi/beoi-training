bool complete_search(int i, int given1, int given2, int given3) {
    if(i == n) // all goodies have been considered
        return given1 == given2 && given2 == given3;
    else {
        bool giveTo1 = complete_search(i+1, given1 + v[i], given2, given3);
        bool giveTo2 = complete_search(i+1, given1, given2 + v[i], given3);
        bool giveTo3 = complete_search(i+1, given1, given2, given3 + v[i]);
        return giveTo1 || giveTo2 || giveTo3;
    }
}


