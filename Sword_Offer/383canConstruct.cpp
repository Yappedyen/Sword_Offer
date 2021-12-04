#include"functions.h"


//为了不在赎金信中暴露字迹，从杂志上搜索各个需要的字母，组成单词来表达意思。
//
//给你一个赎金信(ransomNote) 字符串和一个杂志(magazine)字符串，判断 ransomNote 能不能由 magazines 里面的字符构成。
//
//如果可以构成，返回 true ；否则返回 false 。
//
//magazine 中的每个字符只能在 ransomNote 中使用一次。


bool canConstruct(string ransomNote, string magazine) {

    // unordered_map<char,int> m;

    // for(auto maga:magazine){
    //     m[maga]++;
    // }
    // for(auto note : ransomNote){
    //     m[note]--;
    // }

    // for(unordered_map<char,int>::iterator it = m.begin();it != m.end();it++){
    //     if(it->second <0){
    //         return false;
    //     }
    // }
    // return true;


    if (ransomNote.size() > magazine.size()) {
        return false;
    }

    vector<int> v(26);
    for (auto mag : magazine) {
        v[mag - 'a']++;
    }
    for (auto ran : ransomNote) {
        v[ran - 'a']--;
        if (v[ran - 'a'] < 0) {
            return false;
        }
    }
    return true;

    if (ransomNote.size() > magazine.size()) {
        return false;
    }
    vector<int> cnt(26);
    for (auto& c : magazine) {
        cnt[c - 'a']++;
    }
    for (auto& c : ransomNote) {
        cnt[c - 'a']--;
        if (cnt[c - 'a'] < 0) {
            return false;
        }
    }
    return true;
}