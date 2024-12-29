#include<iostream>
#include<climits>
#include<vector>
#include<cmath>

using namespace std;

int main(){
    int n;
    cout<<"Enter the length of the array :";
    cin>>n;
    cout<<"Enter the elements of array : ";
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>dp(n);
    dp[0]=arr[0];

    for(int j=1;j<n;j++){
        int pick=arr[j]; if(j>1) pick+=dp[j-2];
        int notpick=0+dp[j-1];
        dp[j]=max(pick,notpick);
    }
    cout<<"OUTPUT: "<<dp[n-1];
}