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
    ListNode*getMid(ListNode*head){
        ListNode*slow=head;
        ListNode*fast=head->next;
        
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode*RevList(ListNode*head){
        ListNode*prev=NULL;
        while(head!=NULL){
            ListNode*next=head->next;
            head->next=prev;
            prev=head;
            head=next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL){
            return true;
        }
        ListNode*mid=getMid(head);
        
        ListNode*rev=mid->next;
        mid->next=RevList(rev);
        
        ListNode*head1=head;
        ListNode*head2=mid->next;
        
        while(head2!=NULL){
            if(head1->val!=head2->val){
                return false;
            }
            head1=head1->next;
            head2=head2->next;
        }
        return head1;
    }
};