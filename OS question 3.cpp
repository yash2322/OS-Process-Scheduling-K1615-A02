#include<windows.h>
#include <bits/stdc++.h>
using namespace std;
struct Processes                                     /*here i am decalaring a structure to store the process info*/
{                 
	int p_id;
	int b_time,ar_time;
	//int wait_time;
	//int turn_r_time;
};


//struct readyQueue
//{
//	int id,btime;
//}
void waiting_time_of_process(Processes process[],int number_of_p,int waiting_time[])
{
	/*  This is a function to calculate the waiting time of process. this function is also used to arrange and choose the process	*/
	int temp[number_of_p],value=0;       
 	int time=0,least_burst_time_p=0,executed=0,f_time,min_time_of_execution=5000;   /* i have set a boundary condition that a process
	 																				with a burst time above 5000 will not be selected*/	 
	bool flag=false;                         /* this flag is used to make sure that a process is selected. .If not ,time is incremented by 1. */
	
	for(int x=0;x<number_of_p;x++)
{
	temp[x]=process[x].b_time;              /*storing the burst time of processes in temporary variable.*/
}
//	for(int x=0;x<number_of_p;x++)
//{
//	cout<<temp[x]<<endl;
//}
	
	while(executed!=number_of_p)              /* running this loop until all the processess area executed.*/
	{
		
		for(int x=0;x<number_of_p;x++)
		{
			
			if((process[x].ar_time<=time)&&(temp[x]<min_time_of_execution&&temp[x]>0))      /*This is used to select a process on the basis of atrrival time and least burst time*/
			{
//				cout<<"in upper\n";
//				cout<<process[x].ar_time<<endl;
				min_time_of_execution=temp[x];
				least_burst_time_p=x;
				flag=true;
				
				/*	cout<<"\nleast burst time "<<least_burst_time_p<<endl;
				cout<<"\ntime "<<time<<endl;*/
				
			}
			
		}
		
		if(flag==false)
		{
//			cout<<"in lower\n";
			time++;
//			cout<<"\n"<<time;
			continue;
		}
//		cout<<"\nhere\n";
		value=temp[least_burst_time_p];                
		time=time+value;          //incrementing time .
/*		cout<<"\ntime :"<<time<<endl; 									 check from here*/
		temp[least_burst_time_p]=0;  /*process executed   ,hence burst time =0;*/ 
		min_time_of_execution=5000;
		if(temp[least_burst_time_p]==0)
		{
			cout<<"\n process : "<<process[least_burst_time_p].p_id<<" executed "<<endl;
			//			cout<<"\nexecuted\n";
			executed++;
			f_time=time+2;               /*calculating waiting time*/
			time=time+2;                 /*finish time*/
			waiting_time[least_burst_time_p]=f_time-process[least_burst_time_p].b_time-process[least_burst_time_p].ar_time;
		}
		
		
	}
} 

void turn_around_time_of_process(Processes process[],int number_of_p,int waiting_time[],int turn_around_time[])
{  /*For turn around  time*/ 
	for(int a=0;a<number_of_p;a++)
	{
		turn_around_time[a]=process[a].b_time+waiting_time[a];
		 
	}
}

void find_average_A_time(Processes process[],int number_of_p)
{
	int waiting_time[number_of_p],turn_around_time[number_of_p];
	int total_waiting_time=0,total_turn_around_time=0;      //int
/* Average turn around time  */	
	waiting_time_of_process(process,number_of_p,waiting_time);
	turn_around_time_of_process(process,number_of_p,waiting_time,turn_around_time);
	
	cout << " | Processes |"<< " | Burst time | "<< " | Waiting time | "<< " | Turn around time | \n";
	
	for(int x=0;x<number_of_p;x++)
	{
		total_waiting_time=total_waiting_time+waiting_time[x];
		total_turn_around_time=total_turn_around_time+turn_around_time[x];
		cout << "  " << process[x].p_id << " \t\t"<< process[x].b_time << " \t\t " << waiting_time[x]<< " \t\t " << turn_around_time[x] << "\n";
	}
		cout << "\nAverage waiting time of processes : "<< (float)total_waiting_time / (float)number_of_p;
    	cout << "\nAverage turn around time of processes : "<< (float)total_turn_around_time / (float)number_of_p;
}
int main()
{  
	

	int number_of_process;
	cout<<"\n How many process you want to enter \n";
	cin>>number_of_process;
	Processes process[number_of_process];
	for(int i=0;i<number_of_process;i++)
	{
		system("cls");
		cout<<"\nEnter the process ID of -"<<numbers[i]<<" process : " ;
		cin>>process[i].p_id;
		cout<<"\nEnter the arrival time : ";
		cin>>process[i].ar_time;
		while(process[i].ar_time==0)                 /*if arrival time =0; DOn't select the process*/
		{
			cout<<"\nEntered process arrival time is wrong. Enter the correct arrival time ";
			cin>>process[i].ar_time;
		}
		cout<<"\nEnter the burst time : ";
		cin>>process[i].b_time;
		
	}
		
	find_average_A_time(process,number_of_process);
	return 0;
	//cout<<sizeof(process)/sizeof(process[0]);
//	for(int i=0;i<number_of_process;i++)
//	{
//	
//		cout<<"\nEnter the process ID : ";
//		cout<<process[i].p_id;                          for debugging .
//		cout<<"\nEnter the arrival time : ";
//		cout<<process[i].ar_time;
//		cout<<"\nEnter the burst time : ";
//	cout<<process[i].b_time;
//	}
}


