/*Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */





struct ListNode* reverseList(struct ListNode* head){
    if(head == NULL)//判断链表是否为空
    return NULL;

    if(head ->next ==NULL)//判断是否为一个节点
    return head;

    struct ListNode *q = head, *qr=head;

    while(q->next != NULL) /*该指针指向倒数第一个节点5*/
    {
        q = q->next;
    }

    while(qr->next->next != NULL) /*将最后一个节点从链表中断开*/
    {
        qr = qr->next;
    }
    
     //printf("%d",qr->val);
    qr->next = NULL;/*将最后一个节点从链表中解开,然后依次将原链表的节点插入它的后的后面*/
    q->next = NULL;
    struct ListNode *p = head, *temp = head;
    
    while(p != NULL)
    {
      //printf("p==%d\n", p->val);
        temp = p;
        p = p->next;
        temp->next = q->next;
        q->next = temp;
    }

    head = q;
return head;
}

