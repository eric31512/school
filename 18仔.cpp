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
	cout<<"�Q�K�J(�r�Q�K�J)\n";
	int host=0;	vector<int> money;	vector<int> score;vector<int>total;	int start,people;
	cout<<"���U���N��}�l�C��\n";	cin>>start;
	cout<<"�п�J�C���H��";	cin>>people;
	money.push_back(host);
	total.push_back(host);
	for(int i=1;i<people;i++)
	{   int stake;
		cout<<"���a"<<i<<"���п�J�U�`���B\n";	cin>>stake;
		money.push_back(stake);
		total.push_back(stake);
	}
	cout<<"���Ѳ��a�Y��l\n"<<"�}�l����Ы�1\n";	cin>>start;
	int s=dice(start);	score.push_back(s);
	cout<<score[0]<<endl;
	if(score[0]!=INT_MAX)
	{
		for(int i=1;i<people;i++)
		{
			cout<<"�Ѫ��a"<<i<<"�Y��l\n"<<"�}�l����Ы�1\n";	cin>>start;
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
		{if(i==0)cout<<"���a�ҳѪ��B:"<<total[0]<<endl;
		 else cout<<i<<"�����a�ҳѪ��B:"<<total[i]<<endl; 
		}
	}
	else 
	{
		cout<<"���a���\n";
		for(int i=1;i<people;i++)
		{
			total[0]+=money[i];
		}
		for(int i=0;i<people;i++)
		{
			if(i==0)cout<<"���a�ҳѪ��B:"<<total[0]<<endl;
			else cout<<i<<"�����a�ҳѪ��B:"<<total[i]<<endl; 
		}
	}
	cout<<"�O�_�n�~�򪱩O\n";
	cout<<"�p�G�n�Ы�1\n"<<"�p�G���n�Ы�1�H�~�����N��\n";
	int check;cin>>check;
	
	//second time//

	while(check==1)
	{	money.clear();
		score.clear();
		cout<<"���U���N���~��C��\n";	cin>>start;
		money.push_back(host);
		for(int i=1;i<people;i++)
		{   int stake;
			cout<<"���a"<<i<<"���п�J�U�`���B\n";	cin>>stake;
			money.push_back(stake);
			total[i]+=stake;
		}
		cout<<"���Ѳ��a�Y��l\n"<<"�}�l����Ы�1\n";	cin>>start;
		int s=dice(start);	score.push_back(s);
		cout<<score[0]<<endl;
		if(score[0]!=INT_MAX)
		{
			for(int i=1;i<people;i++)
		{
			cout<<"�Ѫ��a"<<i<<"�Y��l\n"<<"�}�l����Ы�1\n";	cin>>start;
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
		{if(i==0)cout<<"���a�ҳѪ��B:"<<total[0]<<endl;
		 else cout<<i<<"�����a�ҳѪ��B:"<<total[i]<<endl; 
		}
	}
	else 
	{
		cout<<"���a���\n";
		for(int i=1;i<people;i++)
		{
			host+=money[i];
		}
		for(int i=0;i<people;i++)
		{
			if(i==0)cout<<"���a�ҳѪ��B:"<<total[0]<<endl;
			else cout<<i<<"�����a�ҳѪ��B:"<<total[i]<<endl; 
		}
	}
	cout<<"�O�_�n�~�򪱩O\n";
	cout<<"�p�G�n�Ы�1\n"<<"�p�G���n�Ы�1�H�~�����N��\n";
	cin>>check;
	}
	
}
