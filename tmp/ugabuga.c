#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
    int size = 50;
    int count = 0;
    int m = 20;
    int val = 0;
    char** unknown = (char**)malloc(sizeof(char*)*size);
    char** known = (char**)malloc(sizeof(char*)*size);
    char* words = (char*)malloc(sizeof(char)*100);
    for(int i = 0; i<size; i++){
        unknown[i]=(char*)malloc(sizeof(char)*m);
        known[i]=(char*)malloc(sizeof(char)*m);
    }
    for(int i = 0; i<size; ++i){  
                scanf("%s ", unknown[i]);
                if(!strcmp(unknown[i],"ugabuga"))
                    break;
                scanf("%s", known[i]);
                val++;
    }
    fgets(words, 100, stdin);
    for(int i = 0; i < strlen(words); i++)
        words[i] = (char)tolower(words[i]);

    char *buffer[sizeof(words)];
    char *string = strtok(words," \n");
    while(string != NULL){
        buffer[count] = string;
        count++;
        string = strtok(NULL, " \n");
    }

	int flag1 = 0, flag2;
	for (int i = 0; i < count; i++){
		for (int j = 0; j < val; j++){
			if (!strcmp(buffer[i], unknown[j])){
				flag1++;
				flag2 = j;
			}
		}
		if (flag1)
			printf("%s ", known[flag2]);
		else
			printf("<unknown> ");
		flag1 = 0;
		flag2 = 0;
	}  
}