/*Definiition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* reversePrint(struct ListNode* head, int* returnSize){
    
    if(head==NULL){
        *returnSize=0;
        return NULL;
    }

    int count = 0;
    struct ListNode* p = head;
  
    while(p != NULL)/*统计节点个数*/
    {
        ++count;
        p = p->next;
    }

    int *arr = (int*)malloc(count*sizeof(int));   
    p = head;
    
    for(int i = count-1; i >= 0 ; i--)
    {
        arr[i] = p->val;
        p = p->next;
    }  

    *returnSize = count;
    return arr;
}

