#include <stdio.h>
// Created by 27775 on 2023/10/10.
//
int main() {

    int name[5] = {5, 6, 1, 8, 2};
    int len = sizeof(name) / sizeof(name[0]);
    for (int k = 0; k < len; k++) {
        printf("%d", name[k]);
    }
    for (int n = 1; n <= len-1; n++) {
        int index;
        int trans=name[n];index=n;
        for(int i=n;i>0;i--){
            if(trans<name[i-1]){
                name[i]=name[i-1];
               index=i-1;
            }
            name[index]=trans;
        }

    }
    for (int m = 0; m < len; m++) {
        printf("%d", name[m]);
    }
    return 0;}
