#include"functions.h"


//给你一个整数数组 nums ，设计算法来打乱一个没有重复元素的数组。
//
//实现 Solution class :
//
//    Solution(int[] nums) 使用整数数组 nums 初始化对象
//    int[] reset() 重设数组到它的初始状态并返回
//    int[] shuffle() 返回数组随机打乱后的结果

class Solution {
public:
    Solution(vector<int>& nums) :origin(nums), m(nums) {

    }

    vector<int> reset() {
        return origin;
    }

    vector<int> shuffle() {
        int n = m.size();
        for (int i = 0; i < n; ++i)
        {
            auto r = i + rand() % (n - i);	// r : [ i, n - 1 ]
            swap(m[i], m[r]);
        }
        return m;
    }
private:
    vector<int> m;
    vector<int> origin;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */