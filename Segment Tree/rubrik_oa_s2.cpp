#include <bits/stdc++.h>
#include <iostream>
using namespace std;

const int MAXN = 1e5;
int n;
long long t[4 * MAXN]; // Change to long long to avoid overflow

// Function to build the segment tree
void buildTree(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = tl + (tr - tl) / 2;
        buildTree(a, v * 2, tl, tm);//left half
        buildTree(a, v * 2 + 1, tm + 1, tr);//right half
        t[v] = t[v * 2] + t[v * 2 + 1]; // No need to cast since t[] is already long long
    }
}

// Function to print the segment tree
void printSegmentTree(int v, int tl, int tr) {
    if (tl == tr) {
        cout << "Leaf node [" << tl << "]: " << t[v] << "\n";
    } else {
        cout << "Node [" << tl << ", " << tr << "]: " << t[v] << "\n";
        int tm = tl + (tr - tl) / 2;
        printSegmentTree(v * 2, tl, tm);
        printSegmentTree(v * 2 + 1, tm + 1, tr);
    }
}

long long sum(int v, int tl, int tr, int l, int r) {
    if (l > r) {
        return 0;
    }
    if (l == tl && r == tr) {
        return t[v];
    }

    int tm = tl + (tr - tl) / 2;
    return sum(v * 2, tl, tm, l, min(r, tm)) + sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

//pos , tl,tl : 0 to n-1
void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] ^= new_val; // Bitwise XOR as required
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v * 2, tl, tm, pos, new_val);
        else
            update(v * 2 + 1, tm + 1, tr, pos, new_val);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

int main() {
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    buildTree(a, 1, 0, n - 1);

    int q;
    cin >> q;

    while (q--) {
        int ops;
        cin >> ops;

        if (ops == 1) {
            int l, r;
            cin >> l >> r;
            cout << sum(1, 0, n - 1, l - 1, r - 1) << "\n";
        } else if (ops == 2) {
            int l, r;
            cin >> l >> r;

            int z;
            cin >> z;

            for (int i = l - 1; i <= r - 1; i++) {
                update(1, 0, n - 1, i, z);
            }
        }
    }

    return 0;
}
