#include<iostream>
#include <vector>
#include<stdlib.h>
#include<time.h>
#include <climits>
using namespace std;

int compare(int x,int y)
{
	if(x>y)return 2*x;
	else if(x<y) return 2*y;
}


int dice(int x)
{	
	int a=0,b=0,c=0,d=0;
	srand(time(NULL));
	a=rand()%6+1;
	b=rand()%6+1;
	c=rand()%6+1;
	d=rand()%6+1;
	while((a!=b&&a!=c&&a!=d&&b!=c&&b!=d&&c!=d)||(a==b&&b==c&&a!=d)||(a==b&&b==d&&a!=c)||(a==d&&a==c&&a!=b)||(a!=b&&b==c&&b==d)){a=rand()%6+1; b=rand()%6+1; c=rand()%6+1; d=rand()%6+1;}
	cout<<a<<"  "<<b<<"  "<<c<<"  "<<d<<endl;
	if(a==b&&b==c&&c==d)return INT_MAX;
	if(a==b&&c!=d)return c+d;	if(b==c&&a!=d)return a+d;	if(c==d&&a!=b)return a+b;	if(a==d&&b!=c)return b+c;	if(a==c&&b!=d)return b+d; if(a!=c&&b==d)return a+c;
	if(a==b&&c==d)return compare(a,c);	if(a==c&&b==d)return compare(a,b);	if(a==d&&c==b)return compare(a,c);
	
	
}


int main()
{	
	cout<<"十八仔(逗十八仔)\n";
	int host=0;	vector<int> money;	vector<int> score;vector<int>total;	int start,people;
	cout<<"按下任意鍵開始遊戲\n";	cin>>start;
	cout<<"請輸入遊玩人數";	cin>>people;
	money.push_back(host);
	total.push_back(host);
	for(int i=1;i<people;i++)
	{   int stake;
		cout<<"閒家"<<i<<"號請輸入下注金額\n";	cin>>stake;
		money.push_back(stake);
		total.push_back(stake);
	}
	cout<<"先由莊家擲骰子\n"<<"開始執骰請按1\n";	cin>>start;
	int s=dice(start);	score.push_back(s);
	cout<<score[0]<<endl;
	if(score[0]!=INT_MAX)
	{
		for(int i=1;i<people;i++)
		{
			cout<<"由玩家"<<i<<"擲骰子\n"<<"開始執骰請按1\n";	cin>>start;
			int s=dice(start);
			score.push_back(s);
			cout<<score[i]<<endl;
		}
		for(int i=1;i<people;i++)
		{
			if(score[0]>score[i]){total[0]+=money[i];total[i]=0;}
			if(score[0]<score[i]){total[i]+=money[i];total[0]-=money[i];}
		}
		for(int i=0;i<people;i++)
		{if(i==0)cout<<"莊家所剩金額:"<<total[0]<<endl;
		 else cout<<i<<"號閒家所剩金額:"<<total[i]<<endl; 
		}
	}
	else 
	{
		cout<<"莊家獲勝\n";
		for(int i=1;i<people;i++)
		{
			total[0]+=money[i];
		}
		for(int i=0;i<people;i++)
		{
			if(i==0)cout<<"莊家所剩金額:"<<total[0]<<endl;
			else cout<<i<<"號閒家所剩金額:"<<total[i]<<endl; 
		}
	}
	cout<<"是否要繼續玩呢\n";
	cout<<"如果要請按1\n"<<"如果不要請按1以外的任意鍵\n";
	int check;cin>>check;
	
	//second time//

	while(check==1)
	{	money.clear();
		score.clear();
		cout<<"按下任意鍵繼續遊戲\n";	cin>>start;
		money.push_back(host);
		for(int i=1;i<people;i++)
		{   int stake;
			cout<<"閒家"<<i<<"號請輸入下注金額\n";	cin>>stake;
			money.push_back(stake);
			total[i]+=stake;
		}
		cout<<"先由莊家擲骰子\n"<<"開始執骰請按1\n";	cin>>start;
		int s=dice(start);	score.push_back(s);
		cout<<score[0]<<endl;
		if(score[0]!=INT_MAX)
		{
			for(int i=1;i<people;i++)
		{
			cout<<"由玩家"<<i<<"擲骰子\n"<<"開始執骰請按1\n";	cin>>start;
			int s=dice(start);
			score.push_back(s);
			cout<<score[i]<<endl;
		}
		for(int i=1;i<people;i++)
		{
			if(score[0]>score[i]){total[0]+=money[i];total[i]-=money[i];}
			if(score[0]<score[i]){total[i]+=money[i];total[0]-=money[i];}
		}
		for(int i=0;i<people;i++)
		{if(i==0)cout<<"莊家所剩金額:"<<total[0]<<endl;
		 else cout<<i<<"號閒家所剩金額:"<<total[i]<<endl; 
		}
	}
	else 
	{
		cout<<"莊家獲勝\n";
		for(int i=1;i<people;i++)
		{
			host+=money[i];
		}
		for(int i=0;i<people;i++)
		{
			if(i==0)cout<<"莊家所剩金額:"<<total[0]<<endl;
			else cout<<i<<"號閒家所剩金額:"<<total[i]<<endl; 
		}
	}
	cout<<"是否要繼續玩呢\n";
	cout<<"如果要請按1\n"<<"如果不要請按1以外的任意鍵\n";
	cin>>check;
	}
	
}
