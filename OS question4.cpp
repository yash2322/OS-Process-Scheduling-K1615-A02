#include<windows.h>
#include <bits/stdc++.h>
using namespace std;
char d[100]=" OPERATING SYSTEM PROJECT K1615 A02";

int i=0,j;

struct Processes
{
	int p_id;
	int b_time,ar_time;
	float priority;               /* to store the info of processes including the priority */
	//int wait_time;
	//int turn_r_time;
};
void waiting_time_of_process(Processes process[],int number_of_p,int waiting_time[])
{
	//int priority_value[number_of_p];
		for(j=0;j<48;j++)
		{
		cout<<"*";
		}
		for(j=0;j<36;j++)
		{
		cout<<d[j];
		}
		for(j=0;j<48;j++)
		{
		cout<<"*";
		}
		cout<<"\n\n\n";
	for(int i=0;i<number_of_p;i++)
	{
		process[i].priority=-1.0;                   /*Setting the priority value to negative initially*/
	}
	int temp[number_of_p],value=0;
	int time=0,least_burst_time_OR_PRIORITY_P=0,executed=0,f_time,min_time_of_execution=INT_MAX;
	bool flag=false;bool next_if=false; 
	float temp_for_priority=-1.0;    
	
	for(int x=0;x<number_of_p;x++)
{
	temp[x]=process[x].b_time;           
}
//	for(int x=0;x<number_of_p;x++)
//{
//	cout<<temp[x]<<endl;
//}
//	int complete = 0, t = 0, minm = INT_MAX;     
//    int shortest = 0, finish_time;
//    bool check = false;
	bool P_or_BT=false;
	while(executed!=number_of_p)
	{
		
		for(int x=0;x<number_of_p;x++)
		{
			if(process[x].ar_time<=time&&process[x].priority!=0)
			/*calculating the priority if it is not set to zero i.e If it is not yet executed*/
			{          
			      
				process[x].priority=1+((time-process[x].ar_time)/(float)process[x].b_time);
				cout<<"\n "<<"\xB2"<<" priority of proceess "<<process[x].p_id<<" = "<<" 1 + (("<<time<<"-"<<process[x].ar_time<<")/running-time)"<< " ->"<<process[x].priority<<endl; 
			
			
			}
			
			
			if(process[x].priority>=temp_for_priority&&process[x].priority>1.5)
			{ /*If priority value has increased to more than 1.5 Than the process with the highest priority is executed*/
				temp_for_priority=process[x].priority;
				P_or_BT=true;
				min_time_of_execution=temp[x];
			least_burst_time_OR_PRIORITY_P=x;
				flag=true;
				next_if=true;     /*This is to make sure that the higher priority process should be executed instead of simple selecting the process with smaller burst time*/
			}
			
			if((process[x].ar_time<=time)&&(temp[x]<min_time_of_execution&&temp[x]>0)&&next_if==false)
			{/*If no process has very high priority or have same priority the they are executed on the basis of there burst time*/
				
				
//				cout<<"in upper\n";
//				cout<<process[x].ar_time<<endl;
				min_time_of_execution=temp[x];
			least_burst_time_OR_PRIORITY_P=x;
				flag=true;
					
				//	cout<<"\nleast burst time "<<least_burst_time_p<<endl;
				//cout<<"\ntime "<<time<<endl;
			}
			
		}
				if(flag==false)
		{
//			cout<<"in lower\n";
			time++;
//			cout<<"\n"<<time;
			continue;
		}
		if(P_or_BT==false)
		{
			cout<<"\n\n "<<"\xB2 "<<"Process will be sorted on the basis of burst time because priorities are either equal or not very high \n";
		}
		else
		{
			cout<<"\n\n "<<"\xB2 "<<"Process will be sorted on the basis of Priority  \n";
			P_or_BT=false;
		}
		cout<<"\n\n"<<" \xB2"<<" Selected Process priority ="<<temp_for_priority;

//		cout<<"\nhere\n";
		value=temp[least_burst_time_OR_PRIORITY_P];
		time=time+value;
//		cout<<"\ntime :"<<time<<endl;
        process[least_burst_time_OR_PRIORITY_P].priority=0; /*Setting the value of the variables*/									 
		temp[least_burst_time_OR_PRIORITY_P]=0;
		min_time_of_execution=INT_MAX;
		temp_for_priority=-1.0;
		next_if=false;
		if(temp[least_burst_time_OR_PRIORITY_P]==0)
		{
			/*If process executed than calculate its waiting time*/
			cout<<"\n\n\n "<<"\t\t\t"<<"\xB2\xB2\xB2 "<<"process : "<<process[least_burst_time_OR_PRIORITY_P].p_id<<" executed "<<"\xB2\xB2\xB2"<<endl;
			//			cout<<"\nexecuted\n";
			for(int i=0;i<40;i++)
			{
				cout<<"-";
			}
			cout<<"\n\n";
			
			executed++;
			f_time=time;
		             
			waiting_time[least_burst_time_OR_PRIORITY_P]=f_time-process[least_burst_time_OR_PRIORITY_P].b_time-process[least_burst_time_OR_PRIORITY_P].ar_time;
			
			
		}
		
		
	}
} 

void turn_around_time_of_process(Processes process[],int number_of_p,int waiting_time[],int turn_around_time[])
{
	for(int a=0;a<number_of_p;a++)
	{
		turn_around_time[a]=process[a].b_time+waiting_time[a];
		 
	}
}

void find_average_A_time(Processes process[],int number_of_p)
{
	int waiting_time[number_of_p],turn_around_time[number_of_p];
	int total_waiting_time=0,total_turn_around_time=0;      //int
	
	waiting_time_of_process(process,number_of_p,waiting_time);
	turn_around_time_of_process(process,number_of_p,waiting_time,turn_around_time);
	
		cout << " | Processes |"<< " | Burst time | "<< " | Waiting time | "<< " | Turn around time | "<< " | ARRIVAL TIME | \n";

	
	for(int x=0;x<number_of_p;x++)
	{
		total_waiting_time=total_waiting_time+waiting_time[x];
		total_turn_around_time=total_turn_around_time+turn_around_time[x];
		cout << "  " << process[x].p_id << " \t\t  "<< process[x].b_time << " \t\t   " << waiting_time[x]<< " \t\t   " << turn_around_time[x] << " \t\t\t   " <<process[x].ar_time << "\n";
	}
		for(int i=0;i<40;i++)
			{
				cout<<"-";
			}
			cout<<"\n\n";
		cout << "\n"<<"\xB2\xB2 "<<"Average waiting time of processes : "<< (float)total_waiting_time / (float)number_of_p;
    	cout<<"\n\n";
		
		cout << "\n"<<"\xB2\xB2 "<<"Average turn around time of processes : "<< (float)total_turn_around_time / (float)number_of_p<<"\n\n";

}
int main()
{
	string numbers[15]={" FIRST "," SECOND "," THIRD "," FOURTH "," FIFTH "," SIXTH "," SEVENTH "," EIGHT "," NINTH "," TENTH "," ELEVENTH "," TWELTH "," THIRTEENTH "," FOURTEENTH "," FIFTEENTH "};
char d[100]=" OPERATING SYSTEM PROJECT K1615 A02";

int i=0,j;

for(j=0;j<58;j++)
{
Sleep(15);
cout<<"\xB2";
}
for(j=0;j<36;j++)
{
Sleep(20);
cout<<d[j];
}
for(j=0;j<58;j++)
{
Sleep(15);
cout<<"\xB2";
}

	int number_of_process;
	cout<<"\n"<<"\xB2\xB2"<<" How many process you want to enter : ";
	cin>>number_of_process;
	Processes process[number_of_process];
	for(int i=0;i<number_of_process;i++)
	{
		system("cls");
		
		for(j=0;j<48;j++)
		{
		cout<<"*";
		}
		for(j=0;j<36;j++)
		{
		cout<<d[j];
		}
		for(j=0;j<48;j++)
		{
		cout<<"*";
		}

		cout<<"\n\n\n\n"<<"\xB2\xB2"<<" Enter the process ID of -"<<numbers[i]<<" process : " ;
		cin>>process[i].p_id;
		cout<<"\n"<<"\xB2\xB2"<<" Enter the arrival time : ";
		cin>>process[i].ar_time;
		cout<<"\n"<<"\xB2\xB2"<<" Enter the burst time : ";
		cin>>process[i].b_time;
		process[i].priority=0;
	}
	system("cls");
		
	find_average_A_time(process,number_of_process);
	return 0;
	//cout<<sizeof(process)/sizeof(process[0]);
//	for(int i=0;i<number_of_process;i++)
//	{
//	
//		cout<<"\nEnter the process ID : ";
//		cout<<process[i].p_id;
//		cout<<"\nEnter the arrival time : ";
//		cout<<process[i].ar_time;
//		cout<<"\nEnter the burst time : ";
//	cout<<process[i].b_time;
//	}

	
	
}

