#include<iostream>
#include<cstring>
using namespace std;
class stnode{
			int no ;
			char name[10];
			int nor;
			int mid;
			int final;
			stnode *ptr;
	public:
		void writeno(int a)
    {
    	no=a;
	}
	void writename(char b[10])
	{
		strcpy(name,b);
	}
	void writenor(int c)
    {
    	nor=c;
	}
	void writemid(int d)
    {
    	mid=d;
	}
	void writefinal(int e)
    {
    	final=e;
	}
	
	int readno()
	{
		return no;
	}
	char readname()
	{
		return *name;
	}
	int readnor()
	{
		return nor;
	}
	int readmid()
	{
		return mid;
	}
	int readfinal()
	{
		return final;
	}
	void writeptr(stnode *a){
		ptr=a;
	}
	stnode* readptr(){
		return ptr;
	}
		
}; 
int menu(){
	int i;
	cout<<"          menu"<<endl;
	cout<<"     1. 輸入一筆資料"<<endl;
	cout<<"     2. 刪除一筆資料"<<endl;
	cout<<"     3. 查詢一筆資料"<<endl;
	cout<<"     4. 列印資料"<<endl;
	cout<<"     0. 離開系統"<<endl;
	cout<<"  Please select your choice  ";
	cin>>i;
	return i;
}
int main(){
	int n=1;
	stnode *p;
	stnode *last;
	stnode *head;
	head=NULL;
	stnode *check;
	int s;
	while(s=menu()){
		int a;
		char b[10];
		switch(s){	
			case 1:	
				check=head;		
				p=new stnode;
				if(head==NULL)
				{last=p;}
				cout<<"請輸入學生的號碼\n";
				cin>>a;
				p->writeno(a);
				cin.get();
				cout<<"請輸入"<<p->readno()<<"號學生的姓名\n";
				cin.getline(b,10);
				p->writename(b);
				cout<<"請輸入第"<<p->readno()<<"位號學生的平時成績\n";
				cin>>a;
				p->writenor(a);
				cout<<"請輸入第"<<p->readno()<<"號學生的期中成績\n";
				cin>>a;
				p->writemid(a);
				cout<<"請輸入第"<<p->readno()<<"號學生的期末成績\n";
				cin>>a;
				p->writefinal(a);
				if(head==NULL||p->readno()<head->readno()){
				p->writeptr(head);
				head=p;
				check=p;
				}
				if(p->readno()>last->readno()){
					last->writeptr(p);
					last=p;
				}
				if(head->readno()<(p->readno())&&last->readno()>p->readno())
				{
					while(check){
					if(check->readno() < p->readno() && check->readptr()->readno() > p->readno())
					{
						p->writeptr(check->readptr());
						check->writeptr(p);
						check=NULL;
					}
					else
						check=check->readptr();
					}
				}
				break;	
			case 2:
				int number;
				cout<<"請輸入欲刪除號碼";
				cin>>number;
				if(head==NULL){
					cout<<"無資料";break;
				}
				if(head->readptr()==NULL&&head->readno()==number){
					head=0;break;
				}
				if(head->readptr()!=0&&head->readno()==number){
					head=head->readptr();break;
				}
				stnode *del;
				check=head;
				if(head->readno()!=number&&head->readptr()!=0)
				{check=check->readptr();
				 del=head;
					while(check){
						if(check->readno()==number){
							del->writeptr(check->readptr());
							check=NULL;	
											
						}
						else{
							check=check->readptr();
							del=del->readptr();
						}
					}
					break;
				}
				case 3:
				int numbersearch;
				cout<<"請輸入欲查詢號碼";
				cin>>numbersearch;
				check=head;
				while(check){
						if(check->readno()==numbersearch){
							cout<<"號碼:"<<check->readno()<<" 姓名:"<<check->readname()<<" 平時:"<<check->readnor()<<" 期中:"<<check->readmid()<<" 期末"<<check->readfinal()<<"\n";
							break;				
						}
						else{
							check=check->readptr();
						}
					}
				break;			
				case 4:
				check=head;
				if(head==NULL){
					cout<<"no data"<<endl;
					break;
				}
				while(check!=NULL)
				{
					cout<<"號碼:"<<check->readno()<<" 姓名:"<<check->readname()<<" 平時:"<<check->readnor()<<" 期中:"<<check->readmid()<<" 期末"<<check->readfinal()<<"\n";
					check=check->readptr();
			
				}break;
			
			default:
				cout<<"wrong input, select again."  <<endl;   
			}
		}
} 


