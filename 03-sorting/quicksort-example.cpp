#include <bits/stdc++.h>
using namespace std;

const int N = 10;

struct node {
    node *l, *r;
    int val, lazy; // minimum of range
    int i,j; // interval [i,j]
};

int a[N];

// build tree on [i,j]
node *build(int i, int j) {
    if (i == j) {
        return new node{NULL, NULL, a[i], i, j};
    } else {
        node *l = build(i, (i+j)/2);
        node *r = build((i+j)/2+1, j);
        return new node{l, r, min(l->val, r->val), i, j};
    }
}

const int INF = 1000000000;

void pushLazy(node *cur) {
    if (cur->lazy != INF) {
        if (cur->l == NULL) { // cur is a leaf
            cur->val = cur->lazy;
        } else {
            cur->l->lazy = cur->r->lazy = cur->lazy;
            cur->val = (cur->j - cur->i + 1) * cur->lazy;
        }
        cur->lazy = INF;
    }
}

// find minimum value on interval [i,j]
int query(node *cur, int i, int j) {
    pushLazy(cur);
    // sometimes we just ignore the node
    if (cur->j < i || cur->i > j) {
        return 0;
    }
    // sometimes we take the value
    else if (cur-> i >= i && cur->j <= j) {
        return cur->val;
    }
    // otherwise we split in two
    else {
        return query(cur->l, i, j) + query(cur->r, i, j);
    }
}

// we assume that i is in [cur->i, cur->j]
void update(node *cur, int i, int j, int newValue) {
    // if we're at the bottom
    if (cur->l == NULL) { // or "if (cur->i == cur->j)"
        cur->val = newValue;
    }
    else {
        if (cur->j < i || cur->i > j)
            return;
        else if (i <= cur->i && cur->j <= j) {
            cur->lazy = newValue;
        } else {
            pushLazy(cur);
            update(cur->l, i, j, newValue);
            update(cur->r, i, j, newValue);
        }
    }
}

int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> a[i];
    node *root = build(0,n-1);
    cout << query(root, 2, 5) << endl; // minimum on [2,5]
    update(root, 5, 7);
    cout << query(root, 2, 5) << endl; // minimum on [2,5]
}
