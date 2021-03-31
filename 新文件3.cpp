#include<iostream>
using namespace std;
int main()
{
	int left,right,s;
	cin>>left;
	cin>>right;
	int x=left;
	while(x<=right)
	{	
		int y=x;
		while(y>0)
		{
			int r=y%10;
			s+=(left%r);
			y=y/10;
		}
		if(s==0)
		{cout<<x;}
	x++;
	}
	 
}
