#include<iostream>
using namespace std;
class employee{
	public:
		string name,address;
		int id,salary;
		employee*next;
		employee(string name,string address,int id,int salary){
			this->name=name;
			this->address=address;
			this->id=id;
			next=NULL;
			this->salary=salary;
		}
};
employee* create(){
	int a;
	cout<<"enter 1 to add node and 0 to exit"<<endl;
	cin>>a;
	if(a==0)return NULL;
	string name,address;
	int id,salary;
	cout<<"enter name\n";
	cin>>name;
	cout<<"enter address\n";
	cin>>address;
	cout<<"enter id\n";
	cin>>id;
	cout<<"enter salary\n";
	cin>>salary;
	employee*t=new employee(name,address,id,salary);
	t->next=create();
	return t;
}
void print(employee*head){
	if(!head)return;
	cout<<head->name<<" "<<head->address<<" "<<head->id<<" "<<head->salary<<endl;
	print(head->next);
}
int main(){
	employee*head=create();
	print(head);
	
	return 0;
}
