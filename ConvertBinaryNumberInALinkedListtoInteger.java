/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public int getDecimalValue(ListNode head) {
        
        StringBuilder str = new StringBuilder();
        
        while (head != null) {
            str = str.append(String.valueOf(head.val));
            head = head.next;
        }
        
        return Integer.parseInt(str.toString(), 2);
    }
}