#include"functions.h"

//������һ��m��n�еķ��񣬴�����[0, 0] ������[m - 1, n - 1] ��һ�������˴�����[0, 0] �ĸ��ӿ�ʼ�ƶ���
//��ÿ�ο��������ҡ��ϡ����ƶ�һ�񣨲����ƶ��������⣩��Ҳ���ܽ�������������������λ֮�ʹ���k�ĸ��ӡ�
//���磬��kΪ18ʱ���������ܹ����뷽��[35, 37] ����Ϊ3 + 5 + 3 + 7 = 18���������ܽ��뷽��[35, 38]����Ϊ3 + 5 + 3 + 8 = 19��
//���ʸû������ܹ�������ٸ����ӣ�

//dfs
int movingCount(int m, int n, int k) {
    vector<vector<bool>> visited(m, vector<bool>(n, 0));
    return dfs(0, 0, 0, 0, visited, m, n, k);
}

int dfs(int i, int j, int si, int sj, vector<vector<bool>>& visited, int m, int n, int k) {
    if (i >= m || j >= n || k < si + sj || visited[i][j]) return 0;
    visited[i][j] = true;
    return 1 + dfs(i + 1, j, (i + 1) % 10 != 0 ? si + 1 : si - 8, sj, visited, m, n, k) +
        dfs(i, j + 1, si, (j + 1) % 10 != 0 ? sj + 1 : sj - 8, visited, m, n, k);
}

//BFS
//     // ���� x ����λ֮��
//     int get(int x) {
//         int res=0;
//         for (; x; x /= 10) {
//             res += x % 10;
//         }
//         return res;
//     }
// public:
//     int movingCount(int m, int n, int k) {
//         if (!k) return 1;
//         queue<pair<int,int> > Q;
//         // ���Һ����µķ�������
//         int dx[2] = {0, 1};
//         int dy[2] = {1, 0};
//         vector<vector<int> > vis(m, vector<int>(n, 0));
//         Q.push(make_pair(0, 0));
//         vis[0][0] = 1;
//         int ans = 1;
//         while (!Q.empty()) {
//             auto [x, y] = Q.front();
//             Q.pop();
//             for (int i = 0; i < 2; ++i) {
//                 int tx = dx[i] + x;
//                 int ty = dy[i] + y;
//                 if (tx < 0 || tx >= m || ty < 0 || ty >= n || vis[tx][ty] || get(tx) + get(ty) > k) continue;
//                 Q.push(make_pair(tx, ty));
//                 vis[tx][ty] = 1;
//                 ans++;
//             }
//         }
//         return ans;
//     }

//BFS
// int movingCount(int m, int n, int k) {
//     vector<vector<bool>> visited(m, vector<bool>(n, 0));
//     int res = 0;
//     queue<vector<int>> que;
//     que.push({ 0, 0, 0, 0 });
//     while(que.size() > 0) {
//         vector<int> x = que.front();
//         que.pop();
//         int i = x[0], j = x[1], si = x[2], sj = x[3];
//         if(i >= m || j >= n || k < si + sj || visited[i][j]) continue;
//         visited[i][j] = true;
//         res++;
//         que.push({ i + 1, j, (i + 1) % 10 != 0 ? si + 1 : si - 8, sj });
//         que.push({ i, j + 1, si, (j + 1) % 10 != 0 ? sj + 1 : sj - 8 });
//     }
//     return res;
// }