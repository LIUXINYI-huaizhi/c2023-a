#include <stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
int main(void) {
    char map[50][50]={
            "######",
            "##o ##",
            "## # #",
            "#  # #",
            "  ## #",
            "#    #",
    };
    int i,x,y,p,q;
    int ch;
    x=1;y=2;p=4;q=0;
    for(i=0;i<6;i++){
        puts(map[i]);
    }
    while(x!=p||y!=q){
        ch=getch();
        if(ch=='s'){
            if(map[x+1][y]!='#'&&x+1<=5){
                map[x][y]=' ';
                x++;
                map[x][y]='o';
            }
        }
        if(ch=='w'){
            if(map[x-1][y]!='#'&&x-1>=0){
                map[x][y]=' ';
                x--;
                map[x][y]='o';
            }
        }
        if(ch=='a'){
            if(map[x][y-1]!='#'&&y-1>=0){
                map[x][y]=' ';
                y--;
                map[x][y]='o';
            }
        }
        if(ch=='d'){
            if(map[x][y+1]!='#'&&y+1<=5){
                map[x][y]=' ';
                y++;
                map[x][y]='o';
            }
        }
        system("cls");
        for(i=0;i<6;i++){
            puts(map[i]);
        }
    }
    system("cls");
    printf("win~\n");
    Sleep(5000);
    return 0;
}