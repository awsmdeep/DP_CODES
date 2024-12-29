#include <iostream>
#include <climits>
#include <vector>
#include <cmath>

using namespace std;

int Ninja(int day, int last, vector<vector<int>>& matrix, int cols) {
    if (day == 0) {
        int maxi = INT_MIN;
        for (int i = 0; i < cols; i++) {
            if (i != last) {
                maxi = max(maxi, matrix[0][i]);
            }
        }
        return maxi;
    }

    int maxi = INT_MIN;
    for (int i = 0; i < cols; i++) {
        if (i != last) {
            int points = matrix[day][i] + Ninja(day - 1, i, matrix, cols);
            maxi = max(points, maxi);
        }
    }
    return maxi;
}

int main() {
    int rows, cols;
    cout << "Enter the number of rows and columns for the matrix: ";
    cin >> rows >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));
    cout << "Enter elements of the matrix: ";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    // Calling Ninja function with last = cols (as no column is taken initially)
    cout << "OUTPUT: " << Ninja(rows - 1, cols, matrix, cols) << endl;

    return 0;
}
