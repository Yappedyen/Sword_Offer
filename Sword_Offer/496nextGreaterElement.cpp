#include"functions.h"
#include<unordered_map>
#include<stack>
//给你两个 没有重复元素 的数组 nums1 和 nums2 ，其中nums1 是 nums2 的子集。
//请你找出 nums1 中每个元素在 nums2 中的下一个比其大的值。
//nums1 中数字 x 的下一个更大元素是指 x 在 nums2 中对应位置的右边的第一个比 x 大的元素。如果不存在，对应位置输出 - 1 。

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {


    int n = nums1.size();
    vector<int>v;
    for (int i = 0; i < n; i++) {
        auto it = find(nums2.begin(), nums2.end(), nums1[i]);
        for (auto j = it; j != nums2.end(); j++) {
            if (*j > nums1[i]) {
                v.push_back(*j);
                break;
            }
            else if (j == --nums2.end()) {
                v.push_back(-1);
            }
        }
    }
    return v;


    //O(m+n)
    unordered_map<int, int> hashmap;
    stack<int> st;
    for (int i = nums2.size() - 1; i >= 0; --i) {
        int num = nums2[i];
        while (!st.empty() && num >= st.top()) {
            st.pop();
        }
        hashmap[num] = st.empty() ? -1 : st.top();
        st.push(num);
    }
    vector<int> res(nums1.size());
    for (int i = 0; i < nums1.size(); ++i) {
        res[i] = hashmap[nums1[i]];
    }
    return res;

}