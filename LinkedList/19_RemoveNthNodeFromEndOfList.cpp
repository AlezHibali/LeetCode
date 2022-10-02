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
    // let first point to the node before the deleted one
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* first = head;
        ListNode* last = first;
        
        for (int i = 0; i < n; i++){
            last = last->next;
        }

        // when deleting the first node
        if (last == NULL){
            ListNode* temp = head->next;
            delete(head);
            return temp;
        }
        
        last = last->next;
        while (last != NULL){
            last = last -> next;
            first = first -> next;
        }
        
        // temp is to be deleted node, first is before it
        ListNode* temp = first->next;
        first->next = temp->next;
        delete(temp);
        
        return head;
    }
};
