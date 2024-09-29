#include <stdio.h>

int stack[100], top, n, x;

// PUSH
void push()
{
    if (top >= n - 1)
    {
        printf("\nStack is overflow\n");
    }
    else
    {
        printf("Enter the value which you want to add in stack: \n");
        scanf("%d", &x);
        top++;
        stack[top] = x;
    }
}

// POP 
void pop()
{
    if (top <= -1)
    {
        printf("\nStack is Underflow\n");
    }
    else
    {
        printf("\nThe poped element is %d\n", stack[top]);
        top--;
    }
}

// PRINT
void print()
{
    if (top >= 0)
    {
        printf("\nThe element in stack\n");
        for (int i = top; i >= 0; i--)
        {
            printf("\t%d", stack[i]);
        }
        printf("\nPress for next choice:-\n");
    }
    else
    {
        printf("\nThe given Stack is empty.\n");
    }
}

int main()
{
    int choice;
    top = -1;
    printf("Enter the size of Stack [Note*(Max size 100)]:-\n");
    scanf("%d", &n);
    printf("Enter which stack operation do you have to perform :-\n");
    printf("1.Push  2.Pop  3.Print  4.Exit\n");
    do
    {
        printf("Enter your choice :-\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            print();
            break;

        case 4:
            printf("You exit succesfully\n");
            break;

        default:
            printf("Please enter a valid number!!\n");
            break;
        }
    } while (choice != 4);

    return 0;
}