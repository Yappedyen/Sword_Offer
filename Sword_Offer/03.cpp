#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//03.�������ظ�������
//�ҳ��������ظ������֡�
//
//��һ������Ϊ n ������ nums ����������ֶ��� 0��n - 1 �ķ�Χ�ڡ�
//������ĳЩ�������ظ��ģ�����֪���м��������ظ��ˣ�Ҳ��֪��ÿ�������ظ��˼��Ρ����ҳ�����������һ���ظ������֡�


int findRepeatNumber(vector<int>& nums) {
    const int n = nums.size();
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {
        if (nums[i] < 0 || nums[i] >= n)
            return -1;
        if (i < n - 1)
        {
            if (nums[i] == nums[i + 1])
            {
                return nums[i];
            }
        }
    }
    return -1;
}
