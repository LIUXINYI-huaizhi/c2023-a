#include <stdio.h>
#include <string.h>
void encrypt(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        str[i] = ((str[i] - 'a' + 1) % 26) + 'a';
    }
}
void decrypt(char *str){
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        str[i] = ((str[i] - 'a' - 1) % 26) + 'a';
    }
}
int main() {
    char str_1[100];char str_2[100];
    printf("请输入要加密的字符串：");
    scanf("%s", str_1);
    encrypt(str_1);
    printf("加密后的字符串为：%s\n", str_1);
    printf("请输入要解密的字符串：");
    scanf("%s", str_2);
   decrypt(str_2);
    printf("加密后的字符串为：%s\n", str_2);
    return 0;
}
