//
// Created by 27775 on 2023/10/30.
//

#ifndef C2023_CHALLENGE_MENU_H
#define C2023_CHALLENGE_MENU_H

#endif //C2023_CHALLENGE_MENU_H
#include <stdlib.h>
//typedef struct Menu{
  //  char mode;
    //int num;
    //struct Menu*next;
//}Menu;
//Menu list[100];
typedef struct {
    int itemId;
    char itemName[50];
    int quantity;
} Inventory;
Inventory inventory[100];