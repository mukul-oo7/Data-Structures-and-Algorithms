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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> res(k, NULL);

        int count=0, idx=0;
        ListNode* temp = head;

        while(temp){
            count++;
            temp=temp->next;
        }

        int size = count/k, rem=count%k;
        temp=head;

        // cout << size << " " << rem << endl;

        while(temp){
            res[idx++] = temp;
            
            int s = size;
            if(rem){
                s++;
                rem--;
            }
            // cout << s << endl;

            ListNode *pre = temp;
            for(int i=0; i<s; i++){
                pre = temp;
                temp=temp->next;
            }

            pre->next = NULL;
        }

        return res;
    }
};