#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * addBinary(char * a, char * b){
    // 計算la和lb的字串長度
    int la = strlen(a),lb = strlen(b);
    // 並找到其中最大的一個，設為lc
    int lc = la > lb ? la : lb;
    // 用malloc分配lc+1的字串組C
    char * c = (char*)malloc((lc+1));
    // 動態分配的字串陣列c的最後一個位置(lc)，放置一個空字串'\0'，確保c以空字串結束字串
    c[lc] = '\0';
    int carry = 0;
    for(int i = 0;i<lc;i++){
        // 將a的當前位轉為數字，加到carry上
        if(la)carry += a[--la] - '0';
        // 將b的當前位轉為數字，加到carry上
        if(lb)carry += b[--lb] - '0';
        // 把carry的最低為取出，加到c目前的位置上
        c[lc-1-i] = (carry&1)+'0';
        // 將carry向右移一位，模擬二進制進位
        carry >>=1;
    }
    /* 如果最終進位carry為1，表示最高位相加產生進位，需要在結果c的最前面要+1，
    因此使用realloc重新分配內存空間，然後將所有位右移移一位
    */
    if(carry == 1){
        c = (char*)realloc(c,lc+2);
        for(int i=lc;i>=0;i--){
            c[i+1] = c[i];
        }
        c[0] = '1';
    }
    return c;
}


int main(){
    char *a,*b;
    a = "1010";
    b ="1011";
    char * result = addBinary(a,b);
    printf("%s",result);
}
