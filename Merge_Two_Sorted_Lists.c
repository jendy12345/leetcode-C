/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    if(!list1){ // list1為空的話，直接返回第二個list
        return list2;
    }
    if(!list2){ // list2為空的話，直接返回第一個list
        return list1;
    }
    struct ListNode *p, *list;
    if(list1-> val <= list2->val){  // 比較list1和lilst2節點
        p = list1;
        list1 = list1->next;
    }
    else{
        p = list2;
        list2 = list2->next;
    }
    list = p;   // 使list指向節點
    while(list1 && list2){  // 其中一個列表插入後，則出迴圈
        if(list1-> val < list2-> val){
            p -> next = list1;
            list1 = list1->next;    // 指向下一個元素
        }
        else{
            p ->next = list2;
            list2 = list2->next;
        }
        p-> next -> next = NULL;    // 清空下下一個節點
        p = p->next;    // 移向新增的節點
    }
    if(list1){  // p-> next指向剩下為完成列表的節點
        p->next = list1;
    }
    else if(list2){
        p-> next = list2;
    }
    return list;
}
