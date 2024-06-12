#include<iostream>
using namespace std;
struct Book{
	char publisher[100];
	char name[100];
	int pages;
	float price;
	struct Book *next;
	
};
void insert_name(struct Book *s,int n,char name[]){
	int i=0;
	for(i=0;i<n;i+=1){
		s->name[i]=name[i];
	}
	
}
void insert_publisher(struct Book *s,int n,char publisher[]){
	int i=0;
	for(i=0;i<n;i+=1){
		s->publisher[i]=publisher[i];
	}
	
}
void print(struct Book *s){
	while(s){
		int i=0;
		while(s->name[i]!='\0')cout<<s->name[i++]<<" ";
		if(s->next==NULL)break;
		cout<<endl;
		s=s->next;
	}
}
int main(){
	struct Book s1,s2,s3;
	int i=0;
	s3.next=NULL;
	for(i=0;i<3;i+=1){
		if(i==0){
			char f[]="first";
		insert_publisher(&s1,5,f);

		}
		else if(i==1){
			char s[]="second";
			insert_publisher(&s2,6,s);
		}
		else{
			char t[]="third";
			insert_publisher(&s3,5,t);
		} 
		
	}
		for(i=0;i<3;i+=1){
		if(i==0){
			char f[]="first_book_name\0";
		insert_name(&s1,17,f);

		}
		else if(i==1){
			char s[]="second_book_name\0";
			insert_name(&s2,17,s);
		}
		else{
			char t[]="third_book_name\0";
			insert_name(&s3,16,t);
		} 
	}
		
	
	s1.next=&s2;
	s2.next=&s3;
	print(&s1);
	
	return 0;
}
