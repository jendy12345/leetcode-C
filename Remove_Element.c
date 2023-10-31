int removeElement(int* nums, int numsSize, int val){
    // nums => 整數陣列指標，進行陣列操作
    // numsSize => 表示陣列nums大小，元素的個數
    // val => 要被移除的特定值
    if(nums==NULL)  // 檢查nums是否為NULL，如果是則返回為0
    return 0;
    int countVal = 0;   // 用於計算陣列中等於val的元素
    int newSize = numsSize; // 表示移除陣列大小，初始值為numsSize
    for(int i = 0;i<numsSize;i++){  
        if(nums[i] == val){ // 檢查程式碼陣列中的元素是否等於val
            countVal++; // 將等於val的元素個數+1
            newSize--;  // 移除一個元素後，新的陣列大小減一
        }
        else{   // 如果不是，則不需要移除元素
            nums[i-countVal] = nums[i]; // 前半部移除了countVal的元素，所以要調整索引位置
        }
    }
    return newSize;
}


// new code
#include<stdio.h>
#include<stdlib.h>

int removeElement(int* nums, int numsSize, int val){
    if(nums == NULL){    //假設數值為空，則直接return =0
        return 0;
    }
    int count = 0;    // 計算要被移除的數
    int newSize = numsSize;    // 移除陣列大小，在存為新的長度
    for(int i = 0; i < numsSize; i++){
        if(nums[i] == val){    // 假設num[i]中有找到要移除的數，等於val(要移除的數)則+1(往下找下一個)，並長度減1
            count ++;
            newSize--;
        }
        else{
            nums[i-count] = nums[i];  // 如果沒有則不需要移除元素， 前半部移除了count的元素，所以要調整索引位置
        }
    }
    return newSize;
}

int main(){
    int numSize = 4;
    int nums[] = {0,1,2,2,3,0,4,2};
    int val = 2;
    int result = removeElement(nums,numSize,val);
    printf("%d\n",result);
    printf("output： %d,nums=[",result);
    for(int i=0;i<result;i++){
        printf("%d",nums[i]);
        if(i < result - 1){
            printf(",");
        }
    }
    printf("]\n");
    return 0;
}
