#include"functions.h"


//ʵ�� pow(x, n) �������� x �� n ���ݺ���������xn��������ʹ�ÿ⺯����ͬʱ����Ҫ���Ǵ������⡣
double myPow(double x, int n) {

    // double res=1;
    // double base=x;
    // bool flag=n>=0;
    // //����ȡ�������ǵ���С��������Ҫ�������������ٳ���2
    // if(!flag) n=-(++n);
    // while(n>0){
    //     if(n&1) res*=x;
    //     n=n>>1;
    //     x*=x;
    // }
    // return flag?res:1/(res*base);

    if (n == 0) return 1;
    //���ǵ�����������Զ�Ǹ�����
    if (n == -1) return 1 / x;
    if (n & 1) return myPow(x * x, n >> 1) * x;
    else return myPow(x * x, n >> 1);
}