#include <stdio.h>
// Created by 27775 on 2023/10/10.
//
int main() {

    int name[5] = {5, 6, 1, 8, 2};
    int len = sizeof(name) / sizeof(name[0]);
    for (int k = 0; k < len; k++) {
        printf("%d", name[k]);
    }
    for (int n = 0; n <= len-1; n++) {
        int min=name[n];int area=n;
        for (int i = n; i <= len - 1; i++) {
            if (name[i] < min) {
                min = name[i];area=i;
            }

        }
        for(int k=area;k>=n+1;k--){
            name[k]=name[k-1];
        }
        name[n]=min;
    }
    for (int m = 0; m < len; m++) {
        printf("%d", name[m]);
    }
    return 0;
}//
// Created by 27775 on 2023/10/10.
//
//
// Created by 27775 on 2023/10/10.
//
