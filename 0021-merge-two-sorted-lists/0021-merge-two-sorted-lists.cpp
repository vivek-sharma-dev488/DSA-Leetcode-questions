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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy=new ListNode(-1);
        ListNode*  tC=dummy;
        ListNode* tA=list1;
        ListNode* tB=list2;
        while(tA!=NULL && tB!=NULL ){
            if(tA->val<=tB->val){
                tC->next=tA;
                tA=tA->next;
                tC=tC->next;
            }
            else{
                tC->next=tB;
                tB=tB->next;
                tC=tC->next;
            }
        }
        if(tA==NULL) tC->next=tB;
        else tC->next=tA;
        return dummy->next;
    }
};