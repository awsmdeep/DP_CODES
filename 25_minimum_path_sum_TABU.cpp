#include<iostream>
#include<vector>
#include<cmath>
#include<climits>

using namespace std;

int pathSum(int row,int col,vector<vector<int>>&matrix,vector<vector<int>>&dp){

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(i==0 && j==0) {
                dp[i][j]=matrix[i][j];
            }else if(i<0|| j<0) {
                dp[i][j]=99999;
            }else{
                int up=matrix[i][j]+dp[i-1][j];
                int left=matrix[i][j]+dp[i][j-1];
                dp[i][j]=min(up,left);
            }
        }
    }
    return dp[row-1][col-1];
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
    cout<<"minimum path sum: "<<pathSum(row,col,matrix,dp)<<endl;
}