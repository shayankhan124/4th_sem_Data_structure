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

void insert(int val,Node*trav,int target){
	if(!trav)return;
	if(trav->val==target){
		Node*t=trav->next;
		Node*temp=new Node(val);
		temp->next=t;
		trav->next=temp;
		return;
	}
	insert(val,trav->next,target);
}
void print(Node*head){
	if(!head)return;
	cout<<head->val<<" ";
	print(head->next);
}
int main(){
	Node*head=create();
	int val,target;
	cout<<"enter the value of node after which you want to insert the new node"<<endl;
	cin>>target;
	cout<<"enter the value of the new node"<<endl;
	cin>>val;
	cout<<"before insertion"<<endl;
	print(head);
	cout<<endl;
	insert(val,head,target);
	cout<<"after insertion"<<endl;
	print(head);
	cout<<endl;
	
	return 0;
}
