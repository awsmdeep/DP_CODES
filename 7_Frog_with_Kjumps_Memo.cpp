#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int frog(int n, vector<int> &heights, int k,vector<int>&dp) {
    if (n == 0) return 0; // Base case: frog starts at the first stone.

    if(dp[n]!=-1) return dp[n];
    
    int minJump = INT_MAX;

    for (int i = 1; i <= k; i++) { // Loop from 1 to k (not 0 to k).
        if (n - i >= 0) { // Check if the previous stone exists.
            int jump = frog(n - i, heights, k,dp) + abs(heights[n] - heights[n - i]);
            minJump = min(minJump, jump);
        }
    }

    return dp[n]=minJump;
}

int main() {
    int n;
    cout << "Enter the value of N: ";
    cin >> n;

    vector<int> heights(n);
    cout << "Enter the heights of the stones: ";
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    int k;
    cout << "Enter the value of K: ";
    cin >> k;
    vector<int>dp(n,-1);

    cout << "Output: " << frog(n - 1, heights, k,dp) << endl; // Call the function for the last stone.
    return 0;
}
