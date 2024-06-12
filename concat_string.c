#include<stdio.h>
int main(){
	
	char first[]="shayan";
	char second[]="khan";
	printf("%s\n",first);
	printf("%s\n",second);
	int first_size=5,second_size=4;
	char ans[9];
	int i=0;
	int index=0;
	while(first[i]!='\0'){
		ans[index++]=first[i++];
	}
	i=0;
	while(second[i]!='\0'){
		ans[index++]=second[i++];
	}
	printf("%s\n",ans);
	return 0;
}
