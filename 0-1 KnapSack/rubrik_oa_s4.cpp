#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int MAXN = 1005;   // Assuming sum can go from -1000 to +1000
const int OFFSET = 1000; // Offset to handle negative sums

int dp[1005][2005]; // [index][sum + OFFSET] to handle negative sums
                    // The sum ranges from -1000 to +1000

int f(int i, int sum, vector<int>& a) {
    if (i == a.size() || sum < -OFFSET || sum > OFFSET) return 0;

    if (dp[i][sum + OFFSET] != -1) return dp[i][sum + OFFSET];

    int pick = INT_MIN;
    if (sum + a[i] >= 0) pick = 1 + f(i + 1, sum + a[i], a);
    int notPick = f(i + 1, sum, a);

    return dp[i][sum + OFFSET] = max(pick, notPick);
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto& it : a) cin >> it;

    // Initialize dp array with -1 (unvisited states)
    memset(dp, -1, sizeof(dp));

    cout << f(0, 0, a);

    return 0;
}
