#include<iostream>
using namespace std;
class Node{
	public:
		int val;
		Node*next;
		Node(int val){
			this->val=val;
			next=NULL;
		}
};
Node*create(){
	int a;
	cout<<"enter 1 to add node and 0 to quit"<<endl;
	cin>>a;
	if(!a)return NULL;
	int val;
	cout<<"enter the value of the node"<<endl;
	cin>>val;
	Node*t=new Node(val);
	t->next=create();
	return t;
}
void print(Node*head){
	if(!head)return;
	cout<<head->val<<" ";
	print(head->next);
}
void del(Node*trav,Node*&head,Node*prev,int target){
	if(!trav)return;
	if(trav->val==target){
		if(!prev){
			head=head->next;
			trav->next=NULL;
			delete trav;
		}else{
			prev->next=trav->next;
			trav->next=NULL;
			delete trav;
			return;
		}
		return;
	}
	del(trav->next,head,trav,target);
}
int main(){
	
	Node*head=create();
	int target;
	cout<<"enter the value of node you want to delete"<<endl;
	cin>>target;
	cout<<"before deletion"<<endl;
	print(head);
	cout<<endl;
	del(head,head,NULL,target);
	cout<<"after deletion"<<endl;
	print(head);
	cout<<endl;
	return 0;
}
