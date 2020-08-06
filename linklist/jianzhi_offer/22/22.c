/*Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*统计链表总共有多少个节点*/
int calculate_linklist(struct ListNode* head)
{
    int count = 0;
    struct ListNode* p = head;
    while(p != NULL)
    {   
        ++count;
        p = p->next;
    }
return count;
}

struct ListNode* getKthFromEnd(struct ListNode* head, int k){

    printf("\nListNode count==%d\n" ,calculate_linklist(head) );
    int count = calculate_linklist(head);
    struct ListNode* p = head;
    
    for(int i = 1; i < count - k + 1 ; i++)
        p = p->next;
return p;
}
