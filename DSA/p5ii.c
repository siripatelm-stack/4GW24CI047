#include <stdio.h>
/*Recurcive function to solve Tower of Hanoi*/
void towerOfHanoi(int n,char source,char temp,char destination)
{
    if (n==1)
    {
        printf("Move disk 1 from %c to %c\n",source,destination);
        return;
    }
    /*Move n-1 disks from source to temp*/
    towerOfHanoi(n-1,source,destination,temp);
    //Move the nth disk from source to detination
    printf("Move disk %d from %c to %c\n",n,source,destination);
    //Move n-1 disks from temp to destination
    towerOfHanoi(n-1,temp,source,destination);
}
int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d",&n);
    towerOfHanoi(n,'A','B','C');
    return 0;
}