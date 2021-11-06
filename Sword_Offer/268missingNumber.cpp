#include"functions.h"


int missingNumber(vector<int>& nums) {

    //哈希集合O(n)
    // 首先遍历数组nums，将数组中的每个元素加入哈希集合，然后依次检查从 0 到 n 的每个整数是否在哈希集合中，
    // 不在哈希集合中的数字即为丢失的数字。由于哈希集合的每次添加元素和查找元素的时间复杂度都是O(1)，因此总时间复杂度是O(n)。
    //int n = nums.size();
    // unordered_set<int> m;
    // for(int i = 0;i<n;++i){
    //     m.insert(nums[i]);
    // }
    // int missing = -1;
    // for (int i = 0; i <= n; i++) {
    //     if (!m.count(i)) {
    //         missing = i;
    //         break;
    //     }
    // }
    // return missing;
    // 
    // 数学方法
    // int totol = n*(n+1)/2;
    // int arrsum = 0;
    // for(int i =0; i<n;++i){
    //     arrsum+=nums[i];
    // }
    // return totol - arrsum;


    //排序法
    //sort(nums.begin(), nums.end());
    // int n = nums.size();
    // for (int i = 0; i < n; ++i) {
    //     if (nums[i] != i) {
    //         return i;
    //     }
    // }
    // return n;

    //位运算
    int res = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        res ^= nums[i];
    }
    for (int i = 0; i <= n; i++) {
        res ^= i;
    }
    return res;
}