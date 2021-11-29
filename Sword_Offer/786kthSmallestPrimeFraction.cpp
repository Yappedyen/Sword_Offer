#include"functions.h"


//给你一个按递增顺序排序的数组 arr 和一个整数 k 。数组 arr 由 1 和若干 素数  组成，且其中所有整数互不相同。
//对于每对满足 0 < i < j < arr.length 的 i 和 j ，可以得到分数 arr[i] / arr[j] 。
//那么第 k 个最小的分数是多少呢 ? 以长度为 2 的整数数组返回你的答案, 这里 answer[0] == arr[i] 且 answer[1] == arr[j] 。

vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
    // int n = arr.size();
    // vector<pair<int, int>> frac;
    // for (int i = 0; i < n; ++i) {
    //     for (int j = i + 1; j < n; ++j) {
    //         frac.emplace_back(arr[i], arr[j]);
    //     }
    // }
    // sort(frac.begin(), frac.end(), [&](const auto& x, const auto& y) {
    //     return x.first * y.second < x.second * y.first;
    // });
    // return {frac[k - 1].first, frac[k - 1].second};

    // int n = arr.size();
    // auto cmp = [&](const pair<int, int>& x, const pair<int, int>& y) {
    //     return arr[x.first] * arr[y.second] > arr[x.second] * arr[y.first];
    // };
    // priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
    // for (int j = 1; j < n; ++j) {
    //     q.emplace(0, j);
    // }
    // for (int _ = 1; _ < k; ++_) {
    //     auto [i, j] = q.top();
    //     q.pop();
    //     if (i + 1 < j) {
    //         q.emplace(i + 1, j);
    //     }
    // }
    // return {arr[q.top().first], arr[q.top().second]};


    int n = arr.size();
    double left = 0.0, right = 1.0;
    while (true) {
        double mid = (left + right) / 2;
        int i = -1, count = 0;
        // 记录最大的分数
        int x = 0, y = 1;

        for (int j = 1; j < n; ++j) {
            while ((double)arr[i + 1] / arr[j] < mid) {
                ++i;
                if (arr[i] * y > arr[j] * x) {
                    x = arr[i];
                    y = arr[j];
                }
            }
            count += i + 1;
        }

        if (count == k) {
            return { x, y };
        }
        if (count < k) {
            left = mid;
        }
        else {
            right = mid;
        }
    }
}