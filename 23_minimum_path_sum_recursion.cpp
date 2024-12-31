#include<iostream>
#include<vector>
#include<cmath>
#include<climits>

using namespace std;

int pathSum(int row,int col,vector<vector<int>>&matrix){
    if(row==0 && col==0) return matrix[row][col];
    if(row<0 || col<0) return 999999;

    int up=matrix[row][col]+pathSum(row-1,col,matrix);
    int left=matrix[row][col]+pathSum(row,col-1,matrix);

    return  min(up,left);
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
    cout<<"minimum path sum: "<<pathSum(row-1,col-1,matrix)<<endl;
}