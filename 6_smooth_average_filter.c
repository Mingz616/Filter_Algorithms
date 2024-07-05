#include <stdio.h>
#include <string.h>
#include <math.h>
/*
@func: 平滑+平均滤波器
@param: original data
@return: smooth filtered data

@param: 1st filtered data
@return: average filtered data
*/

#define FILTER_ROOM 2  //滤波阈值范围
#define N 5

int middleFilter(int *psignal){
    int avg = 0;
    for(int i=0; i<N; i++){
        avg += psignal[i];
    }
    avg = avg / N;

    return avg;
}

int smoothFilter(int inputValue, int lastValue){
    int output;
    // 1. 如果新旧数值差值大于阈值范围，则开始滤波处理
    if( abs(inputValue - lastValue) > FILTER_ROOM){
        // 2. 如果差值为正，则输出信号上升阈值的一半
        if( (inputValue-lastValue) > 0 ){
            output = lastValue + FILTER_ROOM/2;
        // 3. 如果差值为负，则输出信号下降阈值的一半
        } else {
            output = lastValue - FILTER_ROOM/2;
        }
    // 4. 如果在阈值范围内，则输出新采集的数值
    } else {
        output = inputValue;
    }

    return output;
}

int avgFilter(int *psignal){
    int output;
    int referenceValue = psignal[0];    //参考的初值
    int fsignal[N] = {0};               //创建一个列表为了保存smooth filter后的数据

    //滑窗滤波开始，并保存滤波后的数据进入新的列表中
    for(int i=0; i<N; i++){
        int outputValue = smoothFilter(psignal[i], referenceValue);
        fsignal[i] = outputValue;
        // printf("Input:%d\tOutput:%d\n", psignal[i], outputValue);
        referenceValue = outputValue;    //更新参考值
    }
    //将滑窗滤波的结果，送到平均值滤波器中处理
    output = middleFilter(fsignal);

    return output;
}

int main(){
    int signal1[] = {1,5,2,4,3};
    int signal2[] = {6,7,10,8,9};
    int signal3[] = {13,12,11,15,14};
    
    int output;
    output = avgFilter(signal1);
    printf("%d\t", output);
    output = avgFilter(signal2);
    printf("%d\t", output);
    output = avgFilter(signal3);
    printf("%d\t", output);

    return 0;
}