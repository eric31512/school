#include<iostream>
using namespace std;
int main()
{
	int n,x=1,y;
	cout<<"�п�J�@�ӥ����"<<endl;
	cin>>n;
	while(n>0)
	{	cout<<"aaa";
		int z=n%10;
		x*=z;
		y+=z;
		n=n/10;
	}

	cout<<x-y;
 } 
