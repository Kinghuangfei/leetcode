/*Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */



#include<math.h>
#include<stdio.h>


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    
    struct ListNode * L1 = l1;
    struct ListNode * L2 = l2;
    
    struct ListNode *pre = NULL;
    struct ListNode *cur = NULL;
    struct ListNode *head = NULL;
    pre = head;
   
    /*1先遍历链表，
    2取出每个链表的节点保存的值， 
    3将每个节点的值相加， 
    4， 判断是否进位，若不进位，直接保存新链表的节点中， 否则对10取余， 然后将余数保存到节点中，用carry保存进位，下一个节点相加时，加上进位值，如果加上进位值》10，则carry=1, 否则carry =0*/

    int carry = 0;
    int tmp = 0;
    int count = 1;
    //int temp = 0;
    while( L1 != NULL && L2 != NULL )
    {
         /*将l1的val和 L2的val 进行相加*/
        //tmp = L1->val + L2->val;
        /*节点个数相同的部分*/
        
            cur = (struct ListNode*)malloc(sizeof(struct ListNode));
            cur->next = NULL;
            tmp = L1->val + L2->val + carry;
            
            if(tmp >= 10)
            {
                //cur->val = (tmp + carry) % 10 ;
                cur->val = tmp  % 10 ;
                carry = 1;
            }
            else
            {    
                cur->val = tmp;
                carry = 0;
            }    
            
            printf("\ncur->val == %d\n", cur->val);
            
            if(count == 1) /*count 用来判断是否是头结点*/
            {
                head = cur;
                pre = head;
            }
            else
            {
                pre->next = cur;
                pre = cur;
            }
            
            tmp = 0;
            count++;
            L1 = L1->next;
            L2 = L2->next;
    }

    /*如果存在未遍历完的链表*/
    while(L1 != NULL)
    {
        cur = (struct ListNode*)malloc(sizeof(struct ListNode));
        cur->next = NULL;
        
        tmp = L1->val + carry;
        
        if(tmp >= 10)
        {
            //cur->val = (tmp + carry) % 10 ;
            cur->val = tmp  % 10 ;
            carry = 1;
        }
        else
        {    
            cur->val = tmp;
            carry = 0;
        }    
                
        pre->next = cur;
        pre = cur;

        L1 = L1->next;
    }


    while(L2 != NULL)
    {
        cur = (struct ListNode*)malloc(sizeof(struct ListNode));
        cur->next = NULL;
        
        tmp = L2->val + carry;
        printf("\ntmp == %d \n", tmp);
        if(tmp >= 10)
        {
            //cur->val = (tmp + carry) % 10 ;
            cur->val = tmp  % 10 ;
            carry = 1;
        }
        else
        {    
            cur->val = tmp;
            carry = 0;
        }    
                
        pre->next = cur;
        pre = cur;

        L2 = L2->next;
    }
    
    /*遍历完毕后， 判断是否存在进位*/
    if(carry != 0)
    {
        cur = (struct ListNode*)malloc(sizeof(struct ListNode));       
        cur->next = NULL;
        printf("\ntm1p == %d\n", tmp);
        cur->val = tmp%10 + carry;
        pre->next = cur;
        pre = cur; 
    }   

    return head;
}
