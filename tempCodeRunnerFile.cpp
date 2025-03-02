#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

const int NEG_INF = numeric_limits<int>::min() / 2; // To avoid overflow

int maxSumKSubarrays(const vector<int>& nums, int k, int m) {
    int n = nums.size();
    
    // Build prefix sum array: prefix[i] is the sum of the first i elements.
    vector<int> prefix(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + nums[i - 1];
    }
    
    // dp[i][j] = maximum sum using j subarrays from the first i elements.
    // Dimensions: (n+1) x (k+1). Use NEG_INF for impossible states.
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, NEG_INF));
    
    // Base case: with 0 subarrays, the sum is 0 (for any i).
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    
    // Iterate over the number of subarrays to choose.
    for (int j = 1; j <= k; j++) {
        // For i < j*m, it's impossible to have j subarrays.
        for (int i = 0; i < j * m && i <= n; i++) {
            dp[i][j] = NEG_INF;
        }
        
        // Precompute best[x] = max_{p=0}^{x} { dp[p][j-1] - prefix[p] }.
        vector<int> best(n + 1, NEG_INF);
        best[0] = dp[0][j - 1] - prefix[0]; // prefix[0] = 0.
        for (int i = 1; i <= n; i++) {
            best[i] = max(best[i - 1], dp[i][j - 1] - prefix[i]);
        }
        
        // Now compute dp[i][j] for i from j*m to n.
        for (int i = j * m; i <= n; i++) {
            // Option 1: Do not use the i-th element for a new subarray.
            dp[i][j] = (i > 0 ? dp[i - 1][j] : NEG_INF);
            // Option 2: End a subarray at i. It must have length at least m,
            // so the start p can be at most i - m.
            if (i - m >= 0) {
                dp[i][j] = max(dp[i][j], prefix[i] + best[i - m]);
            }
        }
    }
    
    return dp[n][k];
}

int main() {
    // Example:
    // nums = [1, 2, 3, -2, 5, -1, 4]
    // k = 2, m = 2
    // One optimal selection is:
    //   - Subarray [1, 2, 3] with sum 6 (indices 0 to 2)
    //   - Subarray [5, -1, 4] with sum 8 (indices 4 to 6)
    // Total maximum sum = 6 + 8 = 14.
    vector<int> nums = {-10,3,-1,-2};
    int k = 4;
    int m = 1;
    
    int result = maxSumKSubarrays(nums, k, m);
    cout << "Maximum sum of " << k << " non-overlapping subarrays (each of length at least " 
         << m << ") is: " << result << endl;
    
    return 0;
}
