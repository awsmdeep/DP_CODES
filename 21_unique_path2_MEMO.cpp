#include <iostream>
#include <vector>
using namespace std;

// Helper function for memoized recursion
int path(int row, int col, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
    // Base cases
    if (row >= 0 && col >= 0 && matrix[row][col] == -1) return 0; // Obstacle
    if (row == 0 && col == 0) return 1; // Reached starting cell
    if (row < 0 || col < 0) return 0;   // Out of bounds

    // Check if the result is already computed
    if (dp[row][col] != -1) return dp[row][col];

    // Recursively compute paths from the top and left cells
    int up = path(row - 1, col, matrix, dp);
    int left = path(row, col - 1, matrix, dp);

    // Store the result in the dp table
    return dp[row][col] = up + left;
}

int main() {
    int row, col;
    cout << "Enter number of rows and cols: ";
    cin >> row >> col;

    vector<vector<int>> matrix(row, vector<int>(col));
    cout << "Enter the grid (use -1 for obstacles, 0 for free space):" << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> matrix[i][j];
        }
    }

    // Initialize dp table with -1 (indicating uncomputed states)
    vector<vector<int>> dp(row, vector<int>(col, -1));

    // Compute the result
    cout << "Output unique paths to reach start to end: " << path(row - 1, col - 1, matrix, dp) << endl;
    return 0;
}
