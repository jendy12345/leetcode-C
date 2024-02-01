#include<stdio.h>
#include<stdlib.h>

struct ListNode{    // ListNode必須包含val、next(下一個節點)
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head){
    // head為空節點或到列表下一個點為空，則直接返回
    if(head == NULL || head -> next == NULL){
        return head;
    }
    // 使用指標pbegin指向列表的頭節點
    struct  ListNode *pbegin = head;
    // 循環整個列表
    while(pbegin != NULL){
        // 當pbegin不為空，假設pbegin指向下一個節點為空時，表示已經循環到列表的最後，則跳出迴圈
        if(pbegin -> next == NULL){
            break;
        }
        // 如果pbegin和下一個節點相同
        if(pbegin->val == pbegin -> next -> val){
            // 則刪除掉相同的節點
            pbegin->next = pbegin -> next -> next;
        }
        else{
            //如果沒有重複節點，則繼續看下一個節點
            pbegin = pbegin -> next;
        }
    }
    return head;
}

int main(){
    // 分配了五個ListNode動態記憶體
    struct ListNode* list1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* list2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* list3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* list4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* list5 = (struct ListNode*)malloc(sizeof(struct ListNode));
    
    // 將節點的val賦予值，並next往下一個節點移動，並將最後一個節點設為NULL，表示列表結尾
    list1 -> val = 1;
    list1 -> next = list2;
    list2 -> val = 1;
    list2 -> next = list3;
    list3 -> val = 2;
    list3 -> next = list4;
    list4 -> val = 5;
    list4 -> next = list5;
    list5 -> val = 5;
    list5 -> next = NULL;

    struct ListNode* head = deleteDuplicates(list1);
    while(head != NULL){
        printf("%d ",head -> val);
        head = head -> next;
    }
}
