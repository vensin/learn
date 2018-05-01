#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	FILE *fp;
	int i,count;
	printf("请输入生成的数据量：");
	scanf("%d",&count);
	fp=fopen("10000000.txt","w+");
	for(i=1;i<=count;i++)
	{
			fprintf(fp,"%d",Random(0,1000));
			fputc(' ' ,fp);
	}

	
	return 0;
}
int Random(int start, int end){
    int dis = end - start;
    return rand() % dis + start;
}
