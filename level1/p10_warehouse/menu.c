//
// Created by 27775 on 2023/10/30.
//
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

    Menu a,b,c;
    a.mode='A';b.mode='B';c.mode='C';
    a.num=5;b.num=4;c.num=6;
    a.next=&b;b.next=&c;c.next=NULL;
