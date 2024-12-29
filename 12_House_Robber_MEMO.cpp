#include<iostream>
#include<cmath>
#include<vector>
#include<climits>

using namespace std;


int Robbery(int ind,vector<int>&arr,vector<int>&dp){

    if(ind==0) return arr[ind];
    if(ind<0) return -1;

    if(dp[ind]!=-1) return dp[ind];

    int pick=arr[ind]+Robbery(ind-2,arr,dp);
    int notpick=0+Robbery(ind-1,arr,dp);

    return dp[ind]=max(pick,notpick);
}


int main(){

    int n;
    cout<<"Enter number of houses: ";
    cin>>n;

    vector<int>houses(n);
    cout<<"Enter money in each house : ";
    for(int i=0;i<n;i++){
        cin>>houses[i];
    }
    vector<int>dp(n,-1);

    vector<int>temp1,temp2;
    for(int i=0;i<n;i++){
        if(i!=0) temp1.push_back(houses[i]);
        if(i!=n-1) temp2.push_back(houses[i]);
    }
    int ans1=Robbery(n-2,temp1,dp);
    int ans2=Robbery(n-2,temp2,dp);
    cout<<"OUTPUT: "<<max(ans1,ans2)<<endl;
}