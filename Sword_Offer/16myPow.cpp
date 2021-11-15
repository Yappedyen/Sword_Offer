#include"functions.h"


//实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，xn）。不得使用库函数，同时不需要考虑大数问题。
double myPow(double x, int n) {

    // double res=1;
    // double base=x;
    // bool flag=n>=0;
    // //负数取反，考虑到最小负数，需要先自增，后续再除以2
    // if(!flag) n=-(++n);
    // while(n>0){
    //     if(n&1) res*=x;
    //     n=n>>1;
    //     x*=x;
    // }
    // return flag?res:1/(res*base);

    if (n == 0) return 1;
    //考虑到负数右移永远是负数，
    if (n == -1) return 1 / x;
    if (n & 1) return myPow(x * x, n >> 1) * x;
    else return myPow(x * x, n >> 1);
}