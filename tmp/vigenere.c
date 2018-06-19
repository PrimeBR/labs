#include <stdio.h>
#include <string.h>

int main(){
    //char str[] = "gjhwxclrqxpdvbtuhpkwgwipgtorkzkakugiastkynwuycjxculmeainojgd";
    char str[60];
    fgets(str, 60, stdin);
    char key[] = "zceiwmbt";
    char result[strlen(str)];
    char newkey[strlen(str)];
    int i,j;
    for(i = 0, j = 0; i < strlen(str); ++i, ++j){
        if( j == strlen(key))
            j = 0;
        newkey[i] = key[j];
    }
     printf("New key: %s\n", newkey);

    for(i = 0; i < strlen(str); ++i)
        result[i] = 'a'+(((str[i] - newkey[i])+ 26) % 26);
    printf("\nDecrypt: %s\n", result);
    return 0;
}