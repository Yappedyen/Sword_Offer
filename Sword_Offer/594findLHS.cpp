#include"functions.h"
#include<unordered_map>
#include<map>
#include<math.h>
using namespace std;
//和谐数组是指一个数组里元素的最大值和最小值之间的差别 正好是 1 。
//
//现在，给你一个整数数组 nums ，请你在所有可能的子序列中找到最长的和谐子序列的长度。
//
//数组的子序列是一个由数组派生出来的序列，它可以通过删除一些元素或不删除元素、且不改变其余元素的顺序而得到。


int findLHS(vector<int>& nums) {

   /* 我们可以枚举数组中的每一个元素，对于当前枚举的元素 x，它可以和x + 1组成和谐子序列。我们只需要在数组中找出等于x 或x + 1 的元素个数，就可以得到以 x为最小值的和谐子序列的长度。

        实际处理时，我们可以将数组按照从小到大进行排序，我们只需要依次找到相邻两个连续相同元素的子序列，检查该这两个子序列的元素的之差是否为 1。
        利用类似与滑动窗口的做法，begin 指向第一个连续相同元素的子序列的第一个元素，end 指向相邻的第二个连续相同元素的子序列的末尾元素，如果满足二者的元素之差为 1，则当前的和谐子序列的长度即为两个子序列的长度之和，等于end−begin + 1.
   */

    // sort(nums.begin(),nums.end());
    // int begin = 0;
    // int res = 0;
    // for (int end = 0; end < nums.size(); end++) {
    //     while (nums[end] - nums[begin] > 1) {
    //         begin++;
    //     }
    //     if (nums[end] - nums[begin] == 1) {
    //         res = max(res, end - begin + 1);
    //     }
    // }
    // return res;


    //哈希表
    unordered_map<int, int> cnt;
    int res = 0;
    for (int num : nums) {
        cnt[num]++;
    }
    for (auto [key, val] : cnt) {
        if (cnt.count(key + 1)) {
            res = max(res, val + cnt[key + 1]);
        }
    }
    return res;
}