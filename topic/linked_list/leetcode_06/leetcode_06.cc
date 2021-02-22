/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        std::stack<int> res_stack;
        while(head){
            res_stack.push(head->val);
            head = head->next;
        }
        std::vector<int> res;
        res.reserve(res_stack.size());
        while(!res_stack.empty()){
            res.push_back(res_stack.top());
            res_stack.pop();
        }
        return res;
    }
};