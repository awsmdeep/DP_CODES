#include <bits/stdc++.h>
using namespace std;

int getMaxPathSum(vector<vector<int>> &matrix) {
    int row = matrix.size();
    int col = matrix[0].size();

    // Create a DP table initialized to 0
    vector<vector<int>> dp(row, vector<int>(col, 0));

    // Base case: first row is the same as the matrix
    for (int j = 0; j < col; j++) {
        dp[0][j] = matrix[0][j];
    }

    // Fill the DP table row by row
    for (int i = 1; i < row; i++) {
        for (int j = 0; j < col; j++) {
            int st = dp[i - 1][j];       // Coming from the top
            int leftd = (j > 0) ? dp[i - 1][j - 1] : -1e9; // Coming from the top-left diagonal
            int rightd = (j < col - 1) ? dp[i - 1][j + 1] : -1e9; // Coming from the top-right diagonal

            dp[i][j] = matrix[i][j] + max(st, max(leftd, rightd));
        }
    }

    // Find the maximum value in the last row
    int maxsum = INT_MIN;
    for (int j = 0; j < col; j++) {
        maxsum = max(maxsum, dp[row - 1][j]);
    }

    return maxsum;
}

int main() {
    vector<vector<int>> matrix = {
        {10, 10, 2, 0, 20, 4},
        {1, 0, 0, 30, 2, 5},
        {0, 10, 4, 0, 2, 0},
        {1, 0, 2, 20, 0, 4}
    };

    cout << "Maximum Path Sum: " << getMaxPathSum(matrix) << endl;
    return 0;
}
