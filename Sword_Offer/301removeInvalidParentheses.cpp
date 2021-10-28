#include"functions.h"


//����һ�����������ź���ĸ��ɵ��ַ��� s ��ɾ����С��������Ч���ţ�ʹ��������ַ�����Ч��
//
//�������п��ܵĽ�����𰸿��԰� ����˳�� ���ء�
vector<string> res;
inline bool isValid(const string& str) {
    int cnt = 0;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(') {
            cnt++;
        }
        else if (str[i] == ')') {
            cnt--;
            if (cnt < 0) {
                return false;
            }
        }
    }

    return cnt == 0;
}


void helper(string str, int start, int lcount, int rcount, int lremove, int rremove) {
    if (lremove == 0 && rremove == 0) {
        if (isValid(str)) {
            res.push_back(str);
        }
        return;
    }

    for (int i = start; i < str.size(); i++) {
        if (i != start && str[i] == str[i - 1]) {
            continue;
        }
        // ���ʣ����ַ��޷�����ȥ��������Ҫ��ֱ�ӷ���
        if (lremove + rremove > str.size() - i) {
            return;
        }
        // ����ȥ��һ��������
        if (lremove > 0 && str[i] == '(') {
            helper(str.substr(0, i) + str.substr(i + 1), i, lcount, rcount, lremove - 1, rremove);
        }
        // ����ȥ��һ��������
        if (rremove > 0 && str[i] == ')') {
            helper(str.substr(0, i) + str.substr(i + 1), i, lcount, rcount, lremove, rremove - 1);
        }
        if (str[i] == ')') {
            lcount++;
        }
        else if (str[i] == ')') {
            rcount++;
        }
        // ��ǰ�����ŵ��������������ŵ�������Ϊ�Ƿ�,ֱ�ӷ���.
        if (rcount > lcount) {
            break;
        }
    }
}


vector<string> removeInvalidParentheses(string s) {
    int lremove = 0;
    int rremove = 0;

    for (char c : s) {
        if (c == '(') {
            lremove++;
        }
        else if (c == ')') {
            if (lremove == 0) {
                rremove++;
            }
            else {
                lremove--;
            }
        }
    }
    helper(s, 0, 0, 0, lremove, rremove);
    return res;
}
