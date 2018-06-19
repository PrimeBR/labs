#include <stdio.h>
#include <string.h>

int recursion(const char* word, int head, int tail){
    if(head > tail)
        return 1;
    if(word[head] == word[tail])
        return recursion(word, head+1, tail-1);
    return 0;
}
int main(){
    char word[20];
    scanf("%s", word);
    int len = strlen(word);
    if(recursion(word, 0, len-1))
        printf("Yes");
    else
        printf("No");
}