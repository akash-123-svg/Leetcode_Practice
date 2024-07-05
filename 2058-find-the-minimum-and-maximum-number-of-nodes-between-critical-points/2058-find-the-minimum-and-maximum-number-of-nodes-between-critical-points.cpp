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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head or !head->next or !head->next->next) return {-1,-1};
        
        ListNode* a = head;     
        ListNode* b = head->next;
        ListNode* c = head->next->next;
        
        vector<int>critical;
        int pos = 1;
        
        while(c != NULL){
            if(a->val > b->val and c->val > b->val) critical.push_back(pos);          // minima
            else if(a->val < b->val and c->val < b->val) critical.push_back(pos);     // maxima
            
            a = a->next;
            b = b->next;
            c = c->next;
            pos += 1;
        }
        
        if(critical.size() < 2) return {-1, -1};
        
        int minDiff = INT_MAX;
        int n = critical.size();
        for(int i=1; i<n; i++)    minDiff = min(minDiff, critical[i] - critical[i-1]);
        int maxDiff = critical[n-1] - critical[0];
        
        return{minDiff, maxDiff};
    }
    // Time:- O(n)
    // space:- O(1)
};