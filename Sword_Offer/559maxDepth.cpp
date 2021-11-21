#include"functions.h"
using namespace std;

//����һ�� N �������ҵ��������ȡ�
//
//��������ָ�Ӹ��ڵ㵽��ԶҶ�ӽڵ���·���ϵĽڵ�������
//
//N �������밴����������л���ʾ��ÿ���ӽڵ��ɿ�ֵ�ָ�����μ�ʾ������

//���룺root = [1, null, 3, 2, 4, null, 5, 6]
//�����3



int maxDepth(Node* root) {

    // //dfs
    // if(root==nullptr){
    //     return 0;
    // }
    // int maxchildDepth = 0;
    // auto children = root->children;
    // for(auto chil:children){
    //     int childDepth=maxDepth(chil);
    //     maxchildDepth = max(maxchildDepth,childDepth);
    // }
    // return maxchildDepth+1;


    //bfs
    if (root == nullptr) {
        return 0;
    }
    queue<Node*> qu;
    qu.push(root);
    int ans = 0;
    while (!qu.empty()) {
        int size = qu.size();
        while (size > 0) {
            Node* node = qu.front();
            qu.pop();
            vector<Node*> children = node->children;
            for (auto child : children) {
                qu.push(child);
            }
            size--;
        }
        ans++;
    }
    return ans;

}