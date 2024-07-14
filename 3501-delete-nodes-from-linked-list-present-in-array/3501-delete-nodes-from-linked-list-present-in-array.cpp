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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st;
        for(auto it: nums) st.insert(it);

        ListNode* h = new ListNode(-1, head);
        ListNode* pre = h;

        while(head){
            if(st.find(head->val)!=st.end()){
                pre->next = head->next;
                head=head->next;
            } else{
                pre = head;
                head=head->next;
            }
        }

        return h->next;
    }
};