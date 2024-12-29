#include<iostream>
#include<cmath>
#include<vector>
#include<climits>

using namespace std;


int Robbery(int ind,vector<int>&arr,vector<int>&dp){

   int prev=arr[0];
   int prev2=0;
   for(int i=0;i<ind;i++){

    int pick=arr[i];
    if(i>1) pick+=prev2;
    int notpick=0+prev;
    int curr=max(pick,notpick);
    prev2=prev;
    prev=curr;
   }
   return prev;
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