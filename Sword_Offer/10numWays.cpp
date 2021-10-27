#include"functions.h"

//一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。
//答案需要取模 1e9 + 7（1000000007），如计算初始结果为：1000000008，请返回 1。



int numWays(int n) {

    //动态规划，时间复杂度O(n)，空间复杂度O(n);
    if (n == 0 || n == 1) {
        return 1;
    }
    vector<int> dp(n+1);
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 2] + dp[i - 1]) % 1000000007;
    }
    return dp[n];

    //O(N),O(1)空间复杂度的动态规划
    int a = 1, b = 1, sum;
    for (int i = 0; i < n; i++) {
        sum = (a + b) % 1000000007;
        a = b;
        b = sum;
    }
    return a;
}