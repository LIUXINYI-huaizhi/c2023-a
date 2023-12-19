#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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
    char temp[3];
    scanf("%s",temp);
 int flag=1,j=0;
   while(j<=2&&temp[j]!='\0'){
     //  if(!((int)temp[j]>=48&&(int)temp[j]<=57)){
     if(!isdigit((unsigned char )temp[j])){
           flag=0;
           break;
      }
       else j++;
   }
    if(flag==1){
      //  int count=0;
        //while(count<=2&&temp[count]!='\0'){
          //  count++;
        //}
        //int ans=0;
        //for(int l=count;l>=1;l--) {
          //  ans = ans * 10 + ((int) temp[l - 1] - '0');
        //}
        int ans=atoi(temp);
      for (int i=2;i<=ans;i++) {
        if (is_prime(i)) {
            printf("%d,", i);
        }
    }}
   // else printf("error");
    return 0;
}