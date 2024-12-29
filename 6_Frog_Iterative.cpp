#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> h(n); // Heights of stones
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    int prev2 = 0; // Cost to reach the stone two steps back
    int prev1 = 0; // Cost to reach the previous stone

    for (int i = 1; i < n; i++) {
        int fs = prev1 + abs(h[i] - h[i - 1]); // Jump from i-1 to i
        int ss = INT_MAX;
        if (i > 1) {
            ss = prev2 + abs(h[i] - h[i - 2]); // Jump from i-2 to i
        }
        int curr = min(fs, ss); // Minimum cost to reach the i-th stone
        prev2 = prev1; // Update prev2 to prev1
        prev1 = curr;  // Update prev1 to curr
    }

    cout << prev1 << endl; // Minimum cost to reach the last stone
    return 0;
}
