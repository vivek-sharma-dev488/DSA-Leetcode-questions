
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    //     ListNode* temp=head;
    //     int len=0;
    //     while(temp!=NULL){
    //         len++;
    //         temp=temp->next;
    //     }
    //     if(len==n){
    //         head=head->next;
    //         return head;
    //     }
    //     int m=len-n;
    //         temp=head;
    //         for(int i=1;i<m;i++){
    //             temp=temp->next;
    //         }
    //         temp->next=temp->next->next;
    // return head;
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* temp=dummy;
        ListNode* slow=head;
        ListNode* fast=head;
        for(int i=1;i<=n;i++){
            if(fast==NULL) return head->next;
            fast=fast->next;
        }
        while(fast!=NULL){
            slow=slow->next;
            fast=fast->next;
            temp=temp->next;
        }
        temp->next=temp->next->next;
    return dummy->next;
    }
};