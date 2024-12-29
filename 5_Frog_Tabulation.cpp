#include <iostream>
#include <vector>
#include <cmath>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> h(n); // Heights of stones
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    vector<int> dp(n); // DP array to store the minimum cost
    dp[0] = 0;         // Base case: cost to reach the first stone is 0

    for (int i = 1; i < n; i++) {
        int fs = dp[i - 1] + abs(h[i] - h[i - 1]); // Jump from i-1 to i
        int ss = INT_MAX; // Initialize second step cost
        if (i > 1) {
            ss = dp[i - 2] + abs(h[i] - h[i - 2]); // Jump from i-2 to i
        }
        dp[i] = min(fs, ss); // Minimum cost to reach the i-th stone
    }

    cout << dp[n - 1] << endl; // Output the minimum cost to reach the last stone
    return 0;
}
