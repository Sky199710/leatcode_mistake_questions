解题思路
链表问题要注意一下几点：1.考虑直接传入空列表的情况2.空的节点没有NEXT

代码

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL)
            return head;
        ListNode* cur = head;
        while(cur->next!=NULL){
            ListNode* next = cur->next;
            if(cur->val==next->val)
                cur->next = next->next;
            else
                cur = cur->next;
            if(cur==NULL)
                break;
        }
        return head;

    }
};

