int removeDuplicates(int* nums, int numsSize){
    int index=0;
    for(int i=0;i<numsSize;i++){
        if(i==0 || nums[i]>nums[i-1]){  // 在程式碼中，nums[i-1]表示和上一個數去做比對，如果有重複的數則移除，當i=0(目前為數組的第一個元素)或當前元素nums[i]大於前一個元素nums[i-1]時，將nums[i]複製到新的數組當中。
            nums[index++] = nums[i];
        }
    }
    return index;
}
