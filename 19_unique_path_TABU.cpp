#include<iostream>
#include<cmath>
#include<climits>
#include<vector>

using namespace std;


int path(int row, int col, vector<vector<int>> &dp) {
    // Initialize the first cell
    dp[0][0] = 1;

    // Fill the dp table
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (i == 0 && j == 0) continue; // Skip the starting point
            int up = (i > 0) ? dp[i - 1][j] : 0;
            int left = (j > 0) ? dp[i][j - 1] : 0;
            dp[i][j] = up + left;
        }
    }

    // Return the result from the bottom-right corner
    return dp[row - 1][col - 1];
}


int main(){

    int row,col;
    cout<<"Enter number of rows and cols";
    cin>>row>>col;

    vector<vector<int>>matrix(row,vector<int>(col));
    vector<vector<int>>dp(row,vector<int>(col));

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>matrix[i][j];
        }
    }
    cout<<"Output  unique paths to reach start to end : "<<path(row,col,dp);
}