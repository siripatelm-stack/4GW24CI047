#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5

int stack[MAX];
int top=-1;

void push (int);
int pop();
void display();
void checkPalindrome();
void isOverflow();
void isUnderflow();
int main(){
    int choice , value;
    while(1){
        printf("\n----STACK MENU----\n");
        printf("1.Push an element\n");
        printf("2.Pop an element\n");
        printf("3.Check Palindrome using Stack\n");
        printf("4.Demonstrate Overflow /Underflow\n");
        printf("5.Display stack\n");
        printf("6.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter value to push:");
                scanf("%d",&value);
                push (value);
                break;
            case 2:
                value=pop();
                if(value!=-1)
                {
                    printf("Poped Element:%d\n",value);
                }
                break;
            case 3:
                checkPalindrome();
                break;
            case 4:
                isOverflow();
                isUnderflow();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid Choice !Try again.\n");
        }
    }
    return 0;
}
void push (int value)
{
    if(top ==MAX-1)
    {
        printf("Stack Overflow!Cannot push %d\n",value);
        return;
    }
    stack[++top]=value;
    printf("%d pushed to stack",value);
}
int pop(){
    if(top ==-1)
    {
        printf("Stack Underflow!Nothing to pop.\n");
        return -1;
    }
    return stack[top--];
}
void display(){
    if (top ==-1){
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements are:\n");
    for (int i =0;i<=top;i++)
    {
        printf("%d\n",stack[i]);
    }
    printf("\n");
}
void checkPalindrome(){
    char str[50];
    char rev[50];
    int i;
    printf("Enter a string to check palindrome");
    scanf("%s",str);
    
    int len=strlen(str);
    int tempTop=-1;
    char tempStack[50];

    for (i=0;i<len;i++)
        tempStack[++tempTop]=str[i];
    for(i=0;i<len;i++)
        rev[i]=tempStack[tempTop--];
    rev[i]='\0';

    if(strcmp(str,rev)==0)
        printf("The string '%s' is a PALINDROME.\n",str);
    else    
        printf("The string '%s' is NOT a palindrome.\n");
}
void isOverflow()
{
    if(top==MAX-1)
    {
        printf("Overflow occurs!Stack is full");
    }
    else
    {
        printf("No overflow.\n");
    }
}
void isUnderflow(){
    if(top==-1){
        printf("Underflow occurs !Stack is Empty");
    }
    else{
        printf("No underflow");
    }
}