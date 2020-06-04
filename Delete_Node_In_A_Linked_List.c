/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    /*
    //Even this algorithm works.
    struct ListNode* prev; 
    if (node == NULL) 
        return; 
    else { 
        while (node->next != NULL) { 
            node->val = node->next->val; 
            prev = node; 
            node = node->next; 
        } 
        prev->next = NULL; 
    }
    */
    node->val = node->next->val;
    node->next = node->next->next;
}
