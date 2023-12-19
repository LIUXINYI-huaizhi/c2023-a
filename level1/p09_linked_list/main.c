#include <stdio.h>

typedef struct Link{
    int data;
    struct Link *next;
}Linklist;
int main() {
    Linklist a,b,c,*head,*p;
    a.data=b.data=c.data=0;
    a.next=&b;
    b.next=&c;
    c.next=NULL;
    head=&a;
    p=head;
    do{
        scanf("%d",&p->data);
        p=p->next;
    } while (p!=NULL);//value
    p=head;
    Linklist *temp,*n;
    n=p->next;
    head->next=NULL;
    do{
        temp=p;
        p=n;
        n=p->next;
        p->next=temp;
    } while (n!=NULL);//反序
   head=p;
    int flag=0,i=1;
   while(p!=NULL){
       if(p->data==5){
           flag=1;
           break;
       }
       i++;
       p=p->next;
   }
   if(flag==1)printf("%d",i);
   else printf("-1");//找第一个
  i=1;flag=0;p=p->next;
    while(p!=NULL){
        if(p->data==5){
            flag=1;
            break;
        }
        i++;
        p=p->next;
    }
    if(flag==1)printf("%d",i);
    else printf("-1");//找下一个

    //return 0;
    return (int)head;
}