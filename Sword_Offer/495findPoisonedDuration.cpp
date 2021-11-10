#include"functions.h"

//在《英雄联盟》的世界中，有一个叫 “提莫” 的英雄。他的攻击可以让敌方英雄艾希（编者注：寒冰射手）进入中毒状态。
//
//当提莫攻击艾希，艾希的中毒状态正好持续 duration 秒。
//
//正式地讲，提莫在 t 发起发起攻击意味着艾希在时间区间[t, t + duration - 1]（含 t 和 t + duration - 1）处于中毒状态。如果提莫在中毒影响结束 前 再次攻击，中毒状态计时器将会 重置 ，在新的攻击之后，中毒影响将会在 duration 秒后结束。
//
//给你一个 非递减 的整数数组 timeSeries ，其中 timeSeries[i] 表示提莫在 timeSeries[i] 秒时对艾希发起攻击，以及一个表示中毒持续时间的整数 duration 。
//
//返回艾希处于中毒状态的 总 秒数。

int findPoisonedDuration(vector<int>& timeSeries, int duration) {
    //O(n),O(1)
    // int n = timeSeries.size();
    // int sum = 0;
    // for(int i = 0;i<n-1;++i){
    //     int m = timeSeries[i]+duration-1;
    //     if(m>=timeSeries[i+1]){
    //         sum +=timeSeries[i+1]-timeSeries[i];
    //     }else{
    //         sum+=duration;
    //     }
    // }
    // sum +=duration;
    // return sum;


    //简洁
    // auto res = 0;
    // for (auto i = 1; i < timeSeries.size(); ++i) {
    //     res += min(timeSeries[i] - timeSeries[i - 1], duration);
    // }
    // return res + duration;


    //单次扫描
    int ans = 0;
    int expired = 0;
    for (int i = 0; i < timeSeries.size(); ++i) {
        if (timeSeries[i] >= expired) {
            ans += duration;
        }
        else {
            ans += timeSeries[i] + duration - expired;
        }
        expired = timeSeries[i] + duration;
    }
    return ans;
}