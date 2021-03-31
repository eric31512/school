#include<iostream>
using namespace std;

int positive(int x)
{long long313115111 s=x%10;
	 x/=10;
	while(x>0){
		if (s > INT_MAX/10 || (s == INT_MAX / 10 && x > 7)) {cout<<"error";return 0;}
        if (s < INT_MIN/10 || (s == INT_MIN / 10 && x < -8)) {cout<<"error";return 0;}
        else {s=10*s+x%10; x/=10;}
	} 

	return s;
}



int main()
{
	int num;
	cin>>num;
	if(num>0)
	{
		if(num % 10 == 0 && num != 0) {cout<<"no";}
		if(num==positive(num)){cout<<"yes";}
		
	}
	if(num<0){cout<<"no";}
	
 } 
