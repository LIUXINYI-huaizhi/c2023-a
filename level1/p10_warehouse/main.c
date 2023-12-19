#include <stdio.h>
#include <conio.h>

#include "menu.h"
int inventoryCount=0;

FILE*fp;
void displayMenu() {
    printf("\n---- Welcome to the Warehouse Management System ----\n");
    printf("1. Display Inventory\n");
    printf("2. Add Item\n");
    printf("3. Remove Item\n");
    printf("4. Exit\n");
    printf("-------------------------------------------------\n");
    printf("Enter your choice: ");
}
void displayInventory() {
    printf("\n---- Inventory ----\n");
    for (int i = 0; i < inventoryCount; i++) {
        printf("%d. %s - Quantity: %d\n", inventory[i].itemId, inventory[i].itemName, inventory[i].quantity);
    }
}
void addItem() {
    Inventory newItem;
    printf("\n---- Add Item ----\n");
    printf("Enter item ID: ");
    scanf("%d", &newItem.itemId);
    printf("Enter item name: ");
    scanf("%s", newItem.itemName);
    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);
    inventory[inventoryCount++] = newItem;
}
void removeItem() {
    int itemId;
    printf("\n---- Remove Item ----\n");
    printf("Enter the item id of the item you want to remove: ");
    scanf("%d", &itemId);
    for (int i = 0; i < inventoryCount; i++) {
        if (inventory[i].itemId == itemId) {
            for (int j = i; j < inventoryCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            inventoryCount--;
            printf("Item removed.\n");
            return;
        }
    }
    printf("Item not found.\n");
}
int main() {
    fp= fopen("menu.txt","w+");
    while(1){
    displayMenu();
    int d;
   d=getch()-'0';
    if(d==4){
        return -1;
    }
    else{
        if(d==1){
            displayInventory();
        }
        if(d==2){
            addItem();
        } else removeItem();
    }
   } return 0;
}