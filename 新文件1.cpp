#include<iostream>
using namespace std;
int main()
{
	int n,x=1,y;
	cout<<"請輸入一個正整數"<<endl;
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
