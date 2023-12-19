  #include <stdio.h>
#include "is_prime.h"
 // int is_prime(int n){
   // if(n<=1){
     //   return 0;
    //}
   // for (int i =2;i *i <=n;i++){
     //   if (n%i==0){
       //     return 0;
//        }
  //  }
    //return 1;
//}
int main() {
    int n ;
    printf("请输入一个整数：");
    scanf_s("%d",&n);
    if (is_prime(n)){
        printf("%d是素数\n",n);
    }else{
        printf("%d不是素数\n",n);
    }
    return 0;
}