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
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode temp = head;
        int count = 0;
        while (temp != null && count < k) {
            temp = temp.next;
            count++;
        }
        if(count <k) return head;
        else{
        ListNode cur=head;
        ListNode prev=null;
        ListNode nextptr=null;
        count=0;
        while(count < k)
        {
            nextptr=cur.next;
            cur.next=prev;
            prev=cur;
            cur=nextptr;
            count++;
        }
            head.next=reverseKGroup(nextptr,k);
        return prev;
        }
    }
}