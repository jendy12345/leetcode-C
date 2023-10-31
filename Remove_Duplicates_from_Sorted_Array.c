int removeDuplicates(int* nums, int numsSize){
    int index=0;
    for(int i=0;i<numsSize;i++){
        if(i==0 || nums[i]>nums[i-1]){  // 在程式碼中，nums[i-1]表示和上一個數去做比對，如果有重複的數則移除，當i=0(目前為數組的第一個元素)或當前元素nums[i]大於前一個元素nums[i-1]時，將nums[i]複製到新的數組當中。
            nums[index++] = nums[i];
        }
    }
    return index;
}
// new code
#include<stdio.h>
#include<stdlib.h>

int removeDuplicates(int* nums, int numsSize){
int index = 0;
for(int i = 0; i < numsSize; i++){
    if(i==0 || nums[i] > nums[i-1]){
        nums[index++] = nums[i];
    }
}
return index;
}

int main(){
    int numSize = 10;
    int nums[] = {0,0,1,1,1,2,2,3,3,4};
    int result = removeDuplicates(nums,numSize);
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
