#include"functions.h"


//给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
//
//异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。


vector<int> findAnagrams(string s, string p) {
    // int m = s.size();
    // int n = p.size();
    // if(m<n){
    //     return vector<int>();
    // }

    // vector<int> ans;
    // vector<int> scount(26);
    // vector<int> pcount(26);
    // for(int i = 0;i<n;++i){
    //     ++scount[s[i]-'a'];
    //     ++pcount[p[i]-'a'];
    // }
    // if(scount == pcount){
    //     ans.emplace_back(0);
    // }

    // for(int i = 0;i<m-n;++i){
    //     --scount[s[i]-'a'];
    //     ++scount[s[i+n]-'a'];

    //     if(scount == pcount){
    //         ans.emplace_back(i+1);
    //     }
    // }
    // return ans;

    int sLen = s.size(), pLen = p.size();

    if (sLen < pLen) {
        return vector<int>();
    }

    vector<int> ans;
    vector<int> count(26);
    for (int i = 0; i < pLen; ++i) {
        ++count[s[i] - 'a'];
        --count[p[i] - 'a'];
    }

    int differ = 0;
    for (int j = 0; j < 26; ++j) {
        if (count[j] != 0) {
            ++differ;
        }
    }

    if (differ == 0) {
        ans.emplace_back(0);
    }

    for (int i = 0; i < sLen - pLen; ++i) {
        if (count[s[i] - 'a'] == 1) {  // 窗口中字母 s[i] 的数量与字符串 p 中的数量从不同变得相同
            --differ;
        }
        else if (count[s[i] - 'a'] == 0) {  // 窗口中字母 s[i] 的数量与字符串 p 中的数量从相同变得不同
            ++differ;
        }
        --count[s[i] - 'a'];

        if (count[s[i + pLen] - 'a'] == -1) {  // 窗口中字母 s[i+pLen] 的数量与字符串 p 中的数量从不同变得相同
            --differ;
        }
        else if (count[s[i + pLen] - 'a'] == 0) {  // 窗口中字母 s[i+pLen] 的数量与字符串 p 中的数量从相同变得不同
            ++differ;
        }
        ++count[s[i + pLen] - 'a'];

        if (differ == 0) {
            ans.emplace_back(i + 1);
        }
    }

    return ans;
}