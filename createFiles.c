#include <stdio.h>
//将原数据分成1/8、1/4、1/2、1倍数
#include<stdio.h>
#include<stdlib.h>

void createFiles(){
	FILE *fp,*fp_out;
	fp=fopen("user_login.txt","r");
	// fp_out=fopen("divide 2 data.txt","w");
	// fp_out = fopen("divide 4 data.txt", "w");
	fp_out = fopen("divide 8 data.txt", "w");

	if(fp==NULL||fp_out==NULL){
		printf("error!\n");
		return ;
	}
	int tot=1e5;
	// int cnt_2 = tot / 2;
	// int cnt_4 = tot / 4;
	int cnt_8 = tot / 8;
	int i=0;
	while(!feof(fp)){
		char message[60];
		fscanf(fp,"%s",message);
		i++;
		if(i<=cnt_8){
			
			if(i!=cnt_8) fprintf(fp_out,"%s\n",message);
			else fprintf(fp_out,"%s",message);
		}
		else break;
	}
	fclose(fp);
	fclose(fp_out);
}