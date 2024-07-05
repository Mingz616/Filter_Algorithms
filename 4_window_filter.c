#include <stdio.h>
/*
@func: 滑动窗口均值滤波 C语言 验证
@param: a serise signal samples
@return: output the averge signal value
*/

#define N 3

//每个滑窗取一次平均值
int windowFilter(int *psignal, int *pflag){
    int avg = 0;

    for(int i=*pflag; i<N+(*pflag); i++){
        avg += psignal[i];
    }
    *pflag += 1;    //每运算一次，滑动一次滑窗

    return avg/N;
}

int main(){
    int signal[] = {10,20,33,40,30,20,10,0,10};  
    
    int flag = 0;
    int output;

    //仅用于此列数据而已，需要循环7次滑窗
    for(int i=0; i<7; i++){
        output = windowFilter(signal, &flag);
        printf("%d\t", output);
    }

    return 0;
}