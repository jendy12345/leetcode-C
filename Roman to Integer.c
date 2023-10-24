#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

int call(char c){
    switch(c){
        case 'I':return 1;
        case 'V':return 5;
        case 'X':return 10;
        case 'L':return 50;
        case 'C':return 100;
        case 'D':return 500;
        case 'M':return 1000;
    }
    return 0;
}

int romanToInt(char * s){
    int length = strlen(s),temp = 0,val = 0;  // strlrn(取得字串長度)
    for(int i=0;i<length;i++){  // 循環一次所有的羅馬數字字串
        if(i == length-1){  // 如果i＝最後一個字串時，表示已經處理到最後一個字串了
            val += call(s[i]); // 所以把整個字串的數值加到val變數存取，並退出迴圈;否則檢查下一個數是不是大於目前的數
            break;
        }
        if((temp = call(s[i+1])-call(s[i]))>0){ // 假設找到下一個數值大於目前的數，則要先做相減，相減完之後在鄉加到value上
            val += temp;
            i++;    // 要做i++，讓它指向下一個字串
            continue;
        }
        val += call(s[i]);  // 如果都沒有符合上述的狀況，則直接將字串的數字做相加
    }
    return val;
}

/*
    case 'I':return 1;
    case 'V':return 5;
    case 'X':return 10;
    case 'L':return 50;
    case 'C':return 100;
    case 'D':return 500;
    case 'M':return 1000;
EX：
    MCMXCIVI = 1995
    M = 1000,
    CM = 900,
    XC = 90,
    IV = 4,
    I = 1,
    M + CM + XC + IV + I = 1995
    如果兩兩相比，後面的數值大於前面的數值，則要相減，在將差值加到val上
*/


int main(){
    char s[10];
    printf("s = ");
    scanf("%s",s);
    printf("%ld\n",strlen(s));  // 可印出字串長度
    int result = romanToInt(s);
    printf("%d\n",result);
}
