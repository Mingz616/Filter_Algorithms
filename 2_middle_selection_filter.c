#include <stdio.h>
/*
@func: 中值滤波 C语言 验证
@param: a serise signal samples
@return: output the middle signal value
*/

#define N 5     //取N个值排序

//滤波处理，冒泡法从小到大排序，选择中间的值。
int middleFilter(int *psignal){
    int tmp;

    for(int i=0; i<N-1; i++){
        for(int j=0; j<N-1-i; j++){
            if(psignal[j] > psignal[j+1]){    //swap
                tmp = psignal[j+1];
                psignal[j+1] = psignal[j];
                psignal[j] = tmp;
            }
        }
    }

    return psignal[N/2];
}

int main(){
    //假设采集到一系列的数据，每5个数，取一次中值，作为滤波结果
    int signal1[] = {1,5,2,4,3};
    int signal2[] = {6,7,10,8,9};
    int signal3[] = {13,12,11,15,14};

    int output = middleFilter(signal1);
    printf("\n%d", output);
    output = middleFilter(signal2);
    printf("\n%d", output);
    output = middleFilter(signal3);
    printf("\n%d", output);

    return 0;
}