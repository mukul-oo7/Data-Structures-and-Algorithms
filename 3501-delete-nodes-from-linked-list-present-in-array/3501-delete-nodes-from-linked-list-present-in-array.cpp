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
        for(int i=0; i<nums.size(); i++) st.insert(nums[i]);

        ListNode *h = new ListNode(-1);
        ListNode *t = h;

        while(head!=NULL){
            if(st.find(head->val)!=st.end()){
                head=head->next;
                continue;
            }

            t->next = head;
            head = head->next;
            t=t->next;
            t->next = NULL;
        }

        return h->next;

    }
};