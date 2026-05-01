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
    ListNode* findMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while(cur){
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* mid = findMiddle(head);
        ListNode* ptr2 = reverse(mid);
        ListNode* ptr1 = head;
        bool res = true;
        while(ptr2){
            if(ptr1->val != ptr2->val){
                return false;
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return res;
    }
};