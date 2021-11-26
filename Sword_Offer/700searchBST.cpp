#include"functions.h"

//给定二叉搜索树（BST）的根节点和一个值。 你需要在BST中找到节点值等于给定值的节点。 返回以该节点为根的子树。 如果节点不存在，则返回 NULL。

TreeNode* searchBST(TreeNode* root, int val) {

    //递归
    // if(root == nullptr){
    //     return nullptr;
    // }
    // if(root->val == val){
    //     return root;
    // }
    // return searchBST(val < root->val ? root->left : root->right, val);
    // 
    // 
    //迭代
    while (root) {
        if (val == root->val) {
            return root;
        }
        root = val < root->val ? root->left : root->right;
    }
    return nullptr;