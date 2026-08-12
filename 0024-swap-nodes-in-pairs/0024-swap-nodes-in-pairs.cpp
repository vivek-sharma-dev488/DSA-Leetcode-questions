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
// class Solution {
// public:
//     ListNode* swapPairs(ListNode* head) {
//         ListNode* dummy = new ListNode(-1);
//         dummy->next = head;
//         ListNode* curr = dummy;
//         ListNode* first = curr->next;
//         while (curr->next != NULL && curr->next->next != NULL) {
//             ListNode* second = first->next;
//             first->next = second->next;
//             second->next = first;
//             curr->next = second;
//             curr=first;
//         }
//         return dummy->next;
//     }
// };


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;
        while (curr != NULL && curr->next != NULL) {
            ListNode* next = curr->next;
            curr->next = next->next;
            next->next = curr;
            prev->next = next;
            prev = curr;
            curr = curr->next;
        }
        return dummy->next;
    }
};