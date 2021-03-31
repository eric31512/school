#include<iostream>
using namespace std;
int main()
{
	int n,y=1,z;
	cin>>n;
	for(int x=n;x>0;x=x/10)
	{
	int r=x%10;
	y*=r;
	z+=r;
	}
	cout<<y-z;
}
