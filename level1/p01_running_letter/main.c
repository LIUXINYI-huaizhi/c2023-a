#include <stdio.h>
#include <windows.h>
#include<stdlib.h>
#define WIDTH 80
#define HEIGHT 25
void print_letter(char letter,int x,int y){
    COORD coord={x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
    putchar(letter);
}
int main() {
    char letter = 'D';
    int x = 0, y = HEIGHT/2;
    int flag = 0;
    while (1) {
        if (x < WIDTH - 1&& flag ==0) {
            system("cls");
            print_letter(letter, x, y);
            x++;
            Sleep(100);
        }else if(x>=1&&flag == 1 ){
            system("cls");
            print_letter(letter, x, y);
            x--;
            Sleep(100);
        }
        if (x==WIDTH  && flag==0){
            system("cls");
            print_letter(letter, x, y);
            x--;
            flag =1;
            Sleep(100);
        }
        fflush(stdout);
        Sleep(100);
    }
}



