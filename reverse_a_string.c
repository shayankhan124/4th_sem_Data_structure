#include<stdio.h>
int main(){
	
	char arr[6]="shayan";
	int end=0;
	printf("%s\n",arr);
	while(arr[end]!='\0')end+=1;
	end-=1;
	int start=0;
	while(start<=end){
		char ch=arr[start];
		arr[start]=arr[end];
		arr[end]=ch;
		start+=1;
		end-=1;
	}
	printf("%s",arr);
	return 0;
}
