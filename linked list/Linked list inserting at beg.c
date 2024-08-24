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
        
        struct node *p,*q,*x;
        p=(struct node*)malloc(sizeof(struct node));
        printf("Enter the value of First node:");
        scanf("%d",&p->data);
        s=p;
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
        ch=getchar();
        } while ( ch=='Y'|| ch == 'y');
        p->next=NULL;

        x=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data of new node to insert at beginning:\n");
        scanf("%d",&x->data);
        x->next=s;
        s=x;

        printf("The new linked list is:\t");       

        while (s!=NULL)
        {
            printf("%d\n",s->data);
            s=s->next;
        }
    
    }
    

