
#include "raylib.h"
#include "judge.h"
#include "evaluate.h"
#include "search.h"
#include <stdlib.h>
#define GRID_SIZE 16
#define GRID_STEP 50
#define gridOriginX 0
#define gridOriginY 0
#define  DEPTH 6
typedef struct Node{
    int value;//叶节点则当前值 MAX节点则最大 MIN节点则最小
    int depth;//当前深度
    int x ;
    int y;
    struct Node* father;
    struct Node* children;
}Node;

int grid[GRID_SIZE][GRID_SIZE] = {0};
int count(){
    int count=0;
    for (int i = 1; i <GRID_SIZE; i++) {
        for (int j = 1; j < GRID_SIZE; j++) {
            if(grid[i][j]==0){
                count++;
            }}}
    return count;
}

int Position(int a) {
    if (a>GRID_STEP*15+GRID_STEP/2||a<GRID_STEP-GRID_STEP/2){
        DrawText("over the checkerboard",10,10,20,WHITE);
        return 0;
    }
    else if (a % GRID_STEP > GRID_STEP / 2)
    {
        a = a / GRID_STEP + 1;
    }
    else
    {a = a / GRID_STEP;}
    return a;
}//确定落子位置
struct vector Down_Black(){
    int flag=0;vector position={0,0};
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        int x = Position(GetMouseX());
        int y = Position(GetMouseY());
        if (grid[x][y] != 1 && x != 0 && y != 0) {
            grid[x][y] = 1;
            position.x=x;
            position.y=y;
        }
    }
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == 1) {
                DrawCircle(i * GRID_STEP, j * GRID_STEP, 25, BLACK);

            }
        }
    }//玩家落子

    //}
    return position;
}
int value_combine(){
    int value=0;
    for(int i=1;i<=15;i++){
        for(int j=1;j<=15;j++){
            if(j+4<=15){
                int a[5]={grid[i][j],grid[i][j+1],grid[i][j+2],grid[i][j+3],grid[i][j+4]};
                value+= evaluate(a);
            }//横向
            if(i+4<=15){
                int a[5]={grid[i][j],grid[i+1][j],grid[i+2][j],grid[i+3][j],grid[i+4][j]};
                value+= evaluate(a);
            }//纵向
            if(j+4<=15&&i+4<=15){
                int a[5]={grid[i][j],grid[i+1][j+1],grid[i+2][j+2],grid[i+3][j+3],grid[i+4][j+4]};
                value+= evaluate(a);
            }//正对角
            if(j-4>=1&&i+4<=15){
                int a[5]={grid[i][j],grid[i+1][j-1],grid[i+2][j-2],grid[i+3][j-3],grid[i+4][j-4]};
                value+= evaluate(a);
            }//副对角
        }
    }
    return value;
}//估值
void checkerboard(){
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            DrawRectangleLines(gridOriginX + i * GRID_STEP, gridOriginY + j *GRID_STEP,
                               (i + 1) *GRID_STEP, (j + 1) * GRID_STEP, WHITE);
        }
    }
}//画棋盘
void blank(){
    for (int i = 1; i <GRID_SIZE; i++) {
        for (int j = 1; j < GRID_SIZE; j++) {
            if(grid[i][j]==3){
                grid[i][j]=0;
            }}}
}
//清空预测的棋盘
bool is_alpha_beta_cut(Node*node) {
    if(node->depth/2==1){
        if(node->value>node->father->value){
            return true;//被砍
        } else{
            return false;
        }
    } else{
        if(node->value<node->father->value){
            return  true;
        } else{
            return false;
        }
    }
}
void update_value_from_node(Node* node){
    if(node->depth==1){
        return;
    }
    else{
        if(node->depth/2==1){
            if(node->value<node->father->value){
                node->father->value=node->value;
            } else{
                return;
            }

        }
        else{
            if(node->value>node->father->value){
                node->father->value=node->value;
            }
            else{
                return;}
        }
        update_value_from_node(node->father);
    }
}
void expand_children(Node* node){
    if(node->depth==DEPTH){
        node->value=value_combine();
        update_value_from_node(node);
    }
    else{
        if(is_alpha_beta_cut(node)){
            return;
        }
        if(node->depth/2==1){//MAX层
            grid[node->x][node->y]=2;}
        else{
            grid[node->x][node->y]=1;
        }
        while(count()!=0){
            Node *children=(Node*) malloc(sizeof (Node));
            children->depth=node->depth+1;
            if((node->depth+1)/2==0){
                children->value=-1000000000;
            }
            else{
                children->value=100000000;
            }
            children->father=node;
            node->children=children;
            vector tem_pos= search_blank(grid);
            children->x=tem_pos.x;children->y=tem_pos.y;
            expand_children(children);
        }
        blank();
        grid[node->x][node->y]=0;
    }
}
vector set_next_pos(){
    int c=count();vector next_pos={0,0};
    Node *node_list=(Node*)malloc(c*sizeof(Node));//寻找所有的root并开辟空间
    for(int i=0;i<c;i++){
        node_list[i].depth=1;
        node_list[i].value=-1000000000;
        vector tem_pos=search_blank(grid);
        node_list[i].x=tem_pos.x;
        node_list[i].y=tem_pos.y;
        expand_children(&node_list[i]);
    }
    blank();
    int Max=node_list[0].value;
    for(int i=1;i<c;i++){
        if(node_list[i].value>Max){
            Max=node_list[i].value;
            next_pos.x=node_list[i].x;
            next_pos.y=node_list[i].y;
        }
    }
    return next_pos;
}//最优解
int game(int position_x,int position_y){//最新位置 对ai而言的玩家最新位置
    int flag=1;
    if(gobang_judge(position_x,position_y,grid,'B')){
        flag=2;
            return flag;
    }
    else{
        if(count()!=0){
            vector next_position=set_next_pos();
            DrawCircle(next_position.x* GRID_STEP,next_position.y* GRID_STEP,25,WHITE);
            if(gobang_judge(position_x,position_y,grid,'W')) {
                flag=3;
                return flag;
            }
        }
        else{
            flag=4;
            return flag;
        }
    }
    return flag;
}//主游戏
int main() {
    InitWindow(800, 800, "gobang");
    SetTargetFPS(60);
    int flag=1;
    while (!WindowShouldClose()) {
        BeginDrawing();
        {
            ClearBackground(BROWN);
            checkerboard();//画棋盘
            vector Black=Down_Black();//*
            if(Black.x!=0&&Black.y!=0)
            {flag=game(Black.x,Black.y);}
            if(flag==2){
                DrawText("YOU WIN!",350,350,100,WHITE);
                WaitTime(5);
                EndDrawing();
                CloseWindow();
            }
            if(flag==3){
                DrawText("GAME OVER", 350, 350, 100, WHITE);
                WaitTime(5);
                EndDrawing();
                CloseWindow();
            }
            if(flag==4){
                DrawText("NO WINNER", 350, 350, 100, WHITE);
                WaitTime(5);
                EndDrawing();
                CloseWindow();
            }
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}