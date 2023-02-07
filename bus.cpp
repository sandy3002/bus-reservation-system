#include<stdio.h>
#include<iostream>
#include<string.h>
#include<cstdlib>

using namespace std;

static int p = 0;
class a
{
    char busn[5], driver[10], arrival[5], depart[5],  from[10], to[10], seat[8][4][10];

public:
    void install();

    void allotement();

    void empty();

    void show();

    void avail();

    void position(int i);

}

bus[10];

void vline(char ch)
{
    for(int i=80;i>0;i--)
        cout<<ch;
}

void a::install()
{
    cout<<"Enter bus no: ";
    cin>>bus[p].busn;
    cout<<"\nEnter Driver's name: ";
    cin>>bus[p].driver;
    cout<<"\nArrival time: ";
    cin>>bus[p].arrival;
    cout<<"\nDeparture time: ";
    cin>>bus[p].depart;
    cout<<"\nFrom:\t\t";
    cin>>bus[p].from;
    cout<<"\nTo:\t\t";
    cin>>bus[p].to;
    bus[p].empty();
    p++;
    
}

void a::allotement()
{
    int seat;
    char number[5];
    top:
    cout<<"Bus no: ";
    cin>>number;
    int n;
    for(n=0;n<=p;n++)
    {
        if(strcmp(bus[n].busn, number)==0)
            break;
    }

    while(n<=p)
    {
        cout<<"\nseat number: ";
        cin>>seat;

        if(seat>32)
        {
            cout<<"\nThere are only 32 seats available in this bus";
        }
        else
        {
            if(strcmp(bus[n].seat[seat/4][(seat%4)-1],"Empty")==0)
            {
                cout<<"Enter passanger's name: ";
                cin>>bus[n].seat[seat/4][(seat%4)-1];
                break;
            }
            else
                cout<<"The seat no. is already reserved.\n";
        }
    }
    if(n>p)
    {
        cout<<"Enter correct bus no.\n";
        goto top;
    }
}

void a::empty()
{
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<4;j++)
        {
            strcpy(bus[p].seat[i][j], "Empty");
        }
    }
}

void a::show()
{
    int n;
    char number[5];
    cout<<"Enter bus no: ";
    cin>>number;
    for(n=0;n<=p;n++)
    {
        if(strcmp(bus[n].busn, number)==0)
            break;
    }
    while(n<=p)
    {
        vline('*');
        cout<<"Bus no: \t"<<bus[n].busn<<endl;
        cout<<"Driver: \t"<<bus[n].driver<<endl;
        cout<<"Arrival time: \t"<<bus[n].arrival<<endl;
        cout<<"Departure time: \t"<<bus[n].depart<<endl;
        cout<<"From: \t"<<bus[n].from<<endl;
        cout<<"To: \t"<<bus[n].to<<endl;
        vline('*');
        bus[0].position(n);
        int a=1;
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<4;j++)
            {
                a++;
                if(strcmp(bus[n].seat[j][j],"Empty")!=0)
                    cout<<"\nThe seat no "<<a-1<<" is reserved for "<<bus[n].seat[i][j]<<".";
            }
        }

        break;
    }

    if(n>p)
        cout<<"Enter correct bus no: ";
}

void a::position(int l)
{
	int s=0;p=0;
	for(int i = 0;i<8;i++)
	{
		cout<<endl;
		for(int j=0;j<4;j++)
		{
			s++;
			if(strcmp(bus[l].seat[i][j], "Empty")==0)
			{
				cout.width(5);
				cout.fill(' ');
				cout<<s<<".";
				cout.width(10);
				cout.fill(' ');
				cout<<bus[l].seat[i][j];
				p++;
			}

			else
			{
				cout.width(5);
				cout.fill(' ');
				cout<<s<<".";
				cout.width(10);
				cout.fill(' ');
				cout<<bus[l].seat[i][j];
			}
		}
	}

	cout<<"\n\nThere are"<<p<<"seats empty in Bus no: "<<bus[l].busn;
}

void a::avail()
{
	for(int n=0;n<p;n++)
	{
		vline('*');
		cout<<"Bus no: \t"<<bus[n].busn<<endl;
		cout<<"Driver: \t"<<bus[n].driver<<endl;
		cout<<"Arrival Time: \t"<<bus[n].arrival<<endl;
		cout<<"Departure Time: \t"<<bus[n].depart<<endl;
		cout<<"From: \t" <<bus[n].from<<endl;
		cout<<"To: \t"<<bus[n].to<<endl;
		vline('*');
		vline('_');
	}
}

int main()
{
	system("cls");
	int w;
	while(1)
	{
		cout<<endl<<endl;
		cout<<"***SIMPLE BUS RESERVATION SYSTEM***";
		cout<<endl<<endl;
		cout<<"\t\t\t1.Install"<<endl;
		cout<<"\t\t\t2.Reservation"<<endl;
		cout<<"\t\t\t3.Show"<<endl;
		cout<<"\t\t\t4.Buses Available"<<endl;
		cout<<"\t\t\t5.Exit"<<endl;
		cout<<"\t\t\tEnter your choice:- ";

		cin>>w;

		switch(w)
		{
			case 1: bus[p].install();
				break;
			case 2: bus[p].allotement();
				break;
			case 3: bus[0].show();
				break;
			case 4: bus[0].avail();
				break;
			case 5: exit(0);
		}
	}
	return 0;
}
