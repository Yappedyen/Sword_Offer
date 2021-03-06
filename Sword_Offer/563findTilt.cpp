#include"functions.h"


//给定一个二叉树，计算 整个树 的坡度 。
//
//一个树的 节点的坡度 定义即为，该节点左子树的节点之和和右子树节点之和的 差的绝对值 。如果没有左子树的话，左子树的节点之和为 0 ；没有右子树的话也是一样。空结点的坡度是 0 。
//
//整个树 的坡度就是其所有节点的坡度之和。

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