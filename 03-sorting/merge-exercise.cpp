#include <bits/stdc++.h>
using namespace std;

vector<int> mergesort(vector<int> v) {
    // condition si tableau de taille 1
    // diviser en deux
    vector<int> gauche(??), droite(??);
    // remplir gauche et droite
    gauche = mergesort(gauche);
    droite = mergesort(droite);
    // fusionner gauche et droite dans v
    return v;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    a = mergesort(a);
    for (int i=0; i<n; i++) {
        cout << a[i] << "\n";
    }
}
