#include<iostream>
#include<vector>

using namespace std;

//现给定一个具体的矩形页面面积，你的任务是设计一个长度为 L 和宽度为 W 且满足以下要求的矩形的页面。要求：
//1. 你设计的矩形页面必须等于给定的目标面积。
//2. 宽度 W 不应大于长度 L，换言之，要求 L >= W 。
//3. 长度 L 和宽度 W 之间的差距应当尽可能小。
//你需要按顺序输出你设计的页面的长度 L 和宽度 W。

//W收敛的速率比L收敛的快，所以开平方之后取floor，向下遍历求W要比开平方之后取ceil向上遍历取L要快
vector<int> constructRectangle(int area) {
    int w = sqrt(1.0 * area);
    while (area % w) {
        --w;
    }
    return { area / w, w };

}