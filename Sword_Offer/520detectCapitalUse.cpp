#include"functions.h"


//我们定义，在以下情况时，单词的大写用法是正确的：
//
//全部字母都是大写，比如 "USA" 。
//单词中所有字母都不是大写，比如 "leetcode" 。
//如果单词不只含有一个字母，只有首字母大写， 比如 "Google" 。
//给你一个字符串 word 。如果大写用法正确，返回 true ；否则，返回 false 。

bool detectCapitalUse(string word) {
    // 若第 1 个字母为小写，则需额外判断第 2 个字母是否为小写
    if (word.size() >= 2 && islower(word[0]) && isupper(word[1])) {
        return false;
    }

    // 无论第 1 个字母是否大写，其他字母必须与第 2 个字母的大小写相同
    for (int i = 2; i < word.size(); ++i) {
        if (islower(word[i]) ^ islower(word[1])) {
            return false;
        }
    }
    return true;

}