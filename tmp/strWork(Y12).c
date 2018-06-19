#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
    char string[101];
    char fixed[101];
    fgets(string,101,stdin);
    int j = 0;
    int count = 0;
    for (int i = 0; i <strlen(string); i++){
        if(!isdigit(string[i])){
            fixed[j] = string[i];
            j++;
        }
    }

    for (int i = 0; i <strlen(fixed); i++)
        fixed[i] = (char)toupper(fixed[i]);
    
    char* buffer[20];
    char* tok = strtok(fixed, " ");
    while(tok != NULL){
        buffer[count] = tok;
        count++;
        tok = strtok(NULL, " \n");
    }

    for(int i = 0; i < count; i++){
        for(int k = strlen(buffer[i]); k >= 0; k--)
            printf("%c", buffer[i][k]);
        printf(" ");
    }

}