#include <stdio.h>
void HANOTA(int n,char now,char tran,char target){
    if(n==1){
        printf("%c->%c\n",now,target);
    } else{
        HANOTA(n-1,now,target,tran);
        printf("%c->%c\n",now,target);
        HANOTA(n-1,tran,now,target);
    }
}

int main() {
   int n;
   printf("请输入层数：\n");
   scanf("%d",&n);
    HANOTA(n,'A','B','C');
}