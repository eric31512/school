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
		switch(s){	
		case 1:	
			check=head;		
			p=new stnode;
			if(head==NULL)
			{last=p;}
			cout<<"�п�J�ǥͪ����X\n";
			cin>>p->no;
			cin.get();
			cout<<"�п�J"<<p->no<<"���ǥͪ��m�W\n";
			cin.getline(p->name,10);
			cout<<"�п�J��"<<p->no<<"�츹�ǥͪ����ɦ��Z\n";
			cin>>p->nor;
			cout<<"�п�J��"<<p->no<<"���ǥͪ��������Z\n";
			cin>>p->mid;
			cout<<"�п�J��"<<p->no<<"���ǥͪ��������Z\n";
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
			cout<<"�п�J���R�����X";
			cin>>number;
			if(head==NULL){
				cout<<"�L���";break;
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
			cout<<"�п�J���d�߸��X";
			cin>>numbersearch;
			check=head;
			while(check){
					if(check->no==numbersearch){
						cout<<"���X:"<<check->no<<" �m�W:"<<check->name<<" ����:"<<check->nor<<" ����:"<<check->mid<<" ����"<<check->final<<"\n";
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
				cout<<"���X:"<<check->no<<" �m�W:"<<check->name<<" ����:"<<check->nor<<" ����:"<<check->mid<<" ����"<<check->final<<"\n";
				check=check->ptr;
		
			}break;
		
		default:
			cout<<"wrong input, select again."  <<endl;   
		}
	}
	cout<<"Thank for your using";
} 

