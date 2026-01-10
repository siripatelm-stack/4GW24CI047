#include <stdio.h>
#include <stdlib.h>
#define SIZE 10     //hashtable size (m)

//Hash table structure
int hashTable[SIZE];

//Initialize hash table
void initHashTable()
{
    for(int i=0;i<SIZE;i++)
        hashTable[i]=-1;  //-1 means empty
}

//Hash Function
int hashFunction(int key)
{
    return key % SIZE;
}

//Insert key using linear probing
void insertKey(int key)
{
    int index=hashFunction(key);
    //Linear probing if collision
    while (hashTable[index]!=-1)
    {
        index=(index+1)%SIZE;
    }
    hashTable[index]=key;
}

//Display hash table
void displayHashTable()
{
    printf("\nHash Table:\n");
    for (int i=0;i<SIZE;i++)
    {
        if(hashTable[i]!=-1)
            printf("Index %d -> %d\n",i,hashTable[i]);
        else
            printf("Index %d -> EMPTY\n",i);
    }
}

//Search key in hash table
void searchKey(int key)
{
    int index=hashFunction(key);
    int start=index;
    while(hashTable[index]!=-1)
    {
        if(hashTable[index]==key)
        {
            printf("Key %d found at index %d\n",key,index);
            return;
        }
        index=(index+1)%SIZE;
        if(index==start)
            break;
    }
    printf("Key %d not found in hash table\n",key);
}

int main()
{
    initHashTable();

    int keys[]={1234,5678,4321,8765,1111,2222};
    int n=sizeof(keys)/sizeof(keys[0]);

    //Insert keys into Hash Table
    for(int i=0;i<n;i++)
        insertKey(keys[i]);
    
    //Display Hash Table
    displayHashTable();

    //Search Example
    searchKey(4321);
    searchKey(9999);

    return 0;
}