#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node
{
    int coeff;
    int px,py,pz;
    struct Node *next;
}Node;

Node *createHeader()
{
    Node *header =(Node *) malloc(sizeof(Node));
    header->coeff=0;
    header->px=header->py=header->pz=0;
    header->next=header;
    return header;
}
void insertTerm(Node *header,int coeff,int px,int py,int pz)
{
    Node *newNode =(Node *)malloc (sizeof(Node));
    newNode->coeff=coeff;
    newNode->px=px;
    newNode->py=py;
    newNode->pz=pz;

    Node *temp=header;
    while(temp->next!=header)
        temp=temp->next;
    temp->next=newNode;
    newNode->next=header;
}

void displayPoly(Node *header)
{
    Node *temp=header->next;
    while(temp!=header)
    {
        printf("%+d*x^%d*y^%d*z^%d",temp->coeff,temp->px,temp->py,temp->pz);
        temp=temp->next;
    }
    printf("\n");
}

int ipow(int base, int exp)
{
    int result=1;
    for (int i=0;i<exp;i++)
        result*=base;
    return result;
}

int evaluatePoly(Node *header,int x,int y,int z)
{
    int result=0;
    Node*temp=header->next;
    while(temp!=header)
    {
        result+= temp->coeff*ipow(x,temp->px)*ipow(y,temp->py)*ipow(z,temp->pz);
        temp=temp->next;
    }
    return result;
}

Node *addPoly(Node *h1,Node *h2)
{
    Node *sumHeader=createHeader();
    Node *t1=h1->next;
    while(t1!=h1){
        insertTerm(sumHeader,t1->coeff,t1->px,t1->py,t1->pz);
        t1=t1->next;
    }
    Node *t2=h2->next;
    while(t2!=h2){
        Node *temp =sumHeader->next;
        int found=0;
        while (temp !=sumHeader){
            if(temp->px==t2->px &&temp->py==t2->py && temp->pz==t2->pz){
                temp->coeff+=t2->coeff;
                found=1;
                break;
            }
            temp=temp->next;
        }
        if(!found){
            insertTerm(sumHeader,t2->coeff,t2->px,t2->py,t2->pz);
        }
        t2=t2->next;
    }
    return sumHeader;
}
int main(){
    Node *P = createHeader();
    insertTerm(P,6,2,2,1);
    insertTerm(P,-4,0,1,5);
    insertTerm(P,3,3,1,1);
    insertTerm(P,2,1,5,1);
    insertTerm(P,-2,1,1,3);

    printf("Polynomial P(x,y,z): ");
    displayPoly(P);

    int val=evaluatePoly(P,1,2,1);
    printf("Evaluation at (x=1,y=2,z=1): %d\n",val);

    Node *POLY1=createHeader();
    Node *POLY2=createHeader();

    insertTerm(POLY1,3,2,1,0);
    insertTerm(POLY1,4,0,0,2);
    insertTerm(POLY2,5,2,1,0);
    insertTerm(POLY2,-4,0,0,2);

    printf("\nPoly1: ");
    displayPoly(POLY1);
    printf("POLY2: ");
    displayPoly(POLY2);

    Node *POLYSUM =addPoly(POLY1,POLY2);
    printf("POLYSUM = POLY1+POLY2");
    displayPoly(POLYSUM);

    return 0;
}