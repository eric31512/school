#include <windows.h>
#include<iostream>
#include <iomanip>
using namespace std;
int main()
{
	int h,m,s;
	cout<<"請輸入時間:幾點:幾分:幾秒"<<endl;
	cout<<"          (<24)(<60)(<60)"<<endl;
	cin>>h>>m>>s;
	while(h<0||h>23||m<0||m>60||s<0||s>60)
	{
		cout<<"請重新輸入時間:幾點:幾分:幾秒"<<endl;
		cout<<"          (<24)(<60)(<60)"<<endl;
		cin>>h>>m>>s;
	}
	while(true)
	{	system("cls");
		if(s==60)
		{
			m++;
			s=0;
		}
		if(m==60)
		{
			h++;
			m=0;
		} 
		if(h==24)
		{
			h=0,m=0,s=0;
		}
		cout<<"時間為:";
		cout<<setfill('0')<<setw(2)<<h<<":"<<setfill('0')<<setw(2)<<m<<":"<<setfill('0')<<setw(2)<<s;
		Sleep(1000);
		s++;
		
		
	}
 } 
