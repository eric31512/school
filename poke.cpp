#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<iomanip>

using namespace std;

void set(int one[],int two[])
{	srand(time(NULL));
	int check[52]={0};
	for(int i=0;i<26;i++)
	{	int x,y;
		do{
		one[i]=rand()%52;
		x=one[i];
		}while(check[x]!=0);
		check[x]=1;
		do{
		two[i]=rand()%52;
		y=two[i];
		}while(check[y]!=0);
		check[y]=1;
		
	}
}

void number(int p[])
{
	for(int i=0;i<26;i++)
	{
		p[i]/=4;
		p[i]+=1;
		
	}
}

void colar(int p)
{
	p%=4;
	switch(p)
	{
		case 0:cout<<"±öªá";break;
		case 1:cout<<"¤è¶ô";break;
		case 2:cout<<"¬õ¤ß";break;
		case 3:cout<<"¶Â®ç";break;
	}
}


void compare(int p,int q,int r,int s,int &t,int &u)
{
	if(p>q){cout<<setw(3)<<"player 1 win"<<endl;t+=1;}
	else if(p<q){cout<<setw(3)<<"player 2 win"<<endl;u+=1;}
	else if(p=q)
	{   
		r%=4;s%=4;
		if(r>s){cout<<setw(3)<<"player 1 win"<<endl;t+=1;}
		if(r<s){cout<<setw(3)<<"player 2 win"<<endl;u+=1;}
	}
	cout<<setw(7)<<t<<setw(3)<<":"<<setw(3)<<u<<endl;cout<<endl;
}

using namespace std;
int main()
{
	int player1[26],player2[26],player1plus[26],player2plus[26];
	set(player1,player2);	set(player1plus,player2plus);
	number(player1);	number(player2);
	int p1win=0,p2win=0;
	for(int i=0;i<26;i++)
	{
		int x=player1plus[i];	int y=player2plus[i];
		colar(x);cout<<setw(3)<<player1[i];
		colar(y);cout<<setw(3)<<player2[i]<<"     ";
		int z=player1[i];	int v=player2[i];
		compare(z,v,x,y,p1win,p2win);
	}
	cout<<setw(7)<<p1win<<setw(3)<<":"<<setw(3)<<p2win<<endl;
	if(p1win>p2win)cout<<"player 1 win at final";
	else if(p1win<p2win)cout<<"player 2 win at final";
	else if(p1win=p2win)cout<<"draw";
	system("pause");
} 
