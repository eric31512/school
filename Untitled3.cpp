#include<iostream>
#include<cstdlib>
#include<ctime> 
#include <iomanip>
using namespace std;

void number(int c[])
{
	for(int i=0;i<26;i++)
	{c[i]+=4;
	 c[i]/=4;
	}
	
}

void f(int b[])
{
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
			if(b[j]>b[j+1])
			{
				int c=b[j];
				b[j]=b[j+1];
				b[j+1]=c;
			}
}

void design(int c)
{ 	
	c=c%4;
	switch(c)
	{
		case 0:cout<<"梅花";break;
		case 1:cout<<"方塊";break;
		case 2:cout<<"紅心";break;
		case 3:cout<<"黑桃";break;
	}
}

void designr(int r)
{ 	
	r=r%4;
	switch(r)
	{
		case 0:cout<<setw(10)<<"梅花";break;
		case 1:cout<<setw(10)<<"方塊";break;
		case 2:cout<<setw(10)<<"紅心";break;
		case 3:cout<<setw(10)<<"黑桃";break;
	}
}
int main()
{	srand(time(NULL));
	int check[52]={0},a[26]={0},b[26]={0},time=0,d[26]={0},e[26]={0};
	for(int i=0;i<26;i++)
	{	int x,y;
		do{a[time]=rand()%52;
		x=rand()%52;
		}while(check[x]!=0);
		check[x]=1;
		do{b[time]=rand()%52;
		y=rand()%52;
		}while(check[y]!=0);
		check[y]=1;
		time+=1;
	}
	for(int i=0;i<26;i++)
	{
		d[i]=a[i];
		e[i]=b[i];
	}
	number(a);
	number(b);
	for(int i=0;i<26;i++)
	{	int p=d[i],q=e[i];
		design(p);
		cout<<setw(3)<<a[i];
		designr(q);
		cout<<setw(3)<<b[i]<<endl;
		
	}
	
	
	
}
