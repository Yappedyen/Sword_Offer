#include"functions.h"

//����������������BST���ĸ��ڵ��һ��ֵ�� ����Ҫ��BST���ҵ��ڵ�ֵ���ڸ���ֵ�Ľڵ㡣 �����Ըýڵ�Ϊ���������� ����ڵ㲻���ڣ��򷵻� NULL��

TreeNode* searchBST(TreeNode* root, int val) {

    //�ݹ�
    // if(root == nullptr){
    //     return nullptr;
    // }
    // if(root->val == val){
    //     return root;
    // }
    // return searchBST(val < root->val ? root->left : root->right, val);
    // 
    // 
    //����
    while (root) {
        if (val == root->val) {
            return root;
        }
        root = val < root->val ? root->left : root->right;
    }
    return nullptr;