#include<stdio.h>
#include<stdlib.h>
#define MAX 6

char queue[MAX];
int front =-1,rear=-1;
//function prototypes
void insert(char);
char delete();
void display();
void demonstrateOverflow();
void demonstrateUnderflow();


void insert(char value){
    //Check Overflow 
    if ((front == 0 && rear ==MAX-1)||(rear+1)%MAX== front)
    {
        printf("Circular Queue Overflow! Cannot insert %d ->\n",value);
        return;
    }
    
    //Insert into empty queue
    if (front == -1)
        front=rear=0;
    else
        rear =(rear+1)% MAX;

    queue[rear]=value;
    printf("%d inserted.\n",value);
}

char delete()
{
    char value;
    //Underflow 
    if (front == -1)
    {
        printf("Circular Queue Underflow! Cannot delete.\n");
        return '\0';
    }
    value =queue[front];

    //if queue becomes empty
    if (front ==rear)
        front =rear=-1;
    else
        front =(front +1) % MAX ;
    return value ;
}

void display()
{
    if (front ==-1)
    {
        printf("Circular Queue is empty.\n");
        return ;
    }
    printf("Circular Queue Elements: ");
    int i =front ;
    while(1)
    {
        printf("%d ->",queue[i]);
        if(i==rear)
            break;
        i=(i+1)%MAX;
    }
    printf("%d",queue[0]);
    printf("\n");
}
void demonstrateOverflow()
{
    /*Check if queue is full using the correct circular queue
    condition */
    if((rear+1)%MAX==front)
    {
        printf("Overflow occurs! Cannot add a new element.\n");
    }
    else{
        printf("Queue is not full yet.You can insert.\n");
    }
}
void demonstrateUnderflow()
{
    /*Check if queue is empty*/
    if (front==-1)
    {
        printf("Underflow occurs!Cannot remove an element.\n");
    }
    else{
        printf("Queue is not empty.You can delete an element.\n");
    }
}
int main()
{
    int choice;
    char value;
    while (1)
    {
        printf("\n-----CIRCULAR QUEUE MENU-----\n");
        printf("1. Insert an element\n2. Delete an element\n3. Demonstrate Overflow and Underflow\n4. Display Queue\n5. Exit\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter charcter to insert: ");
                scanf("%d",&value);
                insert(value);
                break;

            case 2:
                value=delete();
                if (value!='\0')
                    printf("Deleted: %d ->\n",value);
                break;

            case 3:
                demonstrateOverflow();
                demonstrateUnderflow();
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default: printf("Invalid choice! Try agian.\n");
        }
    }
}