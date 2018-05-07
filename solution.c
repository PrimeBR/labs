#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <regex.h>
#include <stdlib.h>

int isValid(char *filename){
    char *regexp = "^.*.txt$";
    regex_t regexComp;

    if(regcomp(&regexComp, regexp, REG_EXTENDED)){
        return 0;
    }
    return regexec(&regexComp, filename, 0, NULL, 0) == 0;
}

long long int Mul(char *nextDir){
    int value = 0;
	long long int result = 1;
    FILE* file = fopen(nextDir, "r");
    while(!feof(file)){
		fscanf(file, "%d", &value);
			result *= value;
    }
    fclose(file);
	return result;
}

long long int Sum(char *nextDir){
    int value = 0;
	long long int result = 0;
    FILE* file = fopen(nextDir, "r");
    while(!feof(file)){
		fscanf(file, "%d", &value);
			result += value;
    }
    fclose(file);
	return result;
}


long long int listDir(const char* dirPath, char* prevDir){
	long long int result = 0;
	int flag = 0;
	if(!strcmp(prevDir, "mul")){
		result = 1;
		flag = 1;
	}
	if(!strcmp(prevDir, "add")){
		flag = 0;
	}

	char *nextDir = (char*)malloc(strlen(dirPath)*sizeof(char));
	strcpy(nextDir, dirPath);
	DIR *dir = opendir(nextDir);
	if(dir){
        struct  dirent *de = readdir(dir);
		while(de){
			int len = strlen(nextDir);
			strcat(nextDir, "/");
			strcat(nextDir, de->d_name);
			if(de->d_type == DT_DIR && strcmp(".", de->d_name) && strcmp("..", de->d_name)){
				if(flag)
					result *= listDir(nextDir, de->d_name);
				else
					result += listDir(nextDir, de->d_name);
			}
			if(de->d_type == DT_REG && isValid(de->d_name)){
				if (flag)
					result *= Mul(nextDir);
				else
					result += Sum(nextDir);
			}
			nextDir[len] = '\0';
			de = readdir(dir);
		}
	}
	closedir(dir);
	return result;
}

int main(){
    char *tmp = "tmp";
    long long int val = listDir(tmp, "");
    FILE *file = fopen("result.txt", "w");
    fprintf (file, "%lld", val);
    fclose(file);
	return 0;
}
