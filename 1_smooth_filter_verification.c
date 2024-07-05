#include <stdio.h>
#include <math.h>
/*
@func: 平滑滤波 C语言 验证
@param: input value & last value
@return: output value
*/

#define FILTER_ROOM 11  //滤波阈值范围

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

int main(){
    int signal[] = {10,20,33,40,30,20,10};  //33为有干扰信号掺杂
    //设置初值，缺点是滤波信号延迟一位。
    int referenceValue = signal[0];

    for(int i=0;i<sizeof(signal)/sizeof(int); i++){
        int outputValue = smoothFilter(signal[i], referenceValue);
        printf("Input:%d\tOutput:%d\n", signal[i], outputValue);
        referenceValue = outputValue;    //更新参考值
    }

    return 0;
}