class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

        // Remove matching nodes from the beginning
        while (head != nullptr && head->val == val) {
            head = head->next;
        }

        // Now remove matching nodes from the rest of the list
        ListNode* curr = head;

        while (curr != nullptr && curr->next != nullptr) {

            if (curr->next->val == val) {
                // Skip the node
                curr->next = curr->next->next;
            }
            else {
                // Move to the next node
                curr = curr->next;
            }
        }

        return head;
    }
};