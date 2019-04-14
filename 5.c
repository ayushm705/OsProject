#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
int burst_Time[20],arrival_Time[10],n,i,j,temporary,st[10],ft[10],waiting_Time[10],turnaround_time[10];
int total_wt=0,total_turnaround_time=0;
float average_waiting_time,average_turnaround_time;
char pn[10][10],t[10];
printf("Enter the number of process:");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Enter process name, arrival time & burst time:");
scanf("%s%d%d",pn[i],&arrival_Time[i],&burst_Time[i]);
}
for(i=0;i<n;i++)
for(j=0;j<n;j++)
{
if(burst_Time[i]<burst_Time[j])
{
temporary=arrival_Time[i];
arrival_Time[i]=arrival_Time[j];
arrival_Time[j]=temporary;
temporary=burst_Time[i];
burst_Time[i]=burst_Time[j];
burst_Time[j]=temporary;
strcpy(t,pn[i]);
strcpy(pn[i],pn[j]);
strcpy(pn[j],t);
}
}
for(i=0;i<n;i++)
{
if(i==0)
st[i]=arrival_Time[i];
else
st[i]=ft[i-1];
waiting_Time[i]=st[i]-arrival_Time[i];
ft[i]=st[i]+burst_Time[i];
turnaround_time[i]=ft[i]-arrival_Time[i];
total_wt+=waiting_Time[i];
total_turnaround_time+=turnaround_time[i];
}
average_waiting_time=(float)total_wt/n;
average_turnaround_time=(float)total_turnaround_time/n;


printf("\nPname\tarrivaltime\tbursttime\twaitingtime\tturnaround_timetime");
for(i=0;i<n;i++)
printf("\n%s\t%5d\t\t%5d\t\t%5d\t\t%5d",pn[i],arrival_Time[i],burst_Time[i],waiting_Time[i],turnaround_time[i]);
printf("\nAverage waiting time is:%f",average_waiting_time);
printf("\nAverage turnaroundtime is:%f",average_turnaround_time);
getch();
return 0;
}

