//
// Created by 27775 on 2023/12/12.
//

#include "search.h"
//typedef struct vector{
 //   int x;
   // int y;
//}vector;
vector search_blank(int grid[GRID_SIZE][GRID_SIZE]){
    vector position={0,0};
    for (int i = 1; i <GRID_SIZE; i++) {
        for (int j = 1; j < GRID_SIZE; j++) {
            if(grid[i][j]==0){
                position.x=i;
                position.y=j;
                grid[i][j]=3;//标记//最后要清空
                break;
            }
        }
    }
    return position;
}