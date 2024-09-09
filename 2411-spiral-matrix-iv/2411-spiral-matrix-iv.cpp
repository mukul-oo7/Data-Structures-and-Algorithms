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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> res(m, vector<int>(n, -1));

        vector<vector<int>> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        int i=0, j=0, d=0;

        while(head){

            // cout << i << " " << j << endl;
            res[i][j] = head->val;
            head = head->next;

            int ni=dir[d][0]+i, nj=dir[d][1]+j;

            if(ni<0 || ni>=m || nj<0 || nj>=n || res[ni][nj]!=-1){
                d++;
                if(d==4) d=0;

                i=dir[d][0]+i, j=dir[d][1]+j;
            } else{
                i=ni, j=nj;
            }


        }

        return res;

        
    }
};