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
    // store left from previous node operation
    // store right for temp to get to the correct next node
    // every time make a node->next to its left
    // finally return last one that right == nullptr
    ListNode* reverseList(ListNode* head) {
        ListNode* left = NULL;
        ListNode* right = NULL;
        ListNode* temp = head;
        
        while (temp != NULL){
            right = temp->next;
            temp->next = left;
            left = temp;
            
            if (right == NULL)
                return temp;
            temp = right;
        }
        return NULL;
    }
};
