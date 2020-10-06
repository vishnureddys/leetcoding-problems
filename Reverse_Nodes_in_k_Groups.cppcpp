// https://leetcode.com/problems/reverse-nodes-in-k-group/

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
    ListNode* reverseKGroup(ListNode* head, int k) {
         if(head == NULL || head->next == NULL)
        return head;
    if(k == 1)
        return head;
	
    int countNodes = 0;
    ListNode *ptr = head;
    while(ptr != NULL){
        countNodes++;
        ptr = ptr->next;
    }
    if(countNodes < k)
        return head;
    
    int count = 0;
    ListNode *curr = head, *prev = NULL, *next;
    while(count < k && curr != NULL) {
        count++;
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head->next = reverseKGroup(curr, k);
    return prev;
    }
};
