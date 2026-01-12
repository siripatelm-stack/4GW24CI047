#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    char usn[10];
    char name[30];
    char programme[20];
    int sem;
    char phno[12];
    struct Student *next;
};
struct Student *head =NULL;

//Function to create Node
struct Student *createNode()
{
    struct Student *newNode =(struct Student*) malloc(sizeof(struct Student));
    printf("USN: \n");
    scanf("%s",newNode -> usn);
    printf("Name: \n");
    scanf("%s",newNode->name);
    printf("Programme: \n");
    scanf("%s",newNode->programme);
    printf("Semester: \n");
    scanf("%d",&newNode->sem);
    printf("Phone no: \n");
    scanf("%s",newNode->phno);
    newNode->next=NULL;
    return newNode;
}
//Create SLL of N students using front insertion
void createList(int n){
    for (int i=0;i<n;i++)
    {
        struct Student *newNode=createNode();
        newNode->next=head;
        head=newNode;
        printf("\n");
    }
}
//Display SLL and count nodes
void displayList()
{
    struct Student *temp=head;
    int count=0;
    if(temp==NULL)
    {
        printf("List is empty.\n");
        return;
    }
    printf("\n-- Student List --\n");
    while(temp !=NULL)
    {
        printf("USN: %s,Name: %s,Programme: %s,Sem: %d,PhNo: %s\n",
        temp->usn,temp->name,temp->programme,temp->sem,temp->phno);
        temp =temp->next;
        count++;
    }
    printf("Total number of students = %d\n",count);
}

//Insertion at End 
void insertEnd()
{
    struct Student *newNode =createNode();
    if(head ==NULL)
    {
        head =newNode;
        return;
    }
    struct Student *temp =head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newNode;
}

//Deletion at End
void deleteEnd(){
    if(head ==NULL){
        printf("List is empty.\n");
        return;
    }
    if(head->next ==NULL){
        free(head);
        head =NULL;
        return;
    }
    struct Student *temp =head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;
}
//Delete at front
void deleteFront(){
    if(head ==NULL)
    {
        printf("List is empty");
        return;
    }
    struct Student *temp=head;
    head=head->next;
    free(temp);
}

int main()
{
    int choice ,n;
    while(1)
    {
        printf("\n--- MENU ---\n");
        printf("1. Create SLL of N Students (Front Insertion)\n");
        printf("2. Display and Count Nodes\n");
        printf("3. Insert at end\n");
        printf("4. Delete at end\n");
        printf("5. Delete at Front\n");
        printf("6. Exit\n");
        printf("Enter your Choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter number of Students: ");
                scanf("%d",&n);
                createList(n);
                break;
            case 2:
                displayList();
                break;
            case 3:
                insertEnd();
                break;
            case 4:
                deleteEnd();
                break;
            case 5:
                deleteFront();
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}