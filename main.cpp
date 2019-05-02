#include <iostream>
using namespace std;

class CpuSchedule
{
    int n,Bu[20],P[10],weight[10];
    int processNumber[10], position; // stores process number
    float Atat,Awt,A[10],Wt[10],tat[10];
    public:
        void Getdata();//Getting the No of processes & burst time
        void Fcfs(); //First come First served Algorithm
        void Sjf();//Shortest job First Algorithm
        void Priority(); //Priority Algorithm
        void SjfP(); //Shortest job First Algorithm with Preemption
        void SjfNp(); //Shortest job First Algorithm with NonPreemption
        void RoundRobin(); //Round Robin Algorithm
        void PriorityRoundRobin();
        void WRR();
        void test();
};

void   CpuSchedule::Getdata(){
        cout<<" Enter the no of processes < 20:";
        cin>>n;
        for(int i=0;i<n;i++)
        {
            processNumber[i]=i+1;
          cout<<" Enter The BurstTime for Process p["<<processNumber[i]<<"]= ";
          cin>>Bu[i];
        }
   }
void CpuSchedule::Fcfs(){
    int i,B[10];
    Awt=0.0;
    Atat=0.0;
    for(i=0;i<n;i++)
    {
        B[i]=Bu[i];
        cout<<"\nBurst time for process p["<<processNumber[i]<<"]= ";
        cout<<B[i] << endl;;
    }
    Wt[0]=0;// waiting time for first process is 0

    for(i=1;i<n;i++)
    {
        Wt[i]=B[i-1]+Wt[i-1];//calculating waiting time for each process

    }

    cout<<"\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time";

    //Calculating Total Weighting Time and Total Turn around Time
    for(i=0;i<n;i++)
    {
        Awt += Wt[i];
        tat[i] = B[i]+Wt[i];
        Atat += tat[i];\
         cout<<"\nP["<<processNumber[i]<<"]"<<"\t\t"<<B[i]<<"\t\t"<<Wt[i]<<"\t\t"<<tat[i];
    }

    Awt=Awt/n; // Average Waiting Time
    Atat=Atat/n; // Average Turnaround Time

    cout<<"\n\nAverage Waiting Time:"<<Awt;
    cout<<"\nAverage Turnaround Time:"<<Atat;
}
void CpuSchedule::Sjf(){
    int i,j,temp,B[10]; //here B[] stores the sorted burst time of process.
    Awt=0.0;
    Atat=0.0;

    for(i=0;i<n;i++)
    {
    B[i]=Bu[i];
    cout<<"\nBurst time for process p["<<processNumber[i]<<"]= ";
    cout<<B[i];
    }

    //sorting burst time in ascending order using selection sort
    for(i=0;i<n;i++)
    {
        position=i;
        for(j=i+1;j<n;j++)
        {
            if(B[j]<B[position])
                position=j;
        }

        temp=B[i];
        B[i]=B[position];
        B[position]=temp;

        temp=processNumber[i];
        processNumber[i]=processNumber[position];
        processNumber[position]=temp;
    }
    Wt[0]=0;// waiting time for first process is 0
    for(i=1;i<n;i++)
    {
        Wt[i]=B[i-1]+Wt[i-1];//calculating waiting time for each process
    }
    cout<<"\n\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time";

    //Calculating Total Weighting Time and Total Turn around Time
    for(i=0;i<n;i++)
    {
        Awt+=Wt[i];
        tat[i]= B[i]+Wt[i];
        Atat += tat[i];\
        cout<<"\nP["<<processNumber[i]<<"]"<<"\t\t"<<B[i]<<"\t\t"<<Wt[i]<<"\t\t"<<tat[i];
    }

    Awt/=n; // Average Waiting Time
    Atat/=n; // Average Turnaround Time

    cout<<"\n\nAverage Waiting Time:"<<Awt;
    cout<<"\nAverage Turnaround Time:"<<Atat;
}
void CpuSchedule::Priority(){
    int i,j,temp,B[10]; //here B[] stores the sorted burst time of process.
    Awt=0.0;
    Atat=0.0;

    for(i=0;i<n;i++)
    {
    B[i]=Bu[i];
    cout<<"\nBurst time for process p["<<processNumber[i]<<"]= ";
    cout<<B[i];
    cout<<" Enter the priority for process P"<<processNumber[i]<<"= ";
    cin>>P[i];
    }

    for(i=0;i<n;i++)
    {
        position=i;
        for(j=i+1;j<n;j++)
        {
            if(P[j]<P[position])
                position=j;
        }

        temp=P[i];
        P[i]=P[position];
        P[position]=temp;

        temp=B[i];
        B[i]=B[position];
        B[position]=temp;

        temp=processNumber[i];
        processNumber[i]=processNumber[position];
        processNumber[position]=temp;
    }
    Wt[0]=0;// waiting time for first process is 0
    for(i=1;i<n;i++)
    {
        Wt[i]=B[i-1]+Wt[i-1];//calculating waiting time for each process
    }
    cout<<"\n\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time";

    //Calculating Total Weighting Time and Total Turn around Time
    for(i=0;i<n;i++)
    {
        Awt+=Wt[i];
        tat[i]= B[i]+Wt[i];
        Atat += tat[i];
        cout<<"\nP["<<processNumber[i]<<"]"<<"\t\t"<<B[i]<<"\t\t"<<Wt[i]<<"\t\t"<<tat[i];
    }

    Awt/=n; // Average Waiting Time
    Atat/=n; // Average Turnaround Time

    cout<<"\n\nAverage Waiting Time:"<<Awt;
    cout<<"\nAverage Turnaround Time:"<<Atat;
}
void CpuSchedule::RoundRobin(){
    int i,B[10],quanta,remain,flag=0,Rt[10],time; //here B[] stores the sorted burst time of process.
    Awt=0.0;
    Atat=0.0;
    remain=n;
    for(i=0;i<n;i++)
    {
    B[i]=Bu[i];
    Rt[i]=B[i];
    cout<<"\nBurst time for process p["<<processNumber[i]<<"]= ";
    cout<<B[i];
    cout<<"\nEnter the Arival Time for process P"<<processNumber[i]<<"= ";
    cin>>A[i];
    }
    cout<<"\nEnter Time Quantum"<<endl;
    cin>>quanta;

    cout<<"\n\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time";

    for(time=0,i=0;remain!=0;)
    {
        if(Rt[i]<=quanta && Rt[i]>0)
        {
          time+=Rt[i];
          Rt[i]=0;
          flag=1;
        }
        else if(Rt[i]>0)
        {
          Rt[i]-=quanta;
          time+=quanta;
        }
        if(Rt[i]==0 && flag==1)
        {
          remain--;
          Wt[i]=time-A[i]-B[i];
          tat[i]=time-A[i];
          cout<<"\nP["<<processNumber[i]<<"]"<<"\t\t"<<B[i]<<"\t\t"<<Wt[i]<<"\t\t"<<tat[i];
          Awt+=Wt[i];
          Atat+=tat[i];
          flag=0;
        }
        if(i==n-1)
          i=0;
        else if(A[i+1]<=time)
          i++;
        else
          i=0;
    }
    Awt/=n; // Average Waiting Time
    Atat/=n; // Average Turnaround Time

    cout<<"\n\nAverage Waiting Time:"<<Awt;
    cout<<"\nAverage Turnaround Time:"<<Atat;
}
void CpuSchedule::PriorityRoundRobin(){
    int i,B[10],quanta,remain,flag=0,Rt[10],time,low=3,mid=2,high=1;
    Awt=0.0;
    Atat=0.0;
    remain=n;//remaining processes in ready queue
    for(i=0;i<n;i++)
    {
    B[i]=Bu[i];
    Rt[i]=B[i];
    cout<<"\nBurst time for process p["<<processNumber[i]<<"]= ";
    cout<<B[i];
    cout<<"\nEnter the Arival Time and Priority for process P"<<processNumber[i]<<"= ";
    cin>>A[i];
    cin>>P[i];
    }
    cout<<"\nEnter Base Time Quanta size"<<endl;
    cin>>quanta;

    cout<<"\n\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time";

    for(time=0,i=0;remain!=0;)
    {
        if(P[i]==high)
            quanta*=2;//high priority task are given twice amount of quanta
        else if(P[i]==mid)
            quanta*=1.5;//mid priority task are given 1.5 times of quanta
        else if(P[i]==low)
            quanta*=1; //low priority task get quanta as defined initially

        if(Rt[i]<=quanta && Rt[i]>0)
        {
          time+=Rt[i];
          Rt[i]=0;
          flag=1;
        }
        else if(Rt[i]>0)
        {
          Rt[i]-=quanta;
          time+=quanta;
        }
        if(Rt[i]==0 && flag==1)
        {
          remain--;
          Wt[i]=time-A[i]-B[i];// waiting time calculation
          tat[i]=time-A[i];//turn around time calculation
          cout<<"\nP["<<processNumber[i]<<"]"<<"\t\t"<<B[i]<<"\t\t"<<Wt[i]<<"\t\t"<<tat[i];
          Awt+=Wt[i];
          Atat+=tat[i];
          flag=0;
        }
        if(i==n-1)
          i=0;
        else if(A[i+1]<=time)
          i++;
        else
          i=0;
    }
    Awt/=n; // Average Waiting Time
    Atat/=n; // Average Turnaround Time

    cout<<"\n\nAverage Waiting Time:"<<Awt;
    cout<<"\nAverage Turnaround Time:"<<Atat;
}
void CpuSchedule::WRR()
{
    int i,j,quanta,flag,x,B[10];
    Awt=0.0;
    Atat=0.0;
    for(i=0;i<n;i++)
    {
        B[i]=Bu[i];
        cout<<" Enter The weight for Process p"<<i+1<<"= ";
        cin>>weight[i];
    }
    for(i=0;i<n;i++)
        Wt[i]=0;
    while(1)
    {
        for(i=0;i<n;i++) //we serve each process for time slice of 2
        {
            if(B[i]<2)     // if burst time is less than 2 time slice will be burst time
            {
                quanta=B[i];
            }
            else
            {
                quanta=2;
            }
            B[i]=B[i]-quanta;
            weight[i]--;
            for(j=0;j<n;j++) //update the weights of remaining process
            {
                if(B[j]==0) continue;
                if (i!=j)
                    Wt[j]=Wt[j]+quanta;

            }
            x=(i+1)%n;
            if (weight[i]>=weight[x]) i--;
        }
        for(i=0,flag=1;i<n;i++)
        {
            if (B[i]!=0) flag=0;
        }
        if (flag==1) break;
    }
    cout<<"\n process \t\t waiting time \t\t turnaround time";
    for(i=0;i<n;i++)
    {
       tat[i]=Wt[i]+Bu[i];
       cout<<"\nP"<<i+1<<"\t\t"<<Wt[i]<<"\t\t"<<tat[i];
       Awt=Awt+Wt[i];
       Atat=Atat+tat[i];
    }
    Awt=Awt/n;
    Atat=Atat/n;

    cout<<"\naverage waiting time="<<Awt;
    cout<<"\naverage turnaround time="<<Atat;
}

int main()
{
    int c;
    CpuSchedule cpuSchedule;
    while(1){
        cout<<"\n\nEnter your choice\n";
        cout<<"1. first come first serve\n";
        cout<<"2. Shortest job first\n";
        cout<<"3. Priority scheduling\n";
        cout<<"4. Round robin\n";
        cout<<"5. Weighted round robin\n";
        cout<<"6. Priority round robin\n";
        cin>>c;
        switch(c)
        {
        case 1:
            cpuSchedule.Getdata();
            cpuSchedule.Fcfs();
            break;
        case 2:
            cpuSchedule.Getdata();
            cpuSchedule.Sjf();
            break;
        case 3:
            cpuSchedule.Getdata();
            cpuSchedule.Priority();
            break;
        case 4:
            cpuSchedule.Getdata();
            cpuSchedule.RoundRobin();
            break;
        case 5:
            cpuSchedule.Getdata();
            cpuSchedule.WRR();
            break;
        case 6:
            cpuSchedule.Getdata();
            cpuSchedule.PriorityRoundRobin();
            break;
        default:
            cout<<"wrong entry";
    }
    }
    return 0;
}

