#include <bits/stdc++.h>
using namespace std;

// Function to calculate the minimum path sum using tabulation
int minimumPathSum(vector<vector<int>>& triangle, int n) {
    vector<vector<int>> dp(n, vector<int>(n, 0)); // Initialize dp table

    // Base case: Fill the last row of dp with the values of the triangle
    for (int j = 0; j < n; j++) {
        dp[n - 1][j] = triangle[n - 1][j];
    }

    // Bottom-up calculation
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            dp[i][j] = triangle[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }

    // The result is stored at the top of the triangle
    return dp[0][0];
}

int main() {
    // Input number of rows
    int n;
    cout << "Enter the number of rows in the triangle: ";
    cin >> n;

    // Input the triangle
    vector<vector<int>> triangle(n);
    cout << "Enter the elements of the triangle:\n";
    for (int i = 0; i < n; i++) {
        triangle[i].resize(i + 1);
        for (int j = 0; j <= i; j++) {
            cin >> triangle[i][j];
        }
    }

    // Calculate the minimum path sum
    int result = minimumPathSum(triangle, n);

    // Output the result
    cout << "The minimum path sum is: " << result << endl;

    return 0;
}
