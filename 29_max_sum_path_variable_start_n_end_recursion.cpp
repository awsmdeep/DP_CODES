#include <bits/stdc++.h>
using namespace std;

int pathsum(int i, int j, int col, vector<vector<int>> &matrix) {
    if (j < 0 || j >= col) return -1e9; // Out of bounds penalty
    if (i == 0) return matrix[i][j];   // Base case: return the value in the first row

    // Calculate the maximum path sum considering all possible movements
    int st = matrix[i][j] + pathsum(i - 1, j, col, matrix);
    int leftd = matrix[i][j] + pathsum(i - 1, j - 1, col, matrix);
    int rightd = matrix[i][j] + pathsum(i - 1, j + 1, col, matrix);

    return max(st, max(leftd, rightd));
}

int getMaxPathSum(vector<vector<int>> &matrix) {
    int row = matrix.size();
    int col = matrix[0].size();
    int maxSum = -1e9;

    // Check for all possible ending points in the last row
    for (int j = 0; j < col; j++) {
        maxSum = max(maxSum, pathsum(row - 1, j, col, matrix));
    }

    return maxSum;
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
