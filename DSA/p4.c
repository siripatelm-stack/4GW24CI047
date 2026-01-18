#include <stdio.h>
#include<stdlib.h>
void evaluate();
void push (char item);
char pop();
int prec(char);
char infix[30],postfix[30],stack[30];
int top =-1;
void evaluate()
{
    int i=0,j=0;
    char symbol,temp;
    push('#');
    for (i=0;infix[i] !='\0';i++)
    {
        symbol=infix[i];
        switch (symbol)
        {
            case '(':
                push(symbol);
                break;
            case ')':
                temp =pop();
                while(temp!= '(')
                {
                    postfix[j]=temp;
                    j++;
                    temp =pop();
                }
                break;
                case '+':
                case '-':
                case '*':
                case '/':
                case '^':
                case '$':
                while(prec(stack[top])>=prec(symbol))
                {
                    temp =pop();
                    postfix[j]=temp;
                    j++;
                }
                push (symbol);
                break;
                default:
                    postfix[j]=symbol;
                    j++;
        }      
    }
    while(top>0)
    {
        temp=pop();
        postfix[j]=temp;
        j++;
    }
    postfix[j]='\0';
}
void push(char item){
    top =top+1;
    stack[top]=item;
}
char pop(){
    char item;
    item=stack[top];
    top =top -1;
    return item;
}
int prec(char symbol){
    int p;
    switch (symbol){
        case '#':
            p=-1;
            break;
        case '(':
        case ')':
            p=0;
            break;
        case '+':
        case '-':
            p=1;
            break;
        case '*':
        case '/':
        case '%':
            p=2;
            break;
        case '^':
        case '$':
            p=3;
            break;
    }
    return p;
}

void main(){
    printf("\nEnter the valid infix expression :");
    scanf("%s",infix);
    evaluate();
    printf("\nThe enter infix expression is: %s \n",infix);
    printf("\nThe corresponding postfix expression: %s\n",postfix);
}