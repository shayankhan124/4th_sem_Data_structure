#include<stdio.h>
int is_palindrome(char arr[],int n){
	int end=n-1,start=0;
	while(start<=end){
		if(arr[start]!=arr[end])return 0;
		start+=1;
		end-=1;
	}
	return 1;
}
int main(){
	
	char arr[5]="hello";
	int n=5;
	if(is_palindrome(arr,n)){
		printf("is palindrome");
	}else printf("is not a palindrome");
	
	return 0;
}
