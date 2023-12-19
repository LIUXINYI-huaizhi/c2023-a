#include <stdio.h>
#include<time.h>
int is_prime(int n){
    if(n<=1){
        return 0;
    }
    for (int i =2;i *i <=n;i++){
        if (n%i==0){
            return 0;
        }
    }
    return 1;
}

int main() {
    clock_t start ,end;
    double result;
    start=clock();
    for (int i=2;i<=1000;i++) {
        if (is_prime(i)) {
            printf("%d", i);
        }
    }
    end=clock();
    result=(double)end-start/CLOCKS_PER_SEC;
    printf("计算总时间为%f\n",result);
    return 0;
}