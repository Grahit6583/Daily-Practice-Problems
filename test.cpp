#include <bits/stdc++.h>
using namespace std;

int minPartitionCost(vector<int>& cost, int n, int k) {
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, INT_MAX));
    
    // Prefix sum to help with fast range calculations
    vector<int> prefixSum(n + 1, 0);
    for (int i = 1; i <= n; i++) 
        prefixSum[i] = prefixSum[i - 1] + cost[i - 1];

    dp[0][0] = 0; // Base case: 0 cost when no servers and no partitions

    for (int partitions = 1; partitions <= k; partitions++) {
        for (int j = partitions; j <= n; j++) {
            for (int i = partitions - 1; i < j; i++) {
                int partitionCost = cost[i] + cost[j - 1];
                dp[partitions][j] = min(dp[partitions][j], dp[partitions - 1][i] + partitionCost);
            }
        }
    }

    return dp[k][n];
}

int maxPartitionCost(vector<int>& cost, int n, int k) {
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));

    for (int partitions = 1; partitions <= k; partitions++) {
        for (int j = partitions; j <= n; j++) {
            for (int i = partitions - 1; i < j; i++) {
                int partitionCost = cost[i] + cost[j - 1];
                dp[partitions][j] = max(dp[partitions][j], dp[partitions - 1][i] + partitionCost);
            }
        }
    }

    return dp[k][n];
}

vector<int> findPartitionCost(vector<int> cost, int k) {
    int n = cost.size();
    return {minPartitionCost(cost, n, k), maxPartitionCost(cost, n, k)};
}

int main() {
    int n, k;
    cin >> n;
    vector<int> cost(n);
    for (int i = 0; i < n; i++) 
        cin >> cost[i];
    cin >> k;
    
    vector<int> result = findPartitionCost(cost, k);
    cout << result[0] << endl << result[1] << endl;
    
    return 0;
}
