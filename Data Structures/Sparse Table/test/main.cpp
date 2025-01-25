#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5;
const int LOG = 17;
int a[MAX_N];
int m[MAX_N][LOG];
map<int, int> mp;


void printMap() {
    cout << "Contents of the map (value -> frequency):" << endl;
    for (const auto &pair : mp) {
        cout << "Value: " << pair.first << ", Frequency: " << pair.second << endl;
    }
}


void preprocess(int n)
{
    // preprocessing for min_query_O(N*logN)
    for (int k = 1; k < LOG; k++)
    {
        for (int i = 0; i + (1 << k) - 1 < n; i++)
        {
            m[i][k] = __gcd(m[i][k - 1], m[i + (1 << (k - 1))][k - 1]);
            mp[m[i][k]]++;

            // Debugging print statements
            cout << "k: " << k << ", i: " << i << ", m[i][k]: " << m[i][k] << ", mp[m[i][k]]: " << mp[m[i][k]] << endl;
        }
    }
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter the elements of the array: \n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        m[i][0] = a[i];
        mp[a[i]]++; // Add to map for k = 0

        // Debugging print statements
        cout << "i: " << i << ", a[i]: " << a[i] << ", m[i][0]: " << m[i][0] << ", mp[m[i][0]]: " << mp[m[i][0]] << endl;
    }

    preprocess(n);
    printMap();

    int q;
    cout << "Enter the number of queries: ";
    cin >> q;

    cout << "Enter the queries: \n";
    while (q--)
    {
        int x;
        cin >> x;

        // Debugging print statements
        cout << "Query: " << x << ", Frequency: " << mp[x] << endl;

        cout << (mp.count(x) ? mp[x] : 0) << endl;
    }

    return 0;
}
