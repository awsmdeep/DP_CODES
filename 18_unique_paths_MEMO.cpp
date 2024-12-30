#include <iostream>
#include <vector>

using namespace std;

// Function to calculate unique paths using recursion with memoization
int path(int row, int col, vector<vector<int>> &dp) {
    // Base cases
    if (row == 0 && col == 0) return 1; // Reached the starting point
    if (row < 0 || col < 0) return 0;   // Out of bounds

    // If already calculated, return the stored result
    if (dp[row][col] != -1) return dp[row][col];

    // Recursive calculation: paths from top and left
    int up = path(row - 1, col, dp);
    int left = path(row, col - 1, dp);

    // Store the result in dp table
    return dp[row][col] = up + left;
}

int main() {
    int row, col;
    cout << "Enter the number of rows and columns: ";
    cin >> row >> col;

    // Initialize dp table with -1
    vector<vector<int>> dp(row, vector<int>(col, -1));

    // Calculate and display the result
    cout << "Output: Unique paths to reach from start to end: " 
         << path(row - 1, col - 1, dp) << endl;

    return 0;
}
