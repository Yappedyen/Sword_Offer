#include<iostream>
#include<vector>
#include<string>

using namespace std;

//����һ���� ���� ��ɵ� �ǿ� ��������ʾ�ķǸ��������ڸ����Ļ����ϼ�һ��
//���λ���ִ�����������λ�� ������ÿ��Ԫ��ֻ�洢�������֡�
//����Լ���������� 0 ֮�⣬��������������㿪ͷ��

vector<int> plusOne(vector<int>& digits) {
    int n = size(digits);
    int i = n - 1;
    while (digits[i] == 9) {
        digits[i] = 0;
        i--;
        if (i < 0) {
            vector<int> ans(n + 1);
            ans[0] = 1;
            return ans;
        }
    }
    digits[i]++;
    return digits;
}