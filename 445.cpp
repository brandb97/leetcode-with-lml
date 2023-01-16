// 2023.1.16 10:35 - 10:52 17min
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
    void makeStackFromList(ListNode *l, stack<ListNode *> &stk) {
        while (l != nullptr) {
            stk.push(l);
            l = l->next;
        }
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *cur, *prev = nullptr;
        stack<ListNode *> l1_stack{}, l2_stack{};
        makeStackFromList(l1, l1_stack);
        makeStackFromList(l2, l2_stack);
        int carry = 0;
        while (!l1_stack.empty() || !l2_stack.empty() || carry != 0) {
            auto new_val = (l1_stack.empty()? 0: l1_stack.top()->val) +
                           (l2_stack.empty()? 0: l2_stack.top()->val) +
                           carry;
            if (!l1_stack.empty()) l1_stack.pop();
            if (!l2_stack.empty()) l2_stack.pop();
            carry = new_val / 10;
            new_val = new_val % 10;
            cur = new ListNode(new_val, prev);
            prev = cur;
        }
        return cur;
    }
};
