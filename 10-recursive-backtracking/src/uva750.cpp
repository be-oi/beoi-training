#include <bits/stdc++.h>
using namespace std;

pair<int, int> constraint;
int row[8];
int soln = 1;

void print_solution() {
    cout << (soln < 10 ? " " : "") << soln << "      ";
    soln++;
    for (int i = 0; i < 8; i++) {
        cout << row[i] + 1 << (i != 7 ? " " : "");
    }
    cout << endl;
}

bool valid(int r, int column){
    for (int p = 0; p < column; p++) {
        if (row[p] == r || abs(row[p] - r) == abs(p - column))
            return false;
    }
    return true;
}

void generate(int column=0) {
    if (column >= 8) {
        if (row[constraint.second] == constraint.first)
            print_solution();
    }
    for (int r = 0; r < 8; r++) {
        if (valid(r, column))
        {
            row[column] = r;
            generate(column + 1);
            row[column] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--)
    {
        soln = 1;
        cin >> constraint.first >> constraint.second;
        constraint.first--;
        constraint.second--;
        cout << "SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n" << std::endl;
        generate();
        if (T)
            cout << endl;
    }
}
