#include<iostream>
using namespace std;
int main()
{
	int x,y,z,q;
	cin>>x>>y>>z>>q;
	while(x==y==z==q||x==y==z!=q||x==y==q!=z||x==z==q!=y||x!=y==z==q)
	{
		cout<<"wrong input";
		cin>>x>>y>>z>>q;
	}
}
