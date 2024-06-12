#include<stdio.h>
int main(){
	char arr[]="name";
	int n=4;
	printf("%s\n",arr);
	int i=0;
	for(i=0;i<4;i+=1){
		arr[i]-=32;
	}
	printf("%s\n",arr);
	
	
	return 0;
}
