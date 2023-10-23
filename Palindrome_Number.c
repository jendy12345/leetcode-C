#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

bool isPalindrome(int x){
    if(x < 0){  // 因為負數一定不是迴文，所以直接回傳false
        return false;
    }
    if(x == 0){
        return true;  // 如果輸入的x=0，則直接返回true，因為0為迴文
    }
    int result = 0,before = x; // before=目前輸入的數，result為之後的結果
    while(x){
        result = result * 10 + x % 10;
        printf("result = %d\n",result);
        x /= 10;
        printf("%d\n",x);
    }
    
    return result == before; // 最後result==befor，表示迴文
}
/*
    result = result * 10 + x % 10;
    x /= 10;

    這兩行程式碼的意思：
    EX:
    input x = 121,
    result = result * 10 + x % 10;
    result一開始為0 =>result = 0 * 10 + 121 % 10 = 12

    x /= 10; =>將前面計算的數值往左移一位 =>

    x = 121,
    result = 1,
    left = 12;
    result = 12,
    left = 1;
    result = 121,
    left = 0;
    所以前面x == 0為迴文的意思    
    if(x == 0){
        return true;  // 如果輸入的x=0，則直接返回true，因為0為迴文
    }    
*/

int main(){
    int a=0;
    printf("x = ");
    scanf("%d",&a);
    int result = isPalindrome(a);
    if(result){
        printf("true");
    }
    else{
        printf("false");
    }
}
