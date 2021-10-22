#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;


//给定一个大小为 n 的整数数组，找出其中所有出现超过 ⌊ n / 3 ⌋ 次的元素。
vector<int> majorityElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans;
    unordered_map<int, int> cnt;

    for (auto& v : nums) {
        cnt[v]++;
    }
    for (auto& v : cnt) {
        if (v.second > n / 3) {
            ans.push_back(v.first);
        }
    }

    return ans;
}