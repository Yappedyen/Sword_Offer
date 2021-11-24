#include"functions.h"
#include<unordered_map>

//给你一个字符串 s ，其中包含字母顺序打乱的用英文单词表示的若干数字（0 - 9）。按 升序 返回原始的数字。


//vector<string> strVec = { "zero","six","eight","two","seven","five","four","three","one","nine" };
//vector<int> seq = { 0,6,8,2,7,5,4,3,1,9 };
string originalDigits(string s) {
    // unordered_map<char,int> hash;
    // vector<int> cnt(10);
    // for (char c : s) hash[c]++;
    // for (int i = 0; i < 10; i++) {
    //     int t = INT_MAX, n = strVec[i].size();
    //     for (int j = 0; j < n; j++) {
    //         t = min(t, hash[strVec[i][j]]);
    //     }
    //     for (int j = 0; j < n; j++) {
    //         hash[strVec[i][j]] -= t;
    //     }
    //     cnt[i] = t;
    // }
    // string ans = "";
    // for (int i = 0; i < 10; i++) {
    //     for (int j = 0; j < cnt[i]; j++) {
    //         ans += '0' + seq[i];
    //     }
    // }
    // sort(ans.begin(), ans.end());
    // return ans;

    unordered_map<char, int> c;
    for (char ch : s) {
        ++c[ch];
    }

    vector<int> cnt(10);
    cnt[0] = c['z'];
    cnt[2] = c['w'];
    cnt[4] = c['u'];
    cnt[6] = c['x'];
    cnt[8] = c['g'];

    cnt[3] = c['h'] - cnt[8];
    cnt[5] = c['f'] - cnt[4];
    cnt[7] = c['s'] - cnt[6];

    cnt[1] = c['o'] - cnt[0] - cnt[2] - cnt[4];

    cnt[9] = c['i'] - cnt[5] - cnt[6] - cnt[8];

    string ans;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < cnt[i]; ++j) {
            ans += char(i + '0');
        }
    }
    return ans;
}