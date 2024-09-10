/*ASSIGNMENT 3:
Name:SAHIL DHAS
Roll No. 23514
Sub :Data Structures and algorithms
*/
#include<iostream>
using namespace std;
#define MAXSIZE 3
int rear = -1,front=-1,queue[MAXSIZE];

int insert()
{
	int x ;
	if(front==(rear+1)%MAXSIZE)
	{
		cout<<"Queue is full ";
	}
	else
	{
		if(front==-1)
		{
			front=0;
			cout<<front;
		}
		rear = (rear+1)%MAXSIZE;
		cout<<"enter a number to enter :  ";
		cin>>x;
		queue[rear]=x ;
		cout<<x<<" is added at : "<<rear<<endl;
	}
}
int Delete()
{
	if((front==-1)||(front>rear))
	{
		cout<<"Queue is Empty";
	}
	
	else
	{
		int ele ;
		ele = queue[front];
		cout<<ele<<" is deleted at : "<<front<<endl;
		jk
	if(rear==(MAXSIZE-1)&&(front==0)||(front>rear))
	{
		front=-1;
		rear=-1;
	}
	}
}
int display()
{
	for(int i = front;i<=rear;i++)
	{
		cout<<queue[i]<<endl;
	}
}

int main()
{
	while(!(front== MAXSIZE))
	{
		cout<<"ENTER WHAT YOU WANT : \n 1.INSERT \n 2.DELETE \n 3.DISPLAY"<<endl;
		int x; 
		cout<<": ";
		cin>>x;
		if(x==1)
		{
			insert();
			continue;
		}
		if(x==2)
		{
			Delete();
			continue;
		}
		if(x==3)
		{
			display();
		}
		else
		{
			cout<<"enter valid choice "<<endl;
		}
	}
}
