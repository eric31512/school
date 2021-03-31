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
	cout<<"  �п�J1��2\n";
	cout<<"1.�I�Ƥj��Ĺ\n";
	cout<<"2.�I�Ƥp��Ĺ\n";
	cin>>j;
	return j;
}


void dice1(int& computer,int& human)
{
	srand (time(NULL));
	int c=rand()%6+1;
	int h=rand()%6+1;
	cout<<"�q��������X���I�Ƭ�"<<c<<endl;
	cout<<"���a������X���I�Ƭ�"<<h<<endl;
	if(c>h) { cout<<"�q�����\n";computer=computer+1;}
	else if(c<h) { cout<<"���a���\n";human=human+1;}
	else if(c=h) { cout<<"���襭��\n";computer=computer+1;human=human+1;}
}



void dice2(int& computer,int& human)
{
	srand (time(NULL));
	int c=rand()%6+1;
	int h=rand()%6+1;
	cout<<"�q��������X���I�Ƭ�"<<c<<endl;
	cout<<"���a������X���I�Ƭ�"<<h<<endl;
	if(c<h) { cout<<"�q�����\n";computer=computer+1;}
	else if(c>h) { cout<<"���a���\n";human=human+1;}
	else if(c=h) { cout<<"���襭��\n";computer=computer+1;human=human+1;}
}




int menu(){
	int i;
	cout<<"          menu"<<endl;
	cout<<"     1. ��J��Ӿ�ơA����洫�ʧ@�A�æC�L���G"<<endl;
	cout<<"     2. ��J��Ӿ�ơA����ۭ��ʧ@�A�æC�L���G"<<endl;
	cout<<"     3. ��J��Ӿ�ơA�������ʧ@�A�æC�L���j��"<<endl;
	cout<<"     4. ��l�C��"<<endl;
	cout<<"     5. ���J�P�C��"<<endl;
	cout<<"     0. ���}�t��"<<endl;
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
		case 0:cout<<"����";break;
		case 1:cout<<"���";break;
		case 2:cout<<"����";break;
		case 3:cout<<"�®�";break;
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
	{	cout<<"��"<<i+1<<"���o�P" <<endl;Sleep(1500);
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
					cout<<"�п�J��Ӿ��"<<endl;
					cin>>x>>y;
					change(x,y);
					cout<<"answer="<<x<<"  "<<y<<endl;	break;		
			case 2: 
					cout<<"�п�J��Ӿ��"<<endl;
					cin>>x>>y;
					cout<<"answer="<<multiply(x,y)<<endl;break;
			case 3: 
					cout<<"�п�J��Ӿ��"<<endl;
					cin>>x>>y;
					cout<<"answer="<<compare(x,y)<<endl;break;
			case 4: 
				{	cout<<"���C���@���Ƥ���\n";
					cout<<"Ĺ���h�������\n";
					cout<<"��l�C���}�l\n";
					int cscore=0,hscore=0,times=0;
					while(times<5)
					{switch(menu2())
						{	case 1: system("cls");
									dice1(cscore,hscore);
									cout<<"�ثe�����:";
									cout<<cscore<<":"<<hscore<<endl;
									times=times+1;
									break;
							case 2: system("cls");
									dice2(cscore,hscore);
									cout<<"�ثe�����:";
									cout<<cscore<<":"<<hscore<<endl;
									times=times+1;
									break;
							default:system("cls");
									cout<<"�ثe�����:";
									cout<<cscore<<":"<<hscore<<endl;
			        				cout<<"wrong input, select again."  <<endl;  
						}
					}
					if(cscore>hscore)cout<<"�̲׳ӧQ�̬��q��\n";
					else if(cscore<hscore)cout<<"�̲׳ӧQ�̬����a\n";
					else if(cscore=hscore)cout<<"���襭��\n";
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
