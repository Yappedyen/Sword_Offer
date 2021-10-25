#include<iostream>
#include<vector>
using namespace std;


bool searchMatrix(vector<vector<int>>& matrix, int target) {
    for (const auto& row : matrix) {
        auto it = lower_bound(row.begin(), row.end(), target);
        if (it != row.end() && *it == target) {
            return true;
        }
    }
    return false;
}