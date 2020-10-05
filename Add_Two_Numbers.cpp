// https://leetcode.com/problems/add-two-numbers/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        int carry = 0, sum;
        sum = l1->val + l2->val + carry;
        ListNode* ans = new ListNode(sum%10);
        carry = sum/10;
        l1 = l1->next;
        l2 = l2->next;
        ListNode* sol = ans;
        
        while(l1 || l2 || carry){
            sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            ListNode* temp = new ListNode(sum%10);
            carry = sum/10;
            ans->next = temp;
            ans = ans->next;
            
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        return sol;
    }
};