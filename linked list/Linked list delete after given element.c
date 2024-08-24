#include<stdio.h>
#include <stdlib.h>
#include<malloc.h>

    struct  node
    {
        int data;
       struct node * next;
    };
    struct node*s;

    void clear_stdin()
    {
        int c;
        while((c = getchar()) != EOF && c != '\n');
    }

void main() {
    struct node *p,*q,*first;
    char ch;
    
    p=(struct node *)malloc(sizeof(struct node));
    printf("Enter first node data :\n");
    scanf("%d",&p->data);
    s=p;              // s points to the first node
    first =s ;       // first keeps track of the start of the list
    do{
        q=(struct node *)malloc(sizeof(struct node));
        printf("Enter next node data :\n");
        scanf("%d",&q->data);
        p->next=q;
        p=q;
        printf("press y for next node :\n");
        ch=getch();
    }while(ch=='y'|| ch=='Y');
    p->next=NULL;

    int key;
    printf("Enter data of node to delete :\n");
    scanf("%d",&key);

    while(s->data!=key){
        p=s;
        s=s->next;
    }
    p->next=s->next;
    free(s);

    s=first;

    printf("The linked list after deletion of given element:\n");
    while(s!=NULL){
        printf(" %d \t",s->data);
        s=s->next;
    }
}