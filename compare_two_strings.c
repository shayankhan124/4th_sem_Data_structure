#include<stdio.h>
int check(char first[],char second[],int first_size,int second_size){
	
	if(first_size!=second_size)return 0;
	int i=0;
	for(i=0;i<first_size;i+=1){
		if(first[i]!=second[i])return 0;
	}
	return 1;
}
int main(){
	char first[6]="shayan";
	char second[6]="khan";
	int first_size=6,second_size=6;
	if(check(first,second,first_size,second_size)){
		printf("equal");
	}else printf("not equal");
	return 0;
}
