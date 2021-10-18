#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//03.数组中重复的数字
//找出数组中重复的数字。
//
//在一个长度为 n 的数组 nums 里的所有数字都在 0～n - 1 的范围内。
//数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。


int findRepeatNumber(vector<int>& nums) {
    const int n = nums.size();
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {
        if (nums[i] < 0 || nums[i] >= n)
            return -1;
        if (i < n - 1)
        {
            if (nums[i] == nums[i + 1])
            {
                return nums[i];
            }
        }
    }
    return -1;
}
