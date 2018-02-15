#include <bits/stdc++.h>
using namespace std;

vector<int> quicksort(vector<int> v) {
    int n = v.size();
    if (n <= 1) {
        return v;
    }
    int posPivot = rand() % n; // entier dans {0,...,n-1}
    swap(v[posPivot], v[0]);
    vector<int> v2(n);
    int valPivot = v[0];
    int i = 0, j = n-1;
    for (int k = 1; k < n; k++) {
        // placer v[k] dans v2
        if (v[k] > valPivot) {
            v2[j] = v[k];
            j--;
        } else {
            v2[i] = v[k];
            i++;
        }
    }
    v2[i] = valPivot;
    vector<int> gauche(i), droite(n-i-1);
    for (int k = 0; k < n; k++) {
        if (k < i) gauche[k] = v2[k];
        if (k > i) droite[k-i-1] = v2[k];
    }
    gauche = quicksort(gauche);
    droite = quicksort(droite);
    for (int k = 0; k < n; k++) {
        if (k < i) v2[k] = gauche[k];
        if (k > i) v2[k] = droite[k-i-1];
    }
    return v2;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    a = quicksort(a);
    for (int i=0; i<n; i++) {
        cout << a[i] << "\n";
    }
}
