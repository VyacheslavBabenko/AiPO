#include<stdio.h>
#include<string.h>
#include<dirent.h>

int main(){
	char planet[1001];
	scanf("%s",&planet);
	char c[1001],file[1001];
	memset(c,0,sizeof(c));
	DIR* dir=opendir("planets");
	struct dirent* ent=readdir(dir);
	while(ent!= NULL){
		strcpy(file,"planets\\");
		strcat(file,ent -> d_name);
		FILE* f=fopen(file,"r");
		if(f!=NULL){
			fscanf(f,"%s",&c);
			if(!strcmp(c,planet)) 
				printf("%s\n",ent -> d_name);
			memset(c,0,sizeof(c));
			fclose(f);
		}
		ent=readdir(dir);
	}
	closedir(dir);
	return 0;
}
