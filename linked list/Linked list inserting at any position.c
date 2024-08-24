#include<stdio.h>
#include<stdlib.h>
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
    struct node *p,*q,*first,*x,*y;
    char ch;
    p=(struct node *)malloc(sizeof(struct node));
    printf("Enter the value of first node:\n");
    scanf("%d",&p->data);
    s=p;              // s points to the first node
    first =s ;       // first keeps track of the start of the list
    do{
        q=(struct node *)malloc(sizeof(struct node));
        printf("Enter the value of next node data :\n");
        scanf("%d",&q->data);
        p->next=q;
        p=q;
        printf("press y for next node :\n");
        ch=getch();
    }while(ch=='y'|| ch=='Y');
    p->next=NULL;

    // Insert a node after key
    int key;
    printf("Enter the element after which you want to add element:\n");
    scanf("%d",&key);
   
    while(s->data!=key){
        s=s->next;
    }

    if(s->data ==key){
        
        x=(struct node *)malloc(sizeof(struct node));
        printf("Enter node data to insert after %d :\n",key);
        scanf("%d",&x->data);
        y=s->next;
        s->next=x;
        x->next=y;
        s=first;
    }else{
        printf("data not found");
    }

    printf("The new linked list is:");
    while(s!=NULL){
        printf("%d \t",s->data);
        s=s->next;
    }
}