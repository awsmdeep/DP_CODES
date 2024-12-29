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
    int prev=arr[0];
    int prev2=0;

    for(int j=1;j<n;j++){
        int pick=arr[j]; if(j>1) pick+=prev2;
        int notpick=0+prev;
        int curr=max(pick,notpick);
        prev2=prev;
        prev=curr;
    }
    cout<<"OUTPUT: "<<prev;
}