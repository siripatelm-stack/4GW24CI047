#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*void create(struct);
void read(struct,int);
void display(struct,int);
void freememory(struct,size);*/

struct Day{
    int date;
    char* dayname;
    char* activity;
};
void create(struct Day *day){
    day->dayname = (char*) malloc (40 * sizeof(char));
    day->activity = (char*) malloc (100 * sizeof(char));
    printf("enter the day name: ");
    scanf("%s", day->dayname);
    printf("enter the date: ");
    scanf("%d", &day->date);
    printf("enter the activity: ");
    scanf("%s", day->activity);
}
void read(struct Day *calender, int size){
    for(int i=0;i<size;i++){
        printf("enter the details for day %d: \n",i+1);
        create(&calender[i]);
    }
}
void display(struct Day*calender, int size){
    printf("week's activity details :\n");
    for (int i=0;i<size;i++){
        printf("Day :%d\n",i+1);
        printf("day name :%s \n",calender[i].dayname);
        printf("date :%d\n",calender[i].date);
        printf("activity :%s\n",calender[i].activity);
        printf("\n");
    }
}
void freememory(struct Day*calender , int size){
    for (int i=0;i<size;i++){
        free(calender[i].dayname);
        free(calender[i].activity);
    }
}
int main(){
    int size;
    printf("enter the number of days in a week: ");
    scanf("%d", &size);
    struct Day*calender = (struct Day*) malloc(sizeof(struct Day)*size);
    if (calender==NULL){
        printf("memory allocation failed in the existing program");
        return 1;
    }
    read(calender,size);
    display(calender,size);
    freememory(calender,size);
    free(calender);
    return 0;
}