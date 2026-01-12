#include <stdio.h>
#include <stdlib.h>

typedef struct Employee
{
    char SSN[20];
    char Name[50];
    char Dept[30];
    char Designation[30];
    int Sal;
    char PhNo[15];
    struct Employee *prev ,*next;
}Employee;

Employee*head=NULL;
/*Function to create a new node using the Structure Employee as 
data type to return function*/
Employee *createNode()
{
    Employee *newNode =(Employee *)malloc (sizeof(Employee));
    if(!newNode)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    printf("Enter SSN ,Name, Dept, Designation, Salary, Phone :\n");
    scanf("%s %s %s %s %d %s",newNode ->SSN ,newNode->Name
        ,newNode->Dept,newNode->Designation,&newNode->Sal,
        newNode->PhNo);
    newNode->prev=newNode->next=NULL;
    return newNode;
}

void insertEnd(Employee *newNode)
{
    if(head==NULL)
    {
        head=newNode;
        return;
    }
    Employee *temp=head;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=newNode;
    newNode->prev=temp;
}

void insertFront(Employee *newNode)
{
    if(head==NULL)
    {
        head=newNode;
        return;
    }
    newNode->next=head;
    head->prev=newNode;
    head=newNode;
}

void deleteEnd(){
    if(head==NULL)
    {
        printf("List is Empty\n");
        return;
    }
    Employee *temp=head;
    if(temp->next==NULL)
    {
        free(temp);
        head=NULL;
        return;
    }
    while(temp->next!=NULL)
        temp=temp->next;
    temp->prev->next=NULL;
    free(temp);
}

void deleteFront()
{
    if(head==NULL)
    {
        printf("List is empty!\n");
        return;
    }
    Employee *temp=head;
    if(temp->next ==NULL)
    {
        free(temp);
        head=NULL;
        return;
    }
    head=head->next;
    head->prev=NULL;
    free(temp);
}

void display()
{
    if(head==NULL)
    {
        printf("List is empty!\n");
        return;
    }
    Employee *temp=head;
    int count=0;
    printf("\nDLL Status\n");
    while(temp!=NULL)
    {
        printf("SSN: %s, Name: %s, Dept: %s, Designation: %s, Salary: %d, Phone: %s\n",
        temp->SSN,temp->Name,temp->Dept,temp->Designation,temp->Sal,temp->PhNo);
        temp=temp->next;
        count++;
    }
    printf("Total Employee:%d\n",count);
}

void dequeDemo()
{
    printf("\n---Demonstrating DLL as Double Ended Queue---\n");

    //insert at rear
    printf("\nInsert at rear(End):\n");
    insertEnd(createNode());
    display();

    //Insert at front
    printf("\nInsert at front:\n");
    insertFront(createNode());
    display();

    //Delete from rear
    printf("\nDelete from rear(End):\n");
    deleteEnd();
    display();

    //Delete from front
    printf("\nDelete from Front:\n");
    deleteFront();
    display();

    printf("\n--- End of Deque Demonstaration ---\n");
}
int main()
{
    int choice,n,i;
    while(1)
    {
        printf("\n---MENU---\n");
        printf("1.Create DLL of N Employees (End Insertion)\n");
        printf("2.Display DLL and Count Nodes\n");
        printf("3.Insert at End\n");
        printf("4.Delete at End\n");
        printf("5.Insert at Front\n");
        printf("6.Delete at Front\n");
        printf("7.Demonstarate DLL as Double Ended Queue\n");
        printf("8.Exit\n");
        printf("Enter choice:\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter number of employees: ");
                scanf("%d",&n);
                for (i=0;i<n;i++)
                {
                    insertEnd(createNode());
                }
                break;
            case 2:
                display();
                break;
            case 3:
                insertEnd(createNode());
                break;
            case 4:
                deleteEnd();
                break;
            case 5:
                insertFront(createNode());
                break;
            case 6: 
                deleteFront();
                break;
            case 7:
                dequeDemo();
                break;
            case 8:
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");

        }
    }
    return 0;
}