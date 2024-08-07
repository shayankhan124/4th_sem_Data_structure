#include<iostream>
using namespace std;
class node{
    public:
    int val;
    node*next,*prev;
    node(int v){
        val=v;
        next=NULL;
        prev=NULL;
    }
};

node*create(node*temp){
    int val;
    bool f;
    cout<<"enter 1 to insert data or 0 to delete"<<endl;
    cin>>f;
    if(f==0)return NULL;
    cout<<"enter value"<<endl;
    cin>>val;
    node*t=new node(val);
    t->prev=temp;
    t->next=create(t);
    return t;

}
void print(node*head){
    while(head){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
}
void reverse(node*head,node*prev){
    if(!head)return;
    head->next=head->prev;
    head->prev=prev;
    reverse(head->next,head);
}
int main(){
node *head=create(NULL);
print(head);
cout<<"äfter reverse....."<<endl;
node*tail=head;
node*prev=NULL;
while(tail and tail->next){
    prev=tail;
    tail=tail->next;
}
head=tail;
reverse(tail,NULL);
print(head);


    return 0;
}
