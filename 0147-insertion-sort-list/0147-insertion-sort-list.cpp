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
    ListNode* mergeTwolist(ListNode* list1,ListNode* list2){
        ListNode* dummy=new ListNode(-1);
        ListNode* tc=dummy;
        ListNode* ta=list1;
        ListNode* tb=list2;
        while(ta!=NULL && tb!=NULL){
            if(ta->val<=tb->val){
                tc->next=ta;
                ta=ta->next;
                tc=tc->next;
            }
            else{
                tc->next=tb;
                tb=tb->next;
                tc=tc->next;
            }
        }
        if(ta==NULL) tc->next=tb;
        else tc->next=ta;
        return dummy->next;
    }
    ListNode* insertionSortList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        if(head==NULL ||head->next==NULL) return head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* head2=slow->next;
        slow->next=NULL;
        head=insertionSortList(head);
        head2=insertionSortList(head2);
        return mergeTwolist(head,head2);
    }
};