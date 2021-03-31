#include<iostream>
using namespace std;
int main()
{	
	
    vector<int> selfDividingNumbers(int left, int right) 
    {	cin>>left;
		cin>>right;
        vector<int> a;
        int i,j;
        for(i=left;i<=right;i++)
        {
          j=i;
          int rem,f=0;
          while(j>0 && f!=1)
          {
            rem=j%10;
            if(rem==0 || i%rem!=0)
            {
                f=1;
            }
            j=j/10;
          }
          if(f==0)
          {
            a.push_back(i);
          }
        }
        return a;
    }
}
