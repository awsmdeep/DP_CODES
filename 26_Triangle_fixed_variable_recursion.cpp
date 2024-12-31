#include <bits/stdc++.h>
using namespace std;

// Recursive function to calculate the path sum
int pathsum(int startRow, int startCol, vector<vector<int>>& triangle, int n) {
    // Base case: if we are at the last row, return the element value
    if (startRow == n) return triangle[startRow][startCol];

    // Recursive calls for the downward and diagonal paths
    int down = triangle[startRow][startCol] + pathsum(startRow + 1, startCol, triangle, n);
    int diag = triangle[startRow][startCol] + pathsum(startRow + 1, startCol + 1, triangle, n);

    // Return the minimum of the two paths
    return min(down, diag);
}

// Function to calculate the minimum path sum
int minimumPathSum(vector<vector<int>>& triangle, int n) {
    int row = 0;
    int col = 0;
    return pathsum(row, col, triangle, n - 1);
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
