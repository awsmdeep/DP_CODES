#include<iostream>
#include<cmath>
#include<vector>
#include<climits>


using namespace std;


int maxAdjacentSum(int ind,vector<int>&arr,vector<int>&dp){

    if(ind==0) return arr[ind];
    if(ind<0) return 0;

    if(dp[ind]!=-1) return dp[ind];

    int pick=arr[ind]+maxAdjacentSum(ind-2,arr,dp);
    int notPick=0+maxAdjacentSum(ind-1,arr,dp);
    return dp[ind]=max(pick,notPick);
}


int main(){

    int n;
    cout<<"Enter the length of array : ";
    cin>>n;
    cout<<"Enter the digits of array : ";
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>dp(n,-1);

    cout<<"OUTPUT: "<<maxAdjacentSum(n-1,arr,dp)<<endl;


}