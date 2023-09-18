bool isValid(char * s){ // * => 表示pointer(指標)
    char stack[1000000];    // 設置空字串stack
    int flag = -1;  // 設定flag

    while(*s){  // 's的內容不為'\0'，則執行迴圈內容，開始讀取字串
        if(')' == *s){  // 以下三個括號，有一個括號不一樣表示不匹配，則return false
        // 假設括號為"(" or "["or "{"，則flag+1，同時存入括號進stack儲存
        // 但假設括號為")" or "]"or "}"，則比較stack最後一次存入的括號，如果括號匹配，flag-1，否則直接回傳false
            if(flag >= 0 && stack[flag--] == '('); // 

            else return false;
        }
        else if(']' == *s){
            if(flag >= 0 && stack[flag--] == '[');
            else return false;
        }
        else if('}' == *s){
            if(flag >= 0 && stack[flag--] == '{');
            else return false;
        }
        else{
            stack[++flag] = *s;
        }
        s++;    // 指標s會址向下一個字串空間
    }
    return flag == -1;  // 如果回傳的flag = -1(初始值)，表示括號匹配，否則括號不匹配
}
