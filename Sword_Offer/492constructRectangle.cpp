#include<iostream>
#include<vector>

using namespace std;

//�ָ���һ������ľ���ҳ�������������������һ������Ϊ L �Ϳ��Ϊ W ����������Ҫ��ľ��ε�ҳ�档Ҫ��
//1. ����Ƶľ���ҳ�������ڸ�����Ŀ�������
//2. ��� W ��Ӧ���ڳ��� L������֮��Ҫ�� L >= W ��
//3. ���� L �Ϳ�� W ֮��Ĳ��Ӧ��������С��
//����Ҫ��˳���������Ƶ�ҳ��ĳ��� L �Ϳ�� W��

//W���������ʱ�L�����Ŀ죬���Կ�ƽ��֮��ȡfloor�����±�����WҪ�ȿ�ƽ��֮��ȡceil���ϱ���ȡLҪ��
vector<int> constructRectangle(int area) {
    int w = sqrt(1.0 * area);
    while (area % w) {
        --w;
    }
    return { area / w, w };

}