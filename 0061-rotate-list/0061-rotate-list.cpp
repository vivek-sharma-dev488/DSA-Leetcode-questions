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
    int length(ListNode* head){
        int len = 0;
        ListNode* temp = head;
        while(temp != NULL){
            len++;
            temp = temp->next;
        }
        return len;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL or head->next == NULL) return head;
        int n = length(head);
        k = k%n;
        if(k == 0) return head;
        ListNode* a = head; // k+1 th from end
        ListNode* b = head; // kth from end (new head)
        ListNode* c = head; // last node
        ListNode* temp = head;
        for(int i=1;i<=n;i++){
            if(i == n-k) a = temp;
            if(i == n-k+1) b = temp;
            if(i == n) c = temp;
            temp = temp->next;
        }
        a->next = NULL;
        c->next = head;
        return b;
    }
};