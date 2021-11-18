#include"functions.h"


//����һ�������������� ������ ���¶� ��
//
//һ������ �ڵ���¶� ���弴Ϊ���ýڵ��������Ľڵ�֮�ͺ��������ڵ�֮�͵� ��ľ���ֵ �����û���������Ļ����������Ľڵ�֮��Ϊ 0 ��û���������Ļ�Ҳ��һ�����ս����¶��� 0 ��
//
//������ ���¶Ⱦ��������нڵ���¶�֮�͡�

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


int ans = 0;
int dfs(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    int lsum = dfs(root->left);
    int rsum = dfs(root->right);
    ans += abs(lsum - rsum);
    return lsum + rsum + root->val;
}
int findTilt(TreeNode* root) {
    dfs(root);
    return ans;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */