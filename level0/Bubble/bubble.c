#include <stdio.h>
// Created by 27775 on 2023/10/10.
//
int main() {

    int name[5] = {5, 6, 1, 8, 2};
    int len = sizeof(name) / sizeof(name[0]);
    int lenth = sizeof(name) / sizeof(name[0]);
    for (int k = 0; k < len; k++) {
        printf("%d", name[k]);
    }
    for (int n = 1; n <= len; n++) {
        int key;
        for (int i = 1; i <= lenth - 1; i++) {
            if (name[i] < name[i - 1]) {
                key = name[i];
                name[i] = name[i - 1];
                name[i - 1] = key;
            }
            lenth--;
        }
    }
    for (int m = 0; m < len; m++) {
        printf("%d", name[m]);
    }
    return 0;
}//
// Created by 27775 on 2023/10/10.
//
