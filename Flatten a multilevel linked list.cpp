/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* current = head;
        stack<Node*> s;
        while(current != NULL){
            if(current->child){
                if(current->next){
                    s.push(current->next);
                }
                current->next = current->child;
                current->next->prev = current;
                current->child = NULL;
            }
            else if(current->next == NULL && !s.empty()){
                Node* temp = s.top();
                s.pop();
                current->next = temp;
                current->next->prev = current;
            }
            current = current->next;
            
        }
        return head;
        
    }
};