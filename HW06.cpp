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
	cout<<"     1. ��J�@�����"<<endl;
	cout<<"     2. �R���@�����"<<endl;
	cout<<"     3. �d�ߤ@�����"<<endl;
	cout<<"     4. �C�L���"<<endl;
	cout<<"     0. ���}�t��"<<endl;
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
				cout<<"�п�J�ǥͪ����X\n";
				cin>>a;
				p->writeno(a);
				cin.get();
				cout<<"�п�J"<<p->readno()<<"���ǥͪ��m�W\n";
				cin.getline(b,10);
				p->writename(b);
				cout<<"�п�J��"<<p->readno()<<"�츹�ǥͪ����ɦ��Z\n";
				cin>>a;
				p->writenor(a);
				cout<<"�п�J��"<<p->readno()<<"���ǥͪ��������Z\n";
				cin>>a;
				p->writemid(a);
				cout<<"�п�J��"<<p->readno()<<"���ǥͪ��������Z\n";
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
				cout<<"�п�J���R�����X";
				cin>>number;
				if(head==NULL){
					cout<<"�L���";break;
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
				cout<<"�п�J���d�߸��X";
				cin>>numbersearch;
				check=head;
				while(check){
						if(check->readno()==numbersearch){
							cout<<"���X:"<<check->readno()<<" �m�W:"<<check->readname()<<" ����:"<<check->readnor()<<" ����:"<<check->readmid()<<" ����"<<check->readfinal()<<"\n";
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
					cout<<"���X:"<<check->readno()<<" �m�W:"<<check->readname()<<" ����:"<<check->readnor()<<" ����:"<<check->readmid()<<" ����"<<check->readfinal()<<"\n";
					check=check->readptr();
			
				}break;
			
			default:
				cout<<"wrong input, select again."  <<endl;   
			}
		}
} 


