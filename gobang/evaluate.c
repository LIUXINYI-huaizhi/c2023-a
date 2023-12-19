//
// Created by 27775 on 2023/12/12.
//

#include "evaluate.h"
int evaluate(const int a[5]){
    int evaluate_white=0;int count_0=0,count_1=0,count_2=0;
    for(int i=0;i<5;i++){
        if(a[i]==0||a[i]==3){
            count_0++;
        }
        if(a[i]==1){
            count_1++;
        }
        if(a[i]==2){
            count_2++;
        }
    }
    if(count_1!=0&&count_2!=0){
        evaluate_white=0;
    }
    else if(count_2==1&&count_0==4){
        evaluate_white=1;
    }
    else if(count_2==2&&count_0==3){
        evaluate_white=10;
    }
    else if(count_2==3&&count_0==2){
        evaluate_white=100;
    }
    else if(count_2==4&&count_0==1){
        evaluate_white=10000;
    }
    else if(count_2==5&&count_0==0){
        evaluate_white=1000000;
    }
    else if(count_1==1&&count_0==4){
        evaluate_white=-1;
    }
    else if(count_1==2&&count_0==3){
        evaluate_white=-10;
    }
    else if(count_1==3&&count_0==2){
        if(a[0]==0&&a[4]==0){
            evaluate_white=-2000;
        }
        else evaluate_white=-1000;
    }
    else if(count_1==4&&count_0==1){
        evaluate_white=-100000;
    }
    else if(count_1==5&&count_0==0){
        evaluate_white=-10000000;
    }
    return evaluate_white;
}
