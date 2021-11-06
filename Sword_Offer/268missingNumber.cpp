#include"functions.h"


int missingNumber(vector<int>& nums) {

    //��ϣ����O(n)
    // ���ȱ�������nums���������е�ÿ��Ԫ�ؼ����ϣ���ϣ�Ȼ�����μ��� 0 �� n ��ÿ�������Ƿ��ڹ�ϣ�����У�
    // ���ڹ�ϣ�����е����ּ�Ϊ��ʧ�����֡����ڹ�ϣ���ϵ�ÿ�����Ԫ�غͲ���Ԫ�ص�ʱ�临�Ӷȶ���O(1)�������ʱ�临�Ӷ���O(n)��
    //int n = nums.size();
    // unordered_set<int> m;
    // for(int i = 0;i<n;++i){
    //     m.insert(nums[i]);
    // }
    // int missing = -1;
    // for (int i = 0; i <= n; i++) {
    //     if (!m.count(i)) {
    //         missing = i;
    //         break;
    //     }
    // }
    // return missing;
    // 
    // ��ѧ����
    // int totol = n*(n+1)/2;
    // int arrsum = 0;
    // for(int i =0; i<n;++i){
    //     arrsum+=nums[i];
    // }
    // return totol - arrsum;


    //����
    //sort(nums.begin(), nums.end());
    // int n = nums.size();
    // for (int i = 0; i < n; ++i) {
    //     if (nums[i] != i) {
    //         return i;
    //     }
    // }
    // return n;

    //λ����
    int res = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        res ^= nums[i];
    }
    for (int i = 0; i <= n; i++) {
        res ^= i;
    }
    return res;
}