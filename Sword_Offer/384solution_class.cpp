#include"functions.h"


//����һ���������� nums ������㷨������һ��û���ظ�Ԫ�ص����顣
//
//ʵ�� Solution class :
//
//    Solution(int[] nums) ʹ���������� nums ��ʼ������
//    int[] reset() �������鵽���ĳ�ʼ״̬������
//    int[] shuffle() ��������������Һ�Ľ��

class Solution {
public:
    Solution(vector<int>& nums) :origin(nums), m(nums) {

    }

    vector<int> reset() {
        return origin;
    }

    vector<int> shuffle() {
        int n = m.size();
        for (int i = 0; i < n; ++i)
        {
            auto r = i + rand() % (n - i);	// r : [ i, n - 1 ]
            swap(m[i], m[r]);
        }
        return m;
    }
private:
    vector<int> m;
    vector<int> origin;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */