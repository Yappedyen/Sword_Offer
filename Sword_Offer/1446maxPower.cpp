#include"functions.h"
#include<unordered_map>
//给你一个字符串 s ，字符串的「能量」定义为：只包含一种字符的最长非空子字符串的长度。
//
//请你返回字符串的能量。

typedef pair<char, int> PAIR;

static bool cmp_by_value(const PAIR& lhs, const PAIR& rhs) {
    return lhs.second > rhs.second;
}

struct CmpByValue {
    bool operator()(const PAIR& lhs, const PAIR& rhs) {
        return lhs.second > rhs.second;
    }
};

int maxPower(string s) {
    // int ans = 1, cnt = 1;
    // for (int i = 1; i < s.length(); ++i) {
    //     if (s[i] == s[i - 1]) {
    //         ++cnt;
    //         ans = max(ans, cnt);
    //     } else {
    //         cnt = 1;
    //     }
    // }
    // return ans;
    unordered_map<char, int> m;
    for (auto ss : s) {
        ++m[ss];
    }

    vector<PAIR> n(m.begin(), m.end());
    sort(n.begin(), n.end(), cmp_by_value);

    return n.begin()->second;
}