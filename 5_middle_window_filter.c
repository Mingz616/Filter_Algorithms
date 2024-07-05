#include <stdio.h>


#define N 5     //取N个值排序

//滤波处理，冒泡法从小到大排序
void orderB2S(int *psignal){
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
}

//滑窗去极值后，取平均来滤波。
int middleFilter(int *psignal){
    int avg = 0;

    //滑窗数据排序
    orderB2S(psignal);

    //掐头去尾，去掉极值
    for(int i=1; i<N-1; i++){
        avg += psignal[i];
    }
    avg = avg / (N-2);  //取平均值

    return avg;
}

int main(){
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