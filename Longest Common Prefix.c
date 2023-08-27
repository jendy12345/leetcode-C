char * longestCommonPrefix(char ** strs, int strsSize){
    int index = 0;  //用來追蹤目前正在比較的字串index
    while(index < strlen(strs[0])){ //從第一個字串的第一個字開始比較
        for(int i=0;i<strsSize;i++){    
            //確保不超出字串範圍
            if(index < strlen(strs[i])){ 
                //   假設目前比較中字母在字串中相同，則繼續比較下一個
                if(strs[0][index] == strs[i][index]){

                }
                else{
                    strs[0][index] = '\0';  // 將第一個字串設為'\0'，表示截斷最長共同字母
                    return strs[0]; //反回目前最常共同字母
                }
            }
            else{
                strs[0][index] = '\0';
                return strs[0];
            }
        }
        index++;    //比較完前一個字母後在比較下一個字母
    }
    return strs[0]; //返回完整最長的字母
}
