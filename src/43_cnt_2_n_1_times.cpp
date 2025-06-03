//
// Created by Damon on 2025/5/27.
//

#include "my_algorithms.h"


#include <iostream>
#include <cmath>

int countDigitOne(int n)
{
    if(n < 1)
        return 0;
    if(n<10)
        return 1;
    //数字的位数
    int len = 0;
    int number = n;
    while(number)
    {
        len++;
        number/=10;
    }
    int ret = 0;
    //最高位的权重
    int temp = pow(10,len-1);
    //取出最高位的值
    int first = n/temp;
    if(first == 1)
    {
        //最高位取0，这时的计数值由其他的位贡献
        // 以21345为例，1可能出现在
        ret+=(len-1)*(temp/10);//高中的排列组合问题
        //最高位可以贡献的计数值
        ret+= (n%temp)+1;   // 最高位取1，则后续各位数可以任意取值，总数为除最高位后续值+1(0这个数字)
    }
    else
    {
        //最高位取0~first-1时，由其他位贡献的计数值
        ret+=first*(len-1)*(temp/10);
        //最高位可以贡献的计数值(此时最高位取值1)
        ret+= temp;
    }
    ret+= countDigitOne(n%temp);
    return ret;

}