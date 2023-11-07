#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int lengthOfLastWord(char * s){
    int count = 0;
    for(int i = strlen(s)-1; i>=0; i--){
        if(s[i] != ' '){
            count++;
        }
        else if(s[i]== ' ' && count != 0){
            break;
        }
    }
    return count;
}

int main(){
    char s[100] = "   fly me   to   the moon";
    for(int i=0;i<100;i++){
        // scanf("%s",&s[i]);
    }
    int a = lengthOfLastWord(s);
    printf("%d",a);
}
