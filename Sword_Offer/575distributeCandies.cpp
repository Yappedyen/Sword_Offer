#include"functions.h"


//给定一个偶数长度的数组，其中不同的数字代表着不同种类的糖果，每一个数字代表一个糖果。你需要把这些糖果平均分给一个弟弟和一个妹妹。返回妹妹可以获得的最大糖果的种类数。

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