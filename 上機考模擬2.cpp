#include <iostream>
#include<cstdlib>
#include<ctime> 
#include <windows.h>
#include<iomanip>
using namespace std;

void change(int&a,int&b)
{
	int t=a;
	a=b;
	b=t;
}
int multiply(int a,int b)
{
	int s=a*b;
	return s;
}
int compare(int a,int b)
{
	if(a>b) return a;
	else return b;
}

int menu2()
{	int j;
	cout<<"  請輸入1或2\n";
	cout<<"1.點數大的贏\n";
	cout<<"2.點數小的贏\n";
	cin>>j;
	return j;
}


void dice1(int& computer,int& human)
{
	srand (time(NULL));
	int c=rand()%6+1;
	int h=rand()%6+1;
	cout<<"電腦此次骰出的點數為"<<c<<endl;
	cout<<"玩家此次骰出的點數為"<<h<<endl;
	if(c>h) { cout<<"電腦獲勝\n";computer=computer+1;}
	else if(c<h) { cout<<"玩家獲勝\n";human=human+1;}
	else if(c=h) { cout<<"雙方平手\n";computer=computer+1;human=human+1;}
}



void dice2(int& computer,int& human)
{
	srand (time(NULL));
	int c=rand()%6+1;
	int h=rand()%6+1;
	cout<<"電腦此次骰出的點數為"<<c<<endl;
	cout<<"玩家此次骰出的點數為"<<h<<endl;
	if(c<h) { cout<<"電腦獲勝\n";computer=computer+1;}
	else if(c>h) { cout<<"玩家獲勝\n";human=human+1;}
	else if(c=h) { cout<<"雙方平手\n";computer=computer+1;human=human+1;}
}




int menu(){
	int i;
	cout<<"          menu"<<endl;
	cout<<"     1. 輸入兩個整數，執行交換動作，並列印結果"<<endl;
	cout<<"     2. 輸入兩個整數，執行相乘動作，並列印結果"<<endl;
	cout<<"     3. 輸入兩個整數，執行比較動作，並列印較大值"<<endl;
	cout<<"     4. 骰子遊戲"<<endl;
	cout<<"     5. 撲克牌遊戲"<<endl;
	cout<<"     0. 離開系統"<<endl;
	cout<<"  Please select your choice  ";
	cin>>i;
	return i;
}



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
		case 0:cout<<"梅花";break;
		case 1:cout<<"方塊";break;
		case 2:cout<<"紅心";break;
		case 3:cout<<"黑桃";break;
	}
}


void compare2(int p,int q,int r,int s,int &t,int &u)
{
	if(p>q){cout<<setw(3)<<"player 1 win"<<endl;t+=1;}
	else if(p<q){cout<<setw(3)<<"player 2 win"<<endl;u+=1;}
	else if(p=q)
	{   
		r%=4;s%=4;
		if(r>s){cout<<setw(3)<<"player 1 win"<<endl;t+=1;}
		if(r<s){cout<<setw(3)<<"player 2 win"<<endl;u+=1;}
	}
	Sleep(1000);
	cout<<setw(7)<<t<<setw(4)<<":"<<setw(4)<<u<<endl;cout<<endl;
}




void pokemain(int pp)
{
	int player1[26],player2[26],player1plus[26],player2plus[26];
	set(player1,player2);	set(player1plus,player2plus);
	number(player1);	number(player2);
	int p1win=0,p2win=0;
	for(int i=0;i<26;i++)
	{	cout<<"第"<<i+1<<"次發牌" <<endl;Sleep(1500);
		int x=player1plus[i];	int y=player2plus[i];
		colar(x);cout<<setw(3)<<player1[i]<<"  ";
		colar(y);cout<<setw(3)<<player2[i]<<"  ";Sleep(1000);
		int z=player1[i];	int v=player2[i];
		compare2(z,v,x,y,p1win,p2win);
		Sleep(2000);
	}
	cout<<setw(7)<<p1win<<setw(3)<<":"<<setw(3)<<p2win<<endl;
	if(p1win>p2win)cout<<"player 1 win at final";
	else if(p1win<p2win)cout<<"player 2 win at final";
	else if(p1win=p2win)cout<<"draw";
}


int main() {
	int s;
	while(s=menu())
	{system("cls");
		switch(s){int x,y;
			case 1: 
					cout<<"請輸入兩個整數"<<endl;
					cin>>x>>y;
					change(x,y);
					cout<<"answer="<<x<<"  "<<y<<endl;	break;		
			case 2: 
					cout<<"請輸入兩個整數"<<endl;
					cin>>x>>y;
					cout<<"answer="<<multiply(x,y)<<endl;break;
			case 3: 
					cout<<"請輸入兩個整數"<<endl;
					cin>>x>>y;
					cout<<"answer="<<compare(x,y)<<endl;break;
			case 4: 
				{	cout<<"本遊戲共重複五次\n";
					cout<<"贏較多次者獲勝\n";
					cout<<"骰子遊戲開始\n";
					int cscore=0,hscore=0,times=0;
					while(times<5)
					{switch(menu2())
						{	case 1: system("cls");
									dice1(cscore,hscore);
									cout<<"目前比分為:";
									cout<<cscore<<":"<<hscore<<endl;
									times=times+1;
									break;
							case 2: system("cls");
									dice2(cscore,hscore);
									cout<<"目前比分為:";
									cout<<cscore<<":"<<hscore<<endl;
									times=times+1;
									break;
							default:system("cls");
									cout<<"目前比分為:";
									cout<<cscore<<":"<<hscore<<endl;
			        				cout<<"wrong input, select again."  <<endl;  
						}
					}
					if(cscore>hscore)cout<<"最終勝利者為電腦\n";
					else if(cscore<hscore)cout<<"最終勝利者為玩家\n";
					else if(cscore=hscore)cout<<"雙方平手\n";
					break;
				}		
			case 5:
			{
				int start;
				cout<<"please press 1 to start the game\n";
				cin>>start;
				while(true)
				{
					switch(start)
					{
						case 1:
								pokemain(start);break;
						default:
								cout<<"wrong press,please press 1\n";break;
					}
					if(start==1)break;
					else
					{
						
						cin>>start;
					}
				}
							
				break;
			}																						
			default:
			        cout<<"wrong input, select again."  <<endl;     
		}
		
	}
	cout<<"Thanks for using, bye."<<endl;
}
