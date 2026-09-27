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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* d1=new ListNode(-1);
        ListNode* d2=new ListNode(-1);
        ListNode* t1=d1;
        ListNode* t2=d2;
        ListNode* temp=head;
        int idx=1;
        while(temp!=NULL){
            if(idx%2==1){
                t1->next=temp;
                t1=t1->next;
                temp=temp->next;
                idx++;
            }
            else{
                t2->next=temp;
                t2=t2->next;
                temp=temp->next;
                idx++;
            }
        }
        t1->next=NULL;
        t2->next=NULL;
        t1->next=d2->next;
        return d1->next;
    }
};