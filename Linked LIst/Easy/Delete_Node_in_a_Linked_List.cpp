class Solution {
public:
    void deleteNode(ListNode* node) {
        // putting the same value of next node in node
        node->val = node->next->val;
        // deleting the next node by connceting the node with node->next->next
        node->next = node->next->next;
    }
};
