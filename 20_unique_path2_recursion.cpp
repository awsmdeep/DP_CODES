#include<iostream>
#include<cmath>
#include<climits>
#include<vector>

using namespace std;


int path(int row,int col,vector<vector<int>>&matrix){
    if(row>=0 && col>=0 && matrix[row][col]==-1) return 0;
    if(row==0 && col==0) return 1;
    if(row<0 || col<0) return 0;

    int up=path(row-1,col,matrix);
    int left=path(row,col-1,matrix);
    return up+left;
}


int main(){

    int row,col;
    cout<<"Enter number of rows and cols";
    cin>>row>>col;

    vector<vector<int>>matrix(row,vector<int>(col));

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>matrix[i][j];
        }
    }
    cout<<"Output  unique paths to reach start to end : "<<path(row-1,col-1,matrix);
}