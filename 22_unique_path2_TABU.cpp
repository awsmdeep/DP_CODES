#include <iostream>
#include <vector>
using namespace std;

int uniquePaths(int row, int col, vector<vector<int>>& matrix) {
    vector<vector<int>> dp(row, vector<int>(col, 0));

    // Fill the dp table
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (matrix[i][j] == -1) {
                dp[i][j] = 0; // Obstacle: no paths through this cell
            } else if (i == 0 && j == 0) {
                dp[i][j] = 1; // Starting point
            } else {
                int up = (i > 0) ? dp[i - 1][j] : 0;   // Paths from above
                int left = (j > 0) ? dp[i][j - 1] : 0; // Paths from left
                dp[i][j] = up + left;
            }
        }
    }

    // The bottom-right corner contains the result
    return dp[row - 1][col - 1];
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

    cout << "Output unique paths to reach start to end: " << uniquePaths(row, col, matrix) << endl;
    return 0;
}
