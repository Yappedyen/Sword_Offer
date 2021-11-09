#include"functions.h"
#include<unordered_map>
#include<stack>
//你正在参与祖玛游戏的一个变种。

//在这个祖玛游戏变体中，桌面上有 一排 彩球，每个球的颜色可能是：红色 'R'、黄色 'Y'、蓝色 'B'、绿色 'G' 或白色 'W' 。你的手中也有一些彩球。
//
//你的目标是 清空 桌面上所有的球。每一回合：
//
//从你手上的彩球中选出 任意一颗 ，然后将其插入桌面上那一排球中：两球之间或这一排球的任一端。
//接着，如果有出现 三个或者三个以上 且 颜色相同 的球相连的话，就把它们移除掉。
//如果这种移除操作同样导致出现三个或者三个以上且颜色相同的球相连，则可以继续移除这些球，直到不再满足移除条件。
//如果桌面上所有球都被移除，则认为你赢得本场游戏。
//重复这个过程，直到你赢了游戏或者手中没有更多的球。
//给你一个字符串 board ，表示桌面上最开始的那排球。另给你一个字符串 hand ，表示手里的彩球。请你按上述操作步骤移除掉桌上所有球，计算并返回所需的 最少 球数。如果不能移除桌上所有的球，返回 - 1 。

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

    // 将pos位置的小球加入
    if (!st.empty() && st.top().first == board[pos]) {
        st.top().second++;
    }
    else {
        st.emplace(board[pos], 1);
    }

    if (st.top().second >= 3) {
        if (pos + 1 == board.size() || board[pos + 1] != board[pos]) {
            // 后面没有相同颜色的球，可以直接消去
            auto tmp = st.top();
            st.pop();
            dfs(pos + 1, board);
            st.push(tmp);
        }
        else {
            // 后面有相同颜色的球，必须插入与当前位置不同色的小球进行分隔后，才能将当前积累的小球消去；否则必须和后面的同色球一起消去。
            auto tmp = st.top(); // 维护现场
            st.pop(); // 消去当前积累的同色小球

            for (auto [ch, num] : rem) {
                if (ch == board[pos])
                    continue;
                for (int j = 1; j <= min(3, num); ++j) {
                    rem[ch] -= j;
                    used += j;

                    // 加入j个小球
                    if (!st.empty() && st.top().first == ch) {
                        st.top().second += j;
                    }
                    else {
                        st.emplace(ch, j);
                    }

                    if (st.top().second >= 3) { // 插入的异色球和之前的球累加达到了三个
                        auto tmp2 = st.top(); // 维护现场
                        st.pop(); // 消去同色球
                        dfs(pos + 1, board);
                        st.push(tmp2); // 还原现场
                    }
                    else {
                        dfs(pos + 1, board);
                    }

                    // 还原现场
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

            st.push(tmp); // 还原现场
        }
    }

    // 插入与当前位置同色的小球
    if (rem[board[pos]] >= 1 && (pos + 1 == board.size() || board[pos + 1] != board[pos])) {
        int lim = rem[board[pos]];
        for (int i = 1; i <= min(2, lim); ++i) {
            // 加入i个同色小球
            rem[board[pos]] -= i;
            used += i;
            st.top().second += i;
            if (st.top().second >= 3) { // 累积同色球达到三个
                auto tmp = st.top(); // 维护现场
                st.pop(); // 消去同色球
                dfs(pos + 1, board);
                st.push(tmp); // 还原现场
            }
            else {
                dfs(pos + 1, board);
            }

            // 还原现场
            st.top().second -= i;
            used -= i;
            rem[board[pos]] += i;
        }
    }

    // 不额外插入小球的情形
    // 1. 当前颜色小球不满三个
    // 2. 当前颜色小球满三个，但当前小球和下一小球同色，这说明初始情形为XX...XX，之后中间的小球被消去，从而形成了XXXX，这种情况是允许的。
    if (st.top().second < 3 || (st.top().second == 3 && pos + 1 < board.size() && board[pos] == board[pos + 1]))
        dfs(pos + 1, board);

    // 还原现场
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