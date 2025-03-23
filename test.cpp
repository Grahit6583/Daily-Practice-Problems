#include <iostream>
#include <vector>
using namespace std;

// Function to compute steps to reduce a number to zero
int computeSteps(int x) {
    int steps = 0;
    while (x > 0) {
        x /= 4;  // Floor division by 4
        steps++;
    }
    return steps;
}

long long minOperations(vector<vector<int>>& queries) {
    long long totalSum = 0;

    // Process each query
    for (auto& query : queries) {
        int l = query[0], r = query[1];
        long long sum = 0;

        // Compute steps only for the required range
        for (int i = l; i <= r; i++) {
            sum += computeSteps(i);
        }

        totalSum += sum;
    }

    return totalSum;
}

int main() {
    vector<vector<int>> queries = {{1, 2}, {2, 4}};
    cout << minOperations(queries) << endl; // Output: 3
    return 0;
}
