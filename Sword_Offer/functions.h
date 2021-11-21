#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
	int findRepeatNumber(vector<int>& nums);
	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target);
};


// * Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};