#include<iostream>

using namespace std;

double square(double x)
{
	return x*x;
}

int main()
{	int p=5/3;
	unsigned char x;
	cout<<sizeof(x)<<"\n";
	int y = 0;
	auto * a = &y;
	cout<<*a<<"\n";
	auto *q=&p;
	cout<<*q<<"\n";
	const auto *v = &y, u = 6; 
	cout<<*v<<"\n"<<u<<endl;
	const int var=17;
	constexpr double max2=1.4*square(var);
}
