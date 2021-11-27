#include"functions.h"


//给你一个 m x n 的二元矩阵 matrix ，且所有值被初始化为 0 。请你设计一个算法，随机选取一个满足 matrix[i][j] == 0 的下标 (i, j) ，并将它的值变为 1 。所有满足 matrix[i][j] == 0 的下标(i, j) 被选取的概率应当均等。
//
//尽量最少调用内置的随机函数，并且优化时间和空间复杂度。
//
//实现 Solution 类：
//
//Solution(int m, int n) 使用二元矩阵的大小 m 和 n 初始化该对象
//int[] flip() 返回一个满足 matrix[i][j] == 0 的随机下标[i, j] ，并将其对应格子中的值变为 1
//void reset() 将矩阵中所有的值重置为 0

class Solution {
    // public:
    //         Solution(int m, int n) {
    //         this->m = m;
    //         this->n = n;
    //         this->total = m * n;
    //         srand(time(nullptr));
    //     }

    //     vector<int> flip() {
    //         int x = rand() % total;
    //         vector<int> ans;
    //         total--;   
    //         // 查找位置 x 对应的映射
    //         if (map.count(x)) {
    //             ans = {map[x] / n, map[x] % n};
    //         } else {
    //             ans = {x / n, x % n};
    //         }
    //         // 将位置 x 对应的映射设置为位置 total 对应的映射
    //         if (map.count(total)) {
    //             map[x] = map[total];
    //         } else {
    //             map[x] = total;
    //         }
    //         return ans;
    //     }

    //     void reset() {
    //         total = m * n;
    //         map.clear();
    //     }
    // private:
    //     int m;
    //     int n;
    //     int total;
    //     unordered_map<int, int> map;

public:
    int n, len;
    int next;
    Solution(int m, int n) {
        this->n = n;
        len = m * n;
        reset();
    }

    vector<int> flip() {
        int k = next;
        next = (next + 1) % len;
        return { k / n, k % n };
    }

    void reset() {
        next = rand() % len;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */