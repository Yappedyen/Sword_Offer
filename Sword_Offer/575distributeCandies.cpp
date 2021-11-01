#include"functions.h"


//����һ��ż�����ȵ����飬���в�ͬ�����ִ����Ų�ͬ������ǹ���ÿһ�����ִ���һ���ǹ�������Ҫ����Щ�ǹ�ƽ���ָ�һ���ܵܺ�һ�����á��������ÿ��Ի�õ�����ǹ�����������

int distributeCandies(vector<int>& candyType) {

    //O(nlogn),O(1)
    int n = candyType.size();
    sort(candyType.begin(), candyType.end());
    int count = 1;
    for (int i = 1; i < n && count < n / 2; ++i)
        if (candyType[i] > candyType[i - 1])
            count++;
    return count;
    //O(n),O(n)
    //return min(unordered_set<int>(candyType.begin(), candyType.end()).size(), candyType.size() / 2);
}