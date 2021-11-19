#include"functions.h"
#include<unordered_map>

//给定一个正整数 n ，你可以做如下操作：
//
//如果 n 是偶数，则用 n / 2替换 n 。
//如果 n 是奇数，则可以用 n + 1或n - 1替换 n 。
//n 变为 1 所需的最小替换次数是多少？


unordered_map<int, int> memo;
int integerReplacement(int n) {
    //枚举所有的情况
    // if (n == 1) {
    //     return 0;
    // }
    // if (n % 2 == 0) {
    //     return 1 + integerReplacement(n / 2);
    // }
    // return 2 + min(integerReplacement(n / 2), integerReplacement(n / 2 + 1));

    //记忆化搜索
    if (n == 1) {
        return 0;
    }
    if (memo.count(n)) {
        return memo[n];
    }
    if (n % 2 == 0) {
        return memo[n] = 1 + integerReplacement(n / 2);
    }
    return memo[n] = 2 + min(integerReplacement(n / 2), integerReplacement(n / 2 + 1));
    //贪心
    // int ans = 0;
    // while (n != 1) {
    //     if (n % 2 == 0) {
    //         ++ans;
    //         n /= 2;
    //     }
    //     else if (n % 4 == 1) {
    //         ans += 2;
    //         n /= 2;
    //     }
    //     else {
    //         if (n == 3) {
    //             ans += 2;
    //             n = 1;
    //         }
    //         else {
    //             ans += 2;
    //             n = n / 2 + 1;
    //         }
    //     }
    // }
    // return ans;
}