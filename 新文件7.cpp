#include<iostream>
using namespace std;

int main()
 {
 	int m;
 	cin>>m;
 	while(m>=10)
 	{
 	int s=m%10;
	m/=10;
	m=m+s;
	 }
	 cout<<m;
 }
