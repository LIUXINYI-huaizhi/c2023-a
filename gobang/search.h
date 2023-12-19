//
// Created by 27775 on 2023/12/12.
//

#ifndef GOBANG_SEARCH_H
#define GOBANG_SEARCH_H
#define GRID_SIZE 16
#endif //GOBANG_SEARCH_H
typedef struct vector{
    int x;
    int y;
}vector;

struct vector search_blank(int grid[GRID_SIZE][GRID_SIZE]);