#include <stdio.h>
//Function to find the waiting time for all processes
void findWaitingTime(int processes[], int n, int bt[],int wt[])
{
    wt[0]=0;
    for (int i=0;i<n;i++)
        wt[i]=bt[i-1]+wt[i-1];
}
void findWaitingTime(int processes[],int n,int bt[],int wt[],int at[]){

}
//Function to find the turnaround time for all processes
void findTurnaroundTime(int processes[],int n,int bt[],int wt[],int tat[])
{
    for (int i=0;i<n;i++)
        tat[i]=bt[i]+wt[i];
}
//Function to calculate average time
void findAverageTime(int processes[],int n,int bt[])
{
    int wt[n],tat[n];
    //Function yo find waiting time for all processes
    findWaitingTime(processes,n,bt,wt);

    //Function to find turnaround time for all the processes
    findTurnaroundTime(processes,n,bt,wt,tat);

    //Display processes along with their waiting time and turnaround time
    printf("\nProcess Burst Time Waiting"
    " Time Turn-Around Time\n");
    int total_wt=0,total_tat=0;
    for(int i=0;i<n;i++){
        total_wt=total_wt+wt[i];
        total_tat=total_wt+tat[i];
        printf(" %d\t",(i+1));
        printf(" %d\t",bt[i]);
        printf(" %d\t",wt[i]);
        printf(" %d\t",tat[i]);
    }
    printf("\nAverage waiting time = %.2f",(float)total_wt/(float)n);
    printf("\nAverage turn-around time =,%.2f",(float)total_tat/(float)n);
}
//Function to implement FCFS scheduling algorithm
void FCFS(int processes[],int n, int bt[])
{
    findAverageTime(processes,n,bt);
}
void SJF(int processes[],int n,int bt[])
{
    //Sort processes based on burst time 
    for (int i=0;i<n-1;i++){
        for (int j=0;j<n-i-1;j++){
            if(bt[j]>bt[j+1]){
                //Swap the processes
                int temp =bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=temp;

                temp=processes[j];
                processes[j]=processes[j+1];
                processes[j+1]=temp;
            }
        }
    }
    findAverageTime(processes,n,bt);
}
//Function to implement Round Robin Scheduling algorithm
void RoundRobin(int processes[],int n,int bt[],int quantum)
{
    int wt[n],tat[n];
    //Initialize waiting time and turnaround time arrays
    for (int i=0;i<n;i++){
        wt[i]=0;
        tat[i]=0;
    }
    int time =0;
    //Run until all processes are completed
    while(1){
        int done =1;
        //Traverse all processes
        for (int i=0;i<n;i++){
            //If burst time is greater than 0, processes i is not done
            if(bt[i]>0){
                done=0;
                //If remaining burst time is less than or equal to quantum,finish the process
                if (bt[i]<=quantum){
                    time+=bt[i];
                    wt[i]=time -bt[i];
                    bt[i]=0;
                }
                else{
                    //Reduce the burst time by the quantum time
                    time +=quantum;
                    bt[i]-=quantum;
                }
            }
        }
        //If all processes are done ,exit the loop
        if(done==1)
            break;
    }
}