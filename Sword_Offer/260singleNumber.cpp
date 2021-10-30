#include"functions.h"


//给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 
//找出只出现一次的那两个元素。你可以按 任意顺序 返回答案。



vector<int> singleNumber(vector<int>& nums) {
    //进阶：你的算法应该具有线性时间复杂度。你能否仅使用常数空间复杂度来实现？
    //O(n),O(1)
    int xorsum = 0;
    for (int num : nums) {
        xorsum ^= num;
    }
    // 防止溢出
    int lsb = (xorsum == INT_MIN ? xorsum : xorsum & (-xorsum));
    int type1 = 0, type2 = 0;
    for (int num : nums) {
        if (num & lsb) {
            type1 ^= num;
        }
        else {
            type2 ^= num;
        }
    }
    return { type1, type2 };

    //O(n),O(n)
    // vector<int> v;
    // unordered_map<int,int> m;
    // for(auto r:nums){
    //     m[r]++;
    // }

    // for(auto & num:m){
    //     if(num.second == 1){
    //         v.push_back(num.first);
    //     }
    // }
    // return v;

}