#include"functions.h"
#include<unordered_map>


//实现一个 MapSum 类，支持两个方法，insert 和 sum：
//
//MapSum() 初始化 MapSum 对象
//void insert(String key, int val) 插入 key - val 键值对，字符串表示键 key ，整数表示值 val 。如果键 key 已经存在，那么原来的键值对将被替代成新的键值对。
//int sum(string prefix) 返回所有以该前缀 prefix 开头的键 key 的值的总和。


class MapSum {
public:
    MapSum() {

    }

    //     void insert(string key, int val) {
    //         cnt[key] = val;
    //     }

    //     int sum(string prefix) {
    //         int res = 0;
    //         for(auto & [key,val]:cnt){
    //             if(key.substr(0,prefix.size()) == prefix){
    //                 res += val;
    //             }
    //         }
    //         return res;
    //     }
    // private:
    //     unordered_map<string,int> cnt;

    void insert(string key, int val) {
        int delta = val;
        if (map.count(key)) {
            delta -= map[key];
        }
        map[key] = val;
        for (int i = 1; i <= key.size(); ++i) {
            prefixmap[key.substr(0, i)] += delta;
        }
    }

    int sum(string prefix) {
        return prefixmap[prefix];
    }
private:
    unordered_map<string, int> map;
    unordered_map<string, int> prefixmap;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */