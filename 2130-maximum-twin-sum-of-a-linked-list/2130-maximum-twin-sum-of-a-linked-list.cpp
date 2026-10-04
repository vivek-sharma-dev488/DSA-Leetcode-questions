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
        ListNode* reverseList(ListNode* head){
            ListNode* prev=NULL;
            ListNode* curr=head;
            ListNode* Next=head;
            while(curr!=NULL){
                Next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=Next;
            }
            return prev;
    }
    int pairSum(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* head2=reverseList(slow->next);
        ListNode* a=head;
        ListNode* b=head2;
        int max=INT_MIN;
        while(b!=NULL){
            int tempmax=a->val+b->val;
            if(tempmax>max){
                max=tempmax;
            }
            a=a->next;
            b=b->next;
        }
        return max;
    }
};