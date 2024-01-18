#include<stdio.h>
#include<stdlib.h>

int climbStairs(int n) {
    if(n == 1){ // 如果n=1，表示只有一階樓梯
        return 1; 
    }
    if(n == 2){ // n = 2，表示有兩階樓梯
        return 2;
    }
    int* arr = (int*)malloc((n)*sizeof(int)); // 儲存每一階爬樓梯數量的方式
    arr[0] = 1; 
    arr[1] = 2;
    for(int i = 2; i < n; i++){
        arr[i] = arr[i-1]+arr[i-2]; // 從n-1階排一層樓梯，n-2階爬兩層樓梯
    }
    return arr[n-1];  // 返回最後一個元素arr[n-1]，及爬到樓梯頂部
}

int main(){
    int n = 0;
    printf("n = ");
    scanf("%d",&n);
    int a = 0;
    a = climbStairs(n);
    printf("%d",a);
}
