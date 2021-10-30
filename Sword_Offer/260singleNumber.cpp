#include"functions.h"


//����һ���������� nums������ǡ��������Ԫ��ֻ����һ�Σ���������Ԫ�ؾ��������Ρ� 
//�ҳ�ֻ����һ�ε�������Ԫ�ء�����԰� ����˳�� ���ش𰸡�



vector<int> singleNumber(vector<int>& nums) {
    //���ף�����㷨Ӧ�þ�������ʱ�临�Ӷȡ����ܷ��ʹ�ó����ռ临�Ӷ���ʵ�֣�
    //O(n),O(1)
    int xorsum = 0;
    for (int num : nums) {
        xorsum ^= num;
    }
    // ��ֹ���
    int lsb = (xorsum == INT_MIN ? xorsum : xorsum & (-xorsum));
    int type1 = 0, type2 = 0;
    for (int num : nums) {
        if (num & lsb) {
            type1 ^= num;
        }
        else {
            type2 ^= num;
        }
    }
    return { type1, type2 };

    //O(n),O(n)
    // vector<int> v;
    // unordered_map<int,int> m;
    // for(auto r:nums){
    //     m[r]++;
    // }

    // for(auto & num:m){
    //     if(num.second == 1){
    //         v.push_back(num.first);
    //     }
    // }
    // return v;

}