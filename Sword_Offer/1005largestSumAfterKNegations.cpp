#include"functions.h"

//给你一个整数数组 nums 和一个整数 k ，按以下方法修改该数组：
//
//选择某个下标 i 并将 nums[i] 替换为 - nums[i] 。
//重复这个过程恰好 k 次。可以多次选择同一个下标 i 。
//
//以这种方式修改数组后，返回数组 可能的最大和 。



int largestSumAfterKNegations(vector<int>& nums, int k) {

    // unordered_map<int, int> freq;
    // for (int num: nums) {
    //     freq[num] += 1;
    // }
    // int ans = accumulate(nums.begin(), nums.end(), 0);
    // for (int i = -100; i < 0; ++i) {
    //     if (freq[i]) {
    //         int ops = min(k, freq[i]);
    //         ans += (-i) * ops * 2;
    //         freq[i] -= ops;
    //         freq[-i] += ops;
    //         k -= ops;
    //         if (k == 0) {
    //             break;
    //         }
    //     }
    // }
    // if (k > 0 && k % 2 == 1 && !freq[0]) {
    //     for (int i = 1; i <= 100; ++i) {
    //         if (freq[i]) {
    //             ans -= i * 2;
    //             break;
    //         }
    //     }
    // }
    // return ans;


    // sort(nums.begin(), nums.end());
    // for (int i = 0; i < nums.size() && k; k--, i++) {
    //     if (nums[i] > 0) break;
    //     nums[i] *= -1;
    // }
    // sort(nums.begin(), nums.end());
    // while(k--) {
    //     nums[0]*= -1;
    // }
    // return accumulate(nums.begin(), nums.end(), 0);

    int n = nums.size();
    sort(nums.begin(), nums.end());
    int m = 0;
    for (int i = 0; i < n; ++i) {
        if (nums[i] < 0) {
            m++;
        }
    }


    if (k <= m) {
        for (int j = 0; j < k; j++) {
            nums[j] *= -1;
        }
    }
    else if (m < k) {
        for (int j = 0; j < m; j++) {
            nums[j] *= -1;
        }
        sort(nums.begin(), nums.end());
        if ((k - m) % 2) {
            nums[0] *= -1;
        }
    }
    return accumulate(nums.begin(), nums.end(), 0);
}