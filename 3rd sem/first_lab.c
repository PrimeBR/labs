#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int is_Valid(char *buffer, int i, int opened, int closed) {
    if(isalpha(buffer[i])){
        if((strlen(buffer)-1) == i)
            return 1;
        else if(buffer[i-1] == '(')
            return is_signum(buffer, ++i, opened, closed);
        else
            return is_Valid(buffer, ++i, opened, closed);
        
    }
    else if (buffer[i] == '('){
            return is_Valid(buffer, ++i, ++opened, closed);
    }
    else if (buffer[i] == ')'){
	    return is_Valid(buffer, ++i, opened, ++closed);
    }
    else if(strlen(buffer) == i){
    	if(opened == closed)
    		return 1;
    	else {
            printf("Ошибка! Количество закрывающихся и открывающихся скобок не одинаковое");
            return 0;
        }
    }
    else return is_signum(buffer, i, opened, closed);
}

int is_signum(char *buffer, int i, int opened, int closed) {
    if(buffer[i] == '*' || buffer[i] == '-' || buffer[i] == '+'){
        return is_Valid(buffer, ++i, opened, closed);
    }
    else {
        printf("Ошибка! %d-й элемент не является допустимым знаком!", i);
        return 0;
        }
}

int main() {
    char *buffer=malloc(sizeof(char)*20);
    scanf("%s", buffer);
    int i = 0, opened = 0, closed = 0;
    if(is_Valid(buffer, i, opened, closed)){
        printf("Данное выражение корректно!\n");
    }
    else
        printf("\nВсё плохо!\n");
    
}