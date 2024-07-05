#include <stdio.h>
/*
@func: 平均值滤波 C语言 验证
@param: a serise signal samples
@return: output the averge signal value
优点：不用像中位值滤波器那样排序，所以速度快很多。
*/

#define N 5

int middleFilter(int *psignal){
    int avg = 0;
    for(int i=0; i<N; i++){
        avg += psignal[i];
    }
    avg = avg / N;

    return avg;
}

int main(){
    //假设采集到一系列的数据，每5个数，取一次中值，作为滤波结果
    int signal1[] = {1,5,2,4,3};
    int signal2[] = {6,7,10,8,9};
    int signal3[] = {13,12,11,15,14};

    int output;
    
    output = middleFilter(signal1);
    printf("%d\t", output);
    output = middleFilter(signal2);
    printf("%d\t", output);
    output = middleFilter(signal3);
    printf("%d\t", output);

    return 0;
}