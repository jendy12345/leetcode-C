#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int lengthOfLastWord(char * s){
    int count = 0;  // 使用count來記錄數字長度
    for(int i = strlen(s)-1; i>=0; i--){    // 找到迴圈的最後一個字串並往前尋找，直到有找到非字元或是空格則count+1。
        if(s[i] != ' '){
            count++;    // 如果找到非空格字元，則count+1
        }
        else if(s[i]== ' ' && count != 0){  // 如果找到空格字串且為零，則跳出迴圈。
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
