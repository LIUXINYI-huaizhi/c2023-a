#include <stdio.h>
#include <conio.h>
#include <process.h>
#include <synchapi.h>
#include "map.h"
//#include "the_process.h"
int process(int n,int m,int x,int y,int p,int q,char map[50][50]){
    int i;
    int step=0;
    char ch;
    for(i=0;i<8;i++){
        puts(map[i]);
    }
    while(n!=p||m!=q){
        ch=getch();step++;
        if(ch=='s'){
            if(map[x+2][y]!='#'&&x+2<=7&&map[x+1][y]=='o'){
                map[x+1][y]=map[x][y]=' ';
                x++;n=x+1;
                map[x][y]='a';map[n][m]='o';
            }
            else if(map[x+1][y]!='#'&&x+1<=7&&map[x+1][y]!='o'){
                map[x][y]=' ';
                x++;
                map[x][y]='a';
            }
        }
        if(ch=='w'){
            if(map[x-2][y]!='#'&&x-2>=0&&map[x-1][y]=='o'){
                map[x-1][y]=map[x][y]=' ';
                x--;n=x-1;
                map[x][y]='a';map[n][m]='o';
            }
            else if(map[x-1][y]!='#'&&x-1>=0&&map[x-1][y]!='o'){
                map[x][y]=' ';
                x--;
                map[x][y]='a';
            }
        }
        if(ch=='a'){
            if(map[x][y-2]!='#'&&y-2>=0&&map[x][y-1]=='o'){
                map[x][y-1]=map[x][y]=' ';
                y--;m=y-1;
                map[x][y]='a';map[n][m]='o';
            }
            else if(map[x][y-1]!='#'&&y-1>=0&&map[x][y-1]!='o'){
                map[x][y]=' ';
                y--;
                map[x][y]='a';
            }
        }
        if(ch=='d'){
            if(map[x][y+2]!='#'&&y+2<=7&&map[x][y+1]=='o'){
                map[x][y+1]=map[x][y]=' ';
                y++;m=y+1;
                map[x][y]='a';map[n][m]='o';
            }
            else if(map[x][y+1]!='#'&&y+1<=7&&map[x][y+1]!='o'){
                map[x][y]=' ';
                y++;
                map[x][y]='a';
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
    return step;
}
int stop;int ge;int f=1;
int i,x,y,p,q,n,m;
//int s_1=0,s_3;
int main(void) {
    stop=1;
    while (f == 1){
        if (stop == 1) {
            for (i = 0; i < 6; i++) {
                puts(map_1[i]);
            }
            x = x_1;
            y = y_1;
            p = p_1;
            q = q_1, n = n_1, m = m_1;

            int step_1=process(n, m, x, y, p, q, map_1);
            printf("congratulations!one more or stop?print m or s");
            ge = getch();
            if (ge == 'm') {
                stop = 2;
                break;
            } else {
                f = 0;
                printf("game over");
                break;
            }

        }

        if (stop == 2) {
            for (i = 0; i < 6; i++) {
                puts(map_2[i]);
            }
            x = x_2;
            y = y_2;
            p = p_2;
            q = q_2, n = n_2, m = m_2;
            int step_2=process(n, m, x, y, p, q, map_2);
                printf("congratulations!one more or stop?print m or s");
                ge = getch();
                if (ge == 'm') {
                    stop = 3;
                    break;
                }
                else{
                    f=0;
                    printf("game over");
                }

        }
         if (stop == 3) {
        for (i = 0; i < 6; i++) {
            puts(map_3[i]);
        }
        x = x_3;
        y = y_3;
        p = p_3;
        q = q_3, n = n_3, m = m_3;
        int step_3=process(n, m, x, y, p, q, map_3);
        printf("Unbelievable!");
        stop=0;

    }
    }
    return 0;
    }
 //  system("cls");
   // printf("win~\n");
    //Sleep(5000);

