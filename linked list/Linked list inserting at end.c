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

    void main(){
        
        struct node *p,*q,*x,*first;
        p=(struct node*)malloc(sizeof(struct node));
        printf("Enter the value of First node:");
        scanf("%d",&p->data);
        s=p;
        first=s;
        char ch;


        do
        {
        q=(struct node*)malloc(sizeof(struct node));
        printf("Enter the value of next node:");
        scanf("%d",&q->data);
        clear_stdin();
        p->next=q;
        p=q;
        printf("Press Y for more node:\n");
        ch=getch();
        } while ( ch=='Y'|| ch == 'y');
        p->next=NULL;

        
        x=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data of new node to insert at end:\n");
        scanf("%d",&x->data);
        while (s->next!=NULL)
        {
            s=s->next;
        }
        
        s->next=x;
        x->next=NULL;
        s=first;

        printf("The new linked list is:\t");       

        while (s!=NULL)
        {
            printf("%d\t",s->data);
            s=s->next;
        }
    
    }
    

