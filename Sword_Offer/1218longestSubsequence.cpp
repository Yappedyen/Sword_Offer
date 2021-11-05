#include"functions.h"
#include<unordered_map>

int longestSubsequence(vector<int>& arr, int difference) {
    int ans = 0;
    unordered_map<int, int> dp;
    for (int v : arr) {
        dp[v] = dp[v - difference] + 1;
        ans = max(ans, dp[v]);
    }
    return ans;
}