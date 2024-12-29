#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> heights(n);

    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    int k;
    cin >> k;

    vector<int> dp(n, INT_MAX); // Initialize dp array with INT_MAX.
    dp[0] = 0; // Base case: Minimum energy at the first stone is 0.

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) { // Ensure the previous stone exists.
                dp[i] = min(dp[i], dp[i - j] + abs(heights[i] - heights[i - j]));
            }
        }
    }

    cout << dp[n - 1] << endl; // Minimum energy to reach the last stone.
    return 0;
}
