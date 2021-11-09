#include"functions.h"
#include<unordered_map>
#include<stack>
//�����ڲ���������Ϸ��һ�����֡�

//�����������Ϸ�����У��������� һ�� ����ÿ�������ɫ�����ǣ���ɫ 'R'����ɫ 'Y'����ɫ 'B'����ɫ 'G' ���ɫ 'W' ���������Ҳ��һЩ����
//
//���Ŀ���� ��� ���������е���ÿһ�غϣ�
//
//�������ϵĲ�����ѡ�� ����һ�� ��Ȼ���������������һ�����У�����֮�����һ�������һ�ˡ�
//���ţ�����г��� ���������������� �� ��ɫ��ͬ ���������Ļ����Ͱ������Ƴ�����
//��������Ƴ�����ͬ�����³�����������������������ɫ��ͬ��������������Լ����Ƴ���Щ��ֱ�����������Ƴ�������
//��������������򶼱��Ƴ�������Ϊ��Ӯ�ñ�����Ϸ��
//�ظ�������̣�ֱ����Ӯ����Ϸ��������û�и������
//����һ���ַ��� board ����ʾ�������ʼ�������������һ���ַ��� hand ����ʾ����Ĳ������㰴�������������Ƴ������������򣬼��㲢��������� ���� ��������������Ƴ��������е��򣬷��� - 1 ��

int ans, used;
unordered_map<char, int> rem;
stack<pair<char, int>> st;

void dfs(int pos, string& board) {
    if (used >= ans)
        return;

    if (pos == board.size()) {
        if (st.empty())
            ans = used;
        return;
    }

    // ��posλ�õ�С�����
    if (!st.empty() && st.top().first == board[pos]) {
        st.top().second++;
    }
    else {
        st.emplace(board[pos], 1);
    }

    if (st.top().second >= 3) {
        if (pos + 1 == board.size() || board[pos + 1] != board[pos]) {
            // ����û����ͬ��ɫ���򣬿���ֱ����ȥ
            auto tmp = st.top();
            st.pop();
            dfs(pos + 1, board);
            st.push(tmp);
        }
        else {
            // ��������ͬ��ɫ���򣬱�������뵱ǰλ�ò�ͬɫ��С����зָ��󣬲��ܽ���ǰ���۵�С����ȥ���������ͺ����ͬɫ��һ����ȥ��
            auto tmp = st.top(); // ά���ֳ�
            st.pop(); // ��ȥ��ǰ���۵�ͬɫС��

            for (auto [ch, num] : rem) {
                if (ch == board[pos])
                    continue;
                for (int j = 1; j <= min(3, num); ++j) {
                    rem[ch] -= j;
                    used += j;

                    // ����j��С��
                    if (!st.empty() && st.top().first == ch) {
                        st.top().second += j;
                    }
                    else {
                        st.emplace(ch, j);
                    }

                    if (st.top().second >= 3) { // �������ɫ���֮ǰ�����ۼӴﵽ������
                        auto tmp2 = st.top(); // ά���ֳ�
                        st.pop(); // ��ȥͬɫ��
                        dfs(pos + 1, board);
                        st.push(tmp2); // ��ԭ�ֳ�
                    }
                    else {
                        dfs(pos + 1, board);
                    }

                    // ��ԭ�ֳ�
                    if (st.top().second > j) {
                        st.top().second -= j;
                    }
                    else {
                        st.pop();
                    }
                    used -= j;
                    rem[ch] += j;
                }
            }

            st.push(tmp); // ��ԭ�ֳ�
        }
    }

    // �����뵱ǰλ��ͬɫ��С��
    if (rem[board[pos]] >= 1 && (pos + 1 == board.size() || board[pos + 1] != board[pos])) {
        int lim = rem[board[pos]];
        for (int i = 1; i <= min(2, lim); ++i) {
            // ����i��ͬɫС��
            rem[board[pos]] -= i;
            used += i;
            st.top().second += i;
            if (st.top().second >= 3) { // �ۻ�ͬɫ��ﵽ����
                auto tmp = st.top(); // ά���ֳ�
                st.pop(); // ��ȥͬɫ��
                dfs(pos + 1, board);
                st.push(tmp); // ��ԭ�ֳ�
            }
            else {
                dfs(pos + 1, board);
            }

            // ��ԭ�ֳ�
            st.top().second -= i;
            used -= i;
            rem[board[pos]] += i;
        }
    }

    // ���������С�������
    // 1. ��ǰ��ɫС��������
    // 2. ��ǰ��ɫС��������������ǰС�����һС��ͬɫ����˵����ʼ����ΪXX...XX��֮���м��С����ȥ���Ӷ��γ���XXXX���������������ġ�
    if (st.top().second < 3 || (st.top().second == 3 && pos + 1 < board.size() && board[pos] == board[pos + 1]))
        dfs(pos + 1, board);

    // ��ԭ�ֳ�
    if (st.top().second == 1) {
        st.pop();
    }
    else {
        st.top().second--;
    }
}

int findMinStep(string board, string hand) {
    for (char ch : hand)
        rem[ch]++;

    ans = 1e9;
    used = 0;
    dfs(0, board);
    return ans == 1e9 ? -1 : ans;
}