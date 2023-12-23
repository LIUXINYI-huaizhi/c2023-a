
#include"raylib.h"
#include<stdlib.h>
#pragma warning(default: 4996)
#define E 10         //先后手
#define V 10         //位置初始分以及倍率
#define MIN 5
#define MAX 20
long double A = -999999999999999999;
long double B = 999999999999999999;
int ii = 0, jj = 0, xx = 0, yy = 0;    //上一步棋位置
int num = 0;
struct point {
    int state;          //位置的状态    玩家-1,   空位置0,   电脑1
    long double value;        //该点价值分
    long double n_value;        //棋盘的总优势分
};
typedef struct  vector{
    int x;
    int y;
}vector;
void board();	//画棋盘
void regret(struct point p[25][25]);		//悔棋
void begin(struct point p[25][25]);  	//开始
int robot(struct point p[25][25]);		//ai
void over(int x);		//结束界面
void p_assess(struct point p[25][25]);     //估值函数
double assess(struct point p[25][25]);     //局面评估
double deduction(struct point p[25][25], int sex, int depth, long double a, long double b);//剪枝树
int judge(struct point p[25][25]);     //判断输赢
void initialize(struct point p[25][25]);    //清空棋盘
void execute(struct point p[25][25],int x,int y);    //下棋
void grid(struct point p[25][25]);//绘制棋盘
void grid(struct point p[25][25]){
    BeginDrawing();
    for (int i = MIN; i < MAX; i++) {        //重新绘制棋盘
        for (int j = MIN; j < MAX; j++) {
            if (p[i][j].state == -1) {
                    DrawCircle((i + 1-MIN) * 50, (j + 1-MIN) * 50, 20,BLACK);
            }
            if (p[i][j].state == 1) {
                DrawCircle((i + 1-MIN) * 50, (j + 1-MIN) * 50, 20,WHITE);
            }
        }
    }
    EndDrawing();
}
//清空
void initialize(struct point p[25][25])
{
    int i, j;
    num = 0;
    for (i = 0; i < 25; i++)
    {
        for (j = 0; j < 25; j++)
        {
            p[i][j].state = 0;
            p[i][j].value = 0;
            p[i][j].n_value = 0;
        }
    }
}
//判断棋局胜负
int judge(struct point p[25][25])
{
    int i, j, k = 0, x = 0, y = 0, b = 0, q = 0, e = 0;
    for (i = MIN; i < MAX; i++)
    {
        for (j = MIN; j < MAX; j++)
        {
            if (p[i][j].state == 0)
            {
                k++;
                if (k == 0)
                {
                    e = 1;//平局
                }
            }
            if (p[i][j].state)
            {
                for (x = -2; p[i][j].state == p[i][j + x].state && x < 4; x++)     //横
                {
                }
                for (y = -2; p[i][j].state == p[i + y][j].state && y < 4; y++)      //纵
                {
                }
                for (b = -2; p[i][j].state == p[i + b][j + b].state && b < 4; b++)    //斜下
                {
                }
                for (q = -2; p[i][j].state == p[i - q][j + q].state && q < 4; q++)    //斜上
                {
                }
                if (x == 3 || y == 3 || b == 3 || q == 3)
                {
                    if (p[i][j].state == 1)
                    {
                        e = 2; //玩家输
                    }
                    if (p[i][j].state == -1)
                    {
                        e = 3; //玩家赢
                    }
                }
            }
        }
    }
    return e;
}
//绘画棋盘
void board() {
    while (!WindowShouldClose()) {
        BeginDrawing();
        {
            ClearBackground(BROWN);
            for (int i = 50; i <= 750; i += 50)//画棋盘
            {
                DrawLine(i, 50, i, 750, WHITE);
                DrawLine(50, i, 750, i, WHITE);
            }
           DrawText("regret", 770, 200, 15, BLACK);
            DrawText("again", 770, 300, 15, BLACK);
            DrawText("defensive position", 770, 400,15, BLACK);
            DrawText("exit", 770, 500,  15, BLACK);

        }
        EndDrawing();
    }
}
//悔棋
void regret(struct point p[25][25])
{
    board();
    p[ii][jj].state = 0;  //将上一步棋清空
    p[xx][yy].state = 0;
    grid(p);
}
//开局
void begin(struct point p[25][25])//主要函数
{
    vector m;
    int  x, y, i, j;
    board();
    while (1)
    {
        m.x= GetMouseX();
        m.y=GetMouseY();
        x = m.x % 50;
        y = m.y % 50;
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            if (m.x <= 900 && m.y < 250 && m.x >= 800 && m.y > 200)  //悔棋
            {
                regret(p);//悔棋
                continue;
            }
            if (m.x <= 900 && m.y < 350 && m.x >= 800 && m.y > 300)	//重开
            {
                initialize(p);   //清空
                begin(p);
            }
            if (m.x <= 900 && m.y < 450 && m.x >= 800 && m.y > 400)  //后手 防卫
            {
                if (num < 1)
                {
                    robot(p);
                    num++;
                }
            }
            if (m.x <= 900 && m.y < 550 && m.x >= 800 && m.y > 500)  //退出
            {
                CloseWindow();
                exit(0);
            }

            if (x >= 25)   {  //玩家执棋
                m.x = m.x - x + 50;}//精确落子
            else
                m.x = m.x - x;
            if (y >= 25){
                m.y = m.y - y + 50;}
            else
                m.y = m.y - y;
            i = m.x / 50 - 1+ MIN;
            j = m.y / 50 - 1+ MIN;
            if (i < 20 && j < 20)
            {
                if (p[i][j].state==-1)
                    break;
                if (m.x <= 750 && m.y <= 750 && m.x >= 50 && m.y >= 50)
                {
                    ii = i;
                    jj = j;
                    p[i][j].state = -1;
                    grid(p);
                }
                if (judge(p) != 0)
                {
                    WaitTime(1000);
                    over(judge(p));
                }
                robot(p);
                if (judge(p) != 0)
                {
                    WaitTime(1000);
                    over(judge(p));
                }
                num++;
            }
        }
    }
}
//结束界面
void over(int x)
{
    struct point pp[25][25];
    initialize(pp);
    InitWindow(400, 400,"over");
    ClearBackground(WHITE);
    BeginDrawing();{
    if (x == 1)
    {
        DrawText("NO WINNER", 100, 50, 15, BLACK);
    }
    else if (x == 2)
    {
        DrawText("AI WIN", 100, 50, 15, BLACK);
    }
    else if(x==3)
    {
        DrawText("YOU WIN", 100, 50, 15, BLACK);
    }

    DrawText("RETURN", 50, 200, 15, BLACK);
    DrawText("GAME OVER",  80, 300, 15, BLACK);}
    EndDrawing();
    while (true)
    {
        vector n;//鼠标信息
        n.x= GetMouseX();
        n.y=GetMouseY();
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
                if (n.x <= 350 && n.x >= 50 && n.y <= 250 && n.y >= 200)
                    begin(pp);
                if (n.x <= 300 && n.x >= 80 && n.y <= 350 && n.y >= 300)
                {
                    CloseWindow();
                    exit(0);
                }
        }
    }
}
//局面优势评估
double assess(struct point p[25][25])
{
    int i, j;
    p_assess(p);
    long double s_value = 0;
    for (i = MIN; i < MAX; i++)
    {
        for (j = MIN; j < MAX; j++)
        {
            s_value += p[i][j].value;
        }
    }
    return s_value;
}
//某点价值评定
void p_assess(struct point p[25][25])
{
    int i, j, k, m, n, x, y;
    for (i = MIN; i < MAX; i++)
    {
        for (j = MIN; j < MAX; j++)
        {
            if (p[i][j].state == 0)
            {
                p[i][j].value = 0;
            }
            else
            {                                 //8个方向每个价值为10
                long double v1 = V, v2 = V, v3 = V, v4 = V, v5 = V, v6 = V, v7 = V, v8 = V;
                for (x = 0, n = j; p[i][j].state != -p[i][n + 1].state && n + 1 < 20 && x < 4; x++, n++)       //右
                {
                }
                if (x < 4)
                {
                    v1 = 0;    //黑白子同时存在为0
                }
                else {
                    for (k = 0, n = j; p[i][j].state == p[i][n + 1].state && k < 5; k++, n++)       //右
                    {
                        v1 *= V;     //连续分数翻倍
                    }
                }
                for (y = 0, n = j; p[i][j].state != -p[i][n - 1].state && n - 1 > 4 && y < 4; y++, n--)      //左
                {
                }
                if (y < 4)
                {
                    v2 = 0;
                }
                else {
                    for (k = 0, n = j; p[i][j].state == p[i][n - 1].state && k < 5; k++, n--)
                    {
                        v2 *= V;
                    }
                }
                for (x = 0, n = i; p[i][j].state != -p[n + 1][j].state && n + 1 < 20 && x < 5; x++, n++)
                {
                }
                if (x < 4)
                {
                    v3 = 0;
                }
                else {
                    for (k = 0, n = i; p[i][j].state == p[n + 1][j].state && k < 5; k++, n++)
                    {
                        v3 *= V;
                    }
                }
                for (y = 0, n = i; p[i][j].state != -p[n - 1][j].state && n - 1 > 4 && y < 5; y++, n--)
                {
                }
                if (y < 4)
                {
                    v4 = 0;
                }
                else {
                    for (k = 0, n = i; p[i][j].state == p[n - 1][j].state && k < 5; k++, n--)
                    {
                        v4 *= V;
                    }
                }
                for (x = 0, m = i, n = j; p[i][j].state != -p[m - 1][n + 1].state && n + 1 < 20 && m - 1 > 4 && x < 5; x++, m--, n++)
                {
                }
                if (x < 4)
                {
                    v5 = 0;
                }
                else {
                    for (k = 0, m = i, n = j; p[i][j].state == p[m - 1][n + 1].state && k < 5; k++, m--, n++)
                    {
                        v5 *= V;
                    }
                }
                for (y = 0, m = i, n = j; p[i][j].state != -p[m + 1][n - 1].state && m + 1 < 20 && n - 1 > 4 && y < 5; y++, m++, n--)
                {
                }
                if (y < 4)
                {
                    v6 = 0;
                }
                else {
                    for (k = 0, m = i, n = j; p[i][j].state == p[m + 1][n - 1].state && k < 5; k++, m++, n--)
                    {
                        v6 *= V;
                    }
                }

                for (x = 0, m = i, n = j; p[i][j].state != -p[m - 1][n - 1].state && n - 1 > 4 && m - 1 > 4 && x < 5; x++, m--, n--)
                {
                }
                if (x < 4)
                {
                    v7 = 0;
                }
                else {
                    for (k = 0, m = i, n = j; p[i][j].state == p[m - 1][n - 1].state && k < 5; k++, m--, n--)
                    {
                        v7 *= V;
                    }
                }
                for (y = 0, m = i, n = j; p[i][j].state != -p[m + 1][n + 1].state && n + 1 < 20 && m + 1 < 20 && y < 5; y++, m++, n++)
                {
                }
                if (y < 4)
                {
                    v8 = 0;
                }
                else {
                    for (k = 0, m = i, n = j; p[i][j].state == p[m + 1][n + 1].state && k < 5; k++, m++, n++)
                    {
                        v8 *= V;
                    }
                }
                p[i][j].value = v1 + v2 + v3 + v4 + v5 + v6 + v7 + v8 + 0.1 * (15 - abs(i - 12) - abs(j - 12));    //加上距离中心优势分
                if (p[i][j].state == -1)    //玩家棋子为负分
                {
                    p[i][j].value = -p[i][j].value * E;       //E为偏向防守程度
                }
            }
        }
    }
}
//剪枝
double deduction(struct point p[25][25], int sex, int depth, long double a, long double b)
{
    int m, n,i, j, t = 0,br=0;
    long double va = 0;
    if (depth == 0 || judge(p) != 0)   //达到深度或棋局结束
    {
        return assess(p);       //递归出口，返回分数
    }
    else if (sex % 2 == 1)     //玩家回合
    {
        for (m = MIN; m < MAX; m++)
        {
            if (br == 1) {   //b剪枝
                break;
            }
            for (n = MIN; n < MAX; n++)
            {
                if (p[m][n].state == 0 )   //为空
                {
                    if (num < 80) {
                        t = 0;
                        for (i = -1; i < 2; i++) {
                            for (j = -1; j < 2; j++) {
                                if (p[i + m][j + n].state != 0) {
                                    t++;     //偏僻点剪枝
                                }
                            }
                        }
                    }
                    else {
                        t = 1;
                    }
                    if (t == 0)   //偏僻
                    {
                        va = B;
                    }
                    else {
                        p[m][n].state = -1;    //棋下在这个地方
                        va = deduction(p, sex + 1, depth - 1, a, b);
                        p[m][n].state = 0;      //撤回
                    }
                    if (va < b)    //找最小值
                    {
                        b = va;
                    }
                    if (b < a)
                    {
                        break;    //b剪枝
                        br = 1;
                    }
                }
            }
        }
        return b; //返回分数
    }
    else if (sex % 2 == 0)     //电脑回合
    {
        for (m = MIN; m < MAX; m++)
        {
            if (br == 1) {   //a剪枝
                break;
            }
            for (n = MIN; n < MAX; n++)
            {
                if (p[m][n].state == 0 )     //为空
                {
                    if (num < 80) {
                        t = 0;
                        for (i = -1; i < 2; i++) {
                            for (j = -1; j < 2; j++) {
                                if (p[i + m][j + n].state != 0) {
                                    t++;     //偏僻点剪枝
                                }
                            }
                        }
                    }
                    else {
                        t = 1;
                    }
                    if (t == 0)   //偏僻
                    {
                        va = A;
                    }
                    else {
                        p[m][n].state = 1;     //棋下在这个地方
                        va = deduction(p, sex + 1, depth - 1, a, b);
                        p[m][n].state = 0;     //撤回
                    }
                    if (va > a)    //找最大值
                    {
                        a = va;
                    }
                    if (b < a)
                    {
                        break;    //a剪枝
                        br = 1;
                    }
                }
            }
        }
        return a;//返回分数
    }
    return 0;
}
//电脑执棋
int robot(struct point p[25][25])
{
    int i, j, x = 12, y = 12,m, n, t = 0;
    long double v = -999999999999999999;
    for (i = MIN; i < MAX; i++)        //寻找最佳落子点
    {
        for (j = MIN; j < MAX; j++)
        {
            if (p[i][j].state == 0 )      //为空
            {
                t = 0;
                for (m = -1; m < 2; m++) {
                    for (n = -1; n < 2; n++) {
                        if (p[i + m][j + n].state != 0) {
                            t++;     //剪枝
                        }
                    }
                }
                if (t != 0)   //不偏僻
                {
                    p[i][j].state = 1;    //假设电脑下在这里
                    if (judge(p) == 2)
                    {
                        xx = i;
                        yy = j;    //记录当前位置
                        p[i][j].state = 1;
                        grid(p);  //下棋
                        return 0;
                    }
                    p[i][j].n_value = deduction(p, 1, 2, A, B);
                    p[i][j].state = 0;    //撤回
                    if (p[i][j].n_value > v)
                    {
                        v = p[i][j].n_value;    //找最大值
                        x = i;
                        y = j;     //获取坐标
                    }
                }
            }
        }
    }
    xx=x;
    yy=y;
    p[x][y].state=1;
    grid(p);
    return 0;
}

int main()
{
    InitWindow(800, 800, "gobang");
    SetTargetFPS(60);
    struct point p[25][25];
    initialize(p);
    begin(p);
    return 0;
}
