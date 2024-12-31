#include<iostream>
#include<vector>
#include<cmath>
#include<climits>

using namespace std;

int pathSum(int row,int col,vector<vector<int>>&matrix,vector<vector<int>>&dp){
    if(row==0 && col==0) return matrix[row][col];
    if(row<0 || col<0) return 999999;
    if(dp[row][col]!=-1) return dp[row][col];

    int up=matrix[row][col]+pathSum(row-1,col,matrix,dp);
    int left=matrix[row][col]+pathSum(row,col-1,matrix,dp);

    return dp[row][col]= min(up,left);
}

int main(){

    int row,col;
    cout<<"enter the number of rows and cols";
    cin>>row>>col;

    vector<vector<int>>matrix(row,vector<int>(col));

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>matrix[i][j];
        }
    }
    vector<vector<int>>dp(row,vector<int>(col,-1));
    cout<<"minimum path sum: "<<pathSum(row-1,col-1,matrix,dp)<<endl;
}