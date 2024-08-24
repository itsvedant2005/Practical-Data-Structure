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
        
        struct node *p,*q;
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

        printf("The linked list : \n");                     
        while (s!=NULL)
        {
            printf("%d\n",s->data);
            s=s->next;
        }
    
    }
    

