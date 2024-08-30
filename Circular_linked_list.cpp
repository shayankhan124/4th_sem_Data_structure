#include<bits/stdc++.h>
using namespace std;

// #LinkedList #BasicProblem
// tail is stored as it needs to be updated for certain operations

class node{
    public:
    int data;
    node* next;
    node(){
        data=0;
        next=NULL;
    }
    node(int x){
        data=x;
        next=NULL;
    }
};
class Cirll{
    public:
    node* head;
    node* tail;
    Cirll(){
        head=NULL;
        tail=NULL;
    }
    bool isEmpty(); //checks if the ll is empty
    node* getLastNode(); //returns address of the tail of ll
    void printList(); //prints entire ll
    void addAtEnd(int x); //adds an element at the end of ll
    void addAtFront(int x); //adds an element at the front of ll
    void inserter(int x,int n); //inserts x at nth node's position indexing from 1
    node* searcher(int x); //searches for element x and returns its node address
    bool delAtEnd(); //deletes last node and tells if deletion is successfully performed
    bool delAtFront(); //deletes head node and tells if deletion is successfully performed
    bool deleter(int n); //deletes the nth node indexing from 1 and tells if deletion is successfully performed
};
bool Cirll :: isEmpty(){     //checks if the ll is empty
    if(head==NULL){
        return true;
    }
    return false;
}
node* Cirll :: getLastNode(){    //returns address of the tail of ll
    if(head==NULL){
        return head;
    }else{
        if(tail==NULL){
            tail=head;
            while(tail->next!=head){
                tail=tail->next;
            }
        }
        return tail;
    }
}
void Cirll :: printList(){
    if(head==NULL){
        cout<<"List Empty!"<<endl;
    }else{
        node* temp=head;
        cout<<temp->data<<" ";
        temp=temp->next;
        while(temp!=head){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
    cout<<endl;
}
void Cirll :: addAtEnd(int x){
    node* n1=new node(x);
    n1->next=head; //   changing next from NULL to head everytime a new node is created
    if(head==NULL){
        head=n1;
        tail=n1;    // updating tail
    }else{
        node* last=getLastNode();
        last->next=n1;
        tail=n1;    // updating tail
    }
    //delete(n1); // to delete n1 from memory [DON'T DELETE when ADDing a node]
}
void Cirll :: addAtFront(int x){
    node* n1=new node(x);
    n1->next=head; //   changing next from NULL to head everytime a new node is created
    if(head==NULL){
        head=n1;
        tail=n1;    // updating tail
    }else{
        n1->next=head;
        head=n1;
        tail->next=head;    // updating tail
    }
    //delete(n1); // to delete n1 from memory [DON'T DELETE when ADDing a node]
}
void Cirll ::  inserter(int x,int n){
    if(n==1){
        addAtFront(x);
    }else{
        node* n1=new node(x);
        n1->next=head; //   changing next from NULL to head everytime a new node is created
        node* temp=head;
        int pos=2;
        while(pos<n){
            temp=temp->next;
            pos++;
        }
        n1->next=temp->next;
        temp->next=n1;
        if(n1->next==head){
            tail=n1;    // updating tail if n1 is inserted at end
        }
        //delete(n1); // to delete n1 from memory [DON'T DELETE when ADDing a node]
    }
}
node* Cirll :: searcher(int x){
    int pos=2; //to find position of node is necessary
    node* temp=head;
    if(temp->data==x){
            pos=1; // if head is the reqd node
        return temp;
    }else{
        temp=temp->next;
        while(temp!=head){
            if(temp->data==x){
                break;
            }else{
                pos++;
                temp=temp->next;
            }
        }
        return temp;
    }
}
bool Cirll :: delAtEnd(){
    if(head==NULL){
        return false;
    }else{
        node* temp=head;
        while(temp->next->next!=head){
            temp=temp->next;
        }
        node* temp1=temp->next;
        temp->next=head;
        tail=temp;  // updating tail
        delete(temp1); // to delete the last node from memory
        return true;
    }
}
bool Cirll :: delAtFront(){
    if(head==NULL){
        return false;
    }else{
        node* temp=head;
        head=temp->next;
        tail->next=head; // updating tail
        delete(temp); // to delete the previous head node from memory
        return true;
    }
}
bool Cirll :: deleter(int n){
    if(n==1){
        return delAtFront();
    }else{
        int pos=1;
        node* temp=head;
        while(pos<n-1){
            temp=temp->next;
            pos++;
        }
        node* temp1=temp->next;
        temp->next=temp->next->next;
        if(temp->next==head){
            tail=temp;  // if tail is going to be deleted update tail
        }
        delete(temp1); // to delete the previous node from memory
        return true;
    }
}
int main(){
    Cirll l1;
    l1.addAtEnd(2);
    l1.addAtEnd(2);
    l1.addAtEnd(2);
    l1.addAtEnd(2);
    l1.addAtFront(3);
    l1.printList();
    l1.inserter(5,1);
    l1.inserter(5,3);
    l1.printList();
    node * n1=l1.searcher(5);
    cout<<n1->data<<endl;
    if(l1.delAtEnd()==true){
        l1.printList();
    }else{
        cout<<"List Empty!"<<endl;
    }
    if(l1.delAtFront()==true){
        l1.printList();
    }else{
        cout<<"List Empty!"<<endl;
    }
    if(l1.deleter(2)==true){
        l1.printList();
    }else{
        cout<<"List Empty!"<<endl;
    }
    return 0;
}