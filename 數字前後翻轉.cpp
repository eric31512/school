#include<iostream>
using namespace std;

int main()
{
	int num;
	cin>>num;
	int s=num%10;
	num/=10;
	while(num>0){
		if (s > INT_MAX/10 || (s == INT_MAX / 10 && num > 7)) {cout<<"error";return 0;}
        if (s < INT_MIN/10 || (s == INT_MIN / 10 && num < -8)) {cout<<"error";return 0;}
        s=10*s+num%10;
		num/=10;
	}
	cout<<s;
 } 
