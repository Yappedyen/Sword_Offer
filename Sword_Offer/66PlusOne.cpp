#include<iostream>
#include<vector>
#include<string>

using namespace std;

//给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。
//最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
//你可以假设除了整数 0 之外，这个整数不会以零开头。

vector<int> plusOne(vector<int>& digits) {
    int n = size(digits);
    int i = n - 1;
    while (digits[i] == 9) {
        digits[i] = 0;
        i--;
        if (i < 0) {
            vector<int> ans(n + 1);
            ans[0] = 1;
            return ans;
        }
    }
    digits[i]++;
    return digits;
}