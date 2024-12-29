#include<iostream>
#include<vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    // Create a dp array to store Fibonacci numbers
    vector<int> dp(n + 1);

    // Base cases
    dp[0] = 0;
    dp[1] = 1;

    // Fill the dp array iteratively
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    // Output the nth Fibonacci number
    cout << dp[n] << endl;

    return 0;
}
