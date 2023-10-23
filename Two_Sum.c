#include<stdio.h>
#include<stdlib.h>


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;// 將所指向的變數數值為2，表示返回的結果會包含兩個index
    int *ret = (int*)malloc(2*sizeof(int)),i,j,temp;   
    //用ret定義一個整數指標，並使用malloc分配可以存放兩個整數的記憶體空間
    for(i=0;i<numsSize;i++){    // 循環整個numsSize的長度
        temp = target - nums[i]; // 計算目標和target-nums[i]得到的差值，並將變數存在temp中，要找到相加符合的值，所以先計算插值
        printf("temp = %d\n",temp);
        for(j=i+1;j<numsSize;j++){  // 是內部循環，找到所有nums數組中i的元素
            if(temp == nums[j]){    //判斷temp是否等於num[j]，如果相等，兩個數字相加為target的數字，則會將index個別存在ret[0](第一個位置)，ret[1](第二個位置)
                ret[0] = i;
                ret[1] = j;
                return ret; // 返回ret,這輛個數組中存放了兩個數字的index
            }
        }
    }
    return ret; // 如果沒有找到符合的數字，直接返回ret
}
int main(){
    int sum=0;
    int nums[2];
    int numsSize=0;
    int target = 0;
    scanf("%d",&numsSize);
    scanf("%d",&target);
    printf("nums = ");
    for(int i=0;i<numsSize;i++){
        
        scanf("%d",&nums[i]);
    }
    int returnSize;
    int* result = twoSum(nums,numsSize,target,&returnSize);
    printf("[%d, %d]\n",result[0],result[1]);

    return 0;
}
