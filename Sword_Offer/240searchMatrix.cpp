#include<iostream>
#include<vector>
using namespace std;

//编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target 。该矩阵具有以下特性：
//
//每行的元素从左到右升序排列。
//每列的元素从上到下升序排列。

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    for (const auto& row : matrix) {
        auto it = lower_bound(row.begin(), row.end(), target);
        if (it != row.end() && *it == target) {
            return true;
        }
    }
    return false;
}