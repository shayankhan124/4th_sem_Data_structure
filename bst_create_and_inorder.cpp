#include<iostream>
using namespace std;
class Node{
	public:
		int val;
		Node*left,*right;
		Node(int val){
			right=NULL;
			left=NULL;
			this->val=val;
		}
};
void create(Node*root,int val){
	if(root->val>val){
		if(root->left){
		create(root->left,val);	
		}else{
			Node*t=new Node(val);
			root->left=t;
			return;
		}
	}else{
	if(root->right){
		create(root->right,val);
	}else{
		Node*t=new Node(val);
		root->right=t;
		return;
	}	
	}
}
void inorder(Node*root){
	if(!root)return;
	inorder(root->left);
	cout<<root->val<<" ";
	inorder(root->right);
}
int main(){
Node*root=NULL;
int n;
puts("enter number of nodes");
cin>>n;
for(int i=0;i<n;i+=1){
	int val;
	cout<<"enter the value of "<<i+1<<" node";
	cin>>val;
	if(!root)root=new Node(val);
	else create(root,val);
}	
inorder(root);
	
	return 0;
}
