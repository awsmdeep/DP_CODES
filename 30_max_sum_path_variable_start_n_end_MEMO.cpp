#include <bits/stdc++.h>
using namespace std;

int pathsum(int i, int j, int col, vector<vector<int>> &matrix, vector<vector<int>> &dp) {
    if (j < 0 || j >= col) return -99999; // Out of bounds
    if (i == 0) return matrix[i][j];     // Base case: first row
    if (dp[i][j] != -1) return dp[i][j]; // Memoized result

    // Recursively compute the maximum path sum
    int st = matrix[i][j] + pathsum(i - 1, j, col, matrix, dp);       // From top
    int leftd = matrix[i][j] + pathsum(i - 1, j - 1, col, matrix, dp); // From top-left diagonal
    int rightd = matrix[i][j] + pathsum(i - 1, j + 1, col, matrix, dp); // From top-right diagonal

    return dp[i][j] = max(st, max(leftd, rightd));
}

int getMaxPathSum(vector<vector<int>> &matrix) {
    int row = matrix.size();
    int col = matrix[0].size();
    vector<vector<int>> dp(row, vector<int>(col, -1)); // Initialize DP table with -1
    int maxsum = INT_MIN;

    // Iterate through all ending points in the last row
    for (int i = 0; i < col; i++) {
        maxsum = max(maxsum, pathsum(row - 1, i, col, matrix, dp));
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
