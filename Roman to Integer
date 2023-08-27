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
  int i,length = strlen(s),temp=0,val=0;
  for(int i=0;i<length;i++){
    // 最後對應的字串數值加總到總值中
    if(i==length-1){  
      val += call(s[i]);
      break;
    }
    if((temp=call(s[i+1])-call(s[i]))>0){
      val += temp;  // 如果下一個字串大於目前的字串，則將差值加道總值中
      i++;  //跳過當前的字串，表示已經處理過
      temp = 0;
      continue;
    }
    val += call(s[i]);  // 將當前的字串對應的數值加到總值中
  }
  return val; //返回計算得到整數
}
