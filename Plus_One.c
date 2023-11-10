#include<stdio.h>
#include<stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/*
整數陣列 => digits;
陣列大小 => digitsSize;
回傳陣列大小 => returnSize;
*/
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int i = 0;
    // 檢查陣列最後一個元素是否為9，如果不是9，則陣列最後一個元素+1
    if(digits[digitsSize-1] != 9){
        digits[digitsSize-1]++;
    }
    // 如果最後一個元素為9則進入else迴圈
    else{
        // 從最後一個元素開始往前找
        for(i = digitsSize-1; i >= 0;i--){
            // 如果目前元素為9，將其位置設為0，表示進位
            if(digits[i] == 9){
                digits[i] = 0;
            }
            // 如果不是9，則陣列中的最後一位+1並停止迴圈
            else{
                digits[i]++;
                break;
            }
        }
    }
    // 檢查第一個元素是否為0
    if(digits[0] == 0){
        // 如果第一個元素為0，表示原始數字最高位也進位了，因此返回的長度要加一
        *returnSize = digitsSize+1;
    }
    // 如果第一位元素不為0，表示原始數字最高位並沒有進位，直接返回原始陣列
    else{
        *returnSize = digitsSize;
        return digits;
    }
    // 需要返回一個新的陣列，使用malloc分配新的陣列，大小為returnSize
    int *array = (int *)malloc(sizeof(int)*(*returnSize));
    // 從新陣列的最後元素開始將原陣列元素逐一複製到新陣列中
    for(i = *returnSize-1; i>=1; i--){
        array[i] = digits[i-1];
    }
    array[0] = 1;// 將新陣列中的第一個元素設為1，因為原始數字在進位過程中可能會產生新的最高位
    return array;// 返回新的陣列指標
}

int main(){
    int digitnum = 1;
    int returnSize = 2; 
    int a[] = {9};
    int *result = plusOne(a,digitnum,&returnSize);
    // printf("%d",result);
    for(int i = 0; i<returnSize;i++){
        printf("%d\t",result[i]);
    }
    printf("\n");
}
