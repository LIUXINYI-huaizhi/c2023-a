//
// Created by 27775 on 2023/12/5.
//

#include "judge.h"
#define GRID_SIZE 16
bool gobang_judge(int position_X,int position_Y,int grid[GRID_SIZE][GRID_SIZE],char color){
    int count;int c;
    int x=position_X;int y=position_Y;
    if(color=='B'){
        c=1;
    }
    else if(color=='W'){
        c=2;
    }

    //横向
    while(x>=1&&x<=15){
        struct left_right{
            int left_count;
            int right_count;
        };struct left_right Count={0,0};
        while(x-1>=1&&Count.left_count<5){
            if(grid[x-1][y]==c){
                Count.left_count+=1;
                x=x-1;
            }
            else {
                break;
            }
        }//左查找
        x=position_X;y=position_Y;
        while (x+1<=15&&Count.right_count<5){
            if(grid[x+1][y]==c){
                Count.right_count+=1;
                x=x+1;
            }
            else{
                break;
            }
        }//右查找

        count=Count.right_count+Count.left_count;
        if(count>=5){
            return true;
        } else break;
    }
    //垂直
    x=position_X;y=position_Y;
    while(y>=1&&y<=15){
        struct up_down{
            int up_count;
            int down_count;
        };struct up_down Count={0,0};
        while(y-1>=1&&Count.up_count<5){
            if(grid[x][y-1]==c){
                Count.up_count+=1;
                y=y-1;
            }
            else{
                break;
            }
        }//上查找
        x=position_X;y=position_Y;
        while (y+1<=15&&Count.down_count<5){
            if(grid[x][y+1]==c){
                Count.down_count+=1;
                y=y+1;
            }
            else{
                break;
            }
        }//下查找
        count=Count.up_count+Count.down_count;
        if(count>=5){
            return true;
        }
        else break;
    }
    //正斜向
    x=position_X;y=position_Y;
    while(y>=1&&y<=15&&x>=1&&x<=15){
        struct slant_1{
            int up_count;
            int down_count;
        };struct slant_1 Count={0,0};
        while(y-1>=1&&x+1<=15&&Count.up_count<5){
            if(grid[x+1][y-1]==c){
                Count.up_count+=1;
                x=x+1;
                y=y-1;
            }
            else break;
        }//斜右上查找
        x=position_X;y=position_Y;
        while (y+1<=15&&x-1>=1&&Count.down_count<5){
            if(grid[x+1][y]==c){
                Count.down_count+=1;
                y=y+1;
                x=x-1;
            }
            else break;
        }//斜左下查找
        count=Count.up_count+Count.down_count;
        if(count>=5){
            return true;
        } else
            break;
    }
    //副斜向
    x=position_X;y=position_Y;
    while(y>=1&&y<=15&&x>=1&&x<=15){
        struct slant_2{
            int up_count;
            int down_count;
        };struct slant_2 Count={0,0};
        while(x-1>=1&&y-1>=1&&Count.up_count<5){
            if(grid[x-1][y-1]==c){
                Count.up_count+=1;
                x=x-1;
                y=y-1;
            }
            else break;
        }//斜左上查找
        x=position_X;y=position_Y;
        while (y+1<=15&&x+1<=15&&Count.down_count<5){
            if(grid[x+1][y+1]==c){
                Count.down_count+=1;
                y=y+1;
                x=x+1;
            }
            else break;
        }//斜右下查找
        count=Count.up_count+Count.down_count;
        if(count>=5){
            return true;
        } else break;
    }
    return false;
}