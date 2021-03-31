#include<iostream> 
using namespace std; 
int main()
{
	double a,b,c,m,n;
	cout<<"有一函式ax^m+bx^n+c"<<endl;
	cout<<"請輸入次方m,n"<<endl;
	cin>>m;
	cin>>n;
	while(n<=0||m<=0||m<=n)
	{
	cout<<"請重新輸入次方m,n"<<endl;
	cin>>m; cin>>n;	
	}
	cout<<"請輸入a,b,c"<<endl;
	cin>>a; cin>>b; cin>>c;
	while(a==0)
	{
	cout<<"請重新輸入a,b,c"<<endl;
	cin>>a; cin>>b; cin>>c;
	}
	if(b>0)
	cout<<a*m<<"x^"<<m-1<<"+"<<b*n<<"x^"<<n-1;
	else
	cout<<a*m<<"x^"<<m-1<<"-"<<-1*b*n<<"x^"<<n-1;
	system("pause");
}
