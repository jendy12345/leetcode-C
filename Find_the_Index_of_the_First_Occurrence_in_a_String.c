#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int strStr(char * haystack, char * needle){
    int hl = strlen(haystack);
    int nl = strlen(needle);
    // hl-nl是確保haystack和needle有足夠的長度可以進行字串比較
    for(int i = 0; i<= hl-nl;i++){
    /* 用strncmp函數來比較haystack+i和needle的前nl個字串
    ，如果這兩個字串有相等，則表示有相互匹配，return i，也就是回傳為0，
    這個i就是haystack這個的位置
    */
        if(strncmp(haystack+i,needle,nl)==0){
            return i;
        }
    }
    return -1;
}

int main(){
    
    char hay[1000];
    scanf("%s",hay);
    
    char need[1000];
    scanf("%s",need);
    int result = strStr(hay,need);
    printf("%d\n",result);
    return 0;
}
