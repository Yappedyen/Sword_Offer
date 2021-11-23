#include"functions.h"


//给你两个字符串 s 和 goal ，只要我们可以通过交换 s 中的两个字母得到与 goal 相等的结果，就返回 true ；否则返回 false 。
//
//交换字母的定义是：取两个下标 i 和 j （下标从 0 开始）且满足 i != j ，接着交换 s[i] 和 s[j] 处的字符。
//
//例如，在 "abcd" 中交换下标 0 和下标 2 的元素可以生成 "cbad" 。


bool buddyStrings(string s, string goal) {
    // unordered_multimap<int,char> m;
    if (s.size() != goal.size()) {
        return false;
    }
    if (s == goal) {
        vector<int> count(26);
        for (int i = 0; i < s.size(); i++) {
            count[s[i] - 'a']++;
            if (count[s[i] - 'a'] > 1) {
                return true;
            }
        }
        return false;
    }
    else {
        // int cout = 0;
        // for(int i = 0;i<s.size();i++){
        //     if(s[i] !=goal[i]){
        //         ++cout;
        //     }
        // }
        // sort(s.begin(),s.end());
        // sort(goal.begin(),goal.end());
        // return (cout<=2)&&(s == goal);
        int first = -1, second = -1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != goal[i]) {
                if (first == -1)
                    first = i;
                else if (second == -1)
                    second = i;
                else
                    return false;
            }
        }

        return (second != -1 && s[first] == goal[second] && s[second] == goal[first]);
    }
}