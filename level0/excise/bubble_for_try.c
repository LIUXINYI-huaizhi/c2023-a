#include <stdio.h>
int main(){
    printf("输入十个数字");
    int bubble[10];
    for (int i=0;i<=9;i++){
        scanf("%d",&bubble[i]);
    }//输入
    for(int i=8;i>=0;i--) {
        for (int j = i; j <= 8; j++) {
            if (bubble[j] > bubble[j + 1]) {
                int temp = bubble[j + 1];
                bubble[j + 1] = bubble[j];
                bubble[j] = temp;
            }
        }
    }
   for(int i=0;i<=8;i++){
       printf("%d,",bubble[i]);
   }
    printf("%d",bubble[9]);
    return 0;
}
