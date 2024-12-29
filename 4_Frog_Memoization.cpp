#include <iostream>
#include <vector>
#include <cmath>

#include<bits/stdc++.h>
using namespace std;

int frog(int n, vector<int> &heights, vector<int> &dp) {
    if (n == 0) return 0; // Base case: no cost to reach the first step

    if (dp[n] != -1) return dp[n]; // Return precomputed value if available

    // Calculate the minimum energy
    int left = frog(n - 1, heights, dp) + abs(heights[n] - heights[n - 1]);
    int right = INT_MAX; // Initialize right to a large value
    if (n > 1) {
        right = frog(n - 2, heights, dp) + abs(heights[n] - heights[n - 2]);
    }
    return dp[n] = min(left, right); // Store the result in dp array
}

int main() {
    int n;
    cin >> n; // Number of stones

    vector<int> heights(n); // Initialize heights array with size n
    for (int i = 0; i < n; i++) {
        cin >> heights[i]; // Input heights of stones
    }

    vector<int> dp(n, -1); // DP array initialized to -1

    cout << "output: " << frog(n - 1, heights, dp) << endl; // Call the function
    return 0;
}
