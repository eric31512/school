#include<iostream>
#include<cstring>
using namespace std;
class stnode{
	public:
		int no ;
		char name[10];
		int nor;
		int mid;
		int final;
		stnode *ptr;
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
		switch(s){	
		case 1:	
			check=head;		
			p=new stnode;
			if(head==NULL)
			{last=p;}
			cout<<"請輸入學生的號碼\n";
			cin>>p->no;
			cin.get();
			cout<<"請輸入"<<p->no<<"號學生的姓名\n";
			cin.getline(p->name,10);
			cout<<"請輸入第"<<p->no<<"位號學生的平時成績\n";
			cin>>p->nor;
			cout<<"請輸入第"<<p->no<<"號學生的期中成績\n";
			cin>>p->mid;
			cout<<"請輸入第"<<p->no<<"號學生的期末成績\n";
			cin>>p->final;
			if(head==NULL||p->no<head->no){
				p->ptr=head;
				head=p;
				check=p;
			}
			if(p->no>last->no){
				last->ptr=p;
				last=p;
			}
			if(head->no<(p->no)&&last->no>p->no)
			{
				while(check){
				if(check->no<p->no&&check->ptr->no>p->no){
					p->ptr=check->ptr;
					check->ptr=p;
					check=NULL;
				}
				else
					check=check->ptr;
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
			if(head->ptr==NULL&&head->no==number){
				head=0;break;
			}
			if(head->ptr!=0&&head->no==number){
				head=head->ptr;break;
			}
			stnode *del;
			check=head;
			if(head->no!=number&&head->ptr!=0)
			{check=check->ptr;
			 del=head;
				while(check){
					if(check->no==number){
						del->ptr=check->ptr;
						check=NULL;	
										
					}
					else{
						check=check->ptr;
						del=del->ptr;
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
					if(check->no==numbersearch){
						cout<<"號碼:"<<check->no<<" 姓名:"<<check->name<<" 平時:"<<check->nor<<" 期中:"<<check->mid<<" 期末"<<check->final<<"\n";
						break;				
					}
					else{
						check=check->ptr;
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
				cout<<"號碼:"<<check->no<<" 姓名:"<<check->name<<" 平時:"<<check->nor<<" 期中:"<<check->mid<<" 期末"<<check->final<<"\n";
				check=check->ptr;
		
			}break;
		
		default:
			cout<<"wrong input, select again."  <<endl;   
		}
	}
	cout<<"Thank for your using";
} 

