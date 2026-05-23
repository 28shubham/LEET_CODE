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
    bool isPalindrome(ListNode* head) {

        if(head == nullptr || head->next == nullptr)
            return true;

        ListNode* rabit = head;
        ListNode* t = head;
        int length = 0;

        // Find middle
        while(rabit != nullptr && rabit->next != nullptr) {
            t = t->next;
            rabit = rabit->next->next;
            length++;
        }

        // Skip middle node for odd length list
        if(rabit != nullptr) {
            t = t->next;
        }

        // Reverse second half
        ListNode* prev = nullptr;
        ListNode* curr = t;

        while(curr != nullptr) {
            ListNode* nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }

        // Compare first half and reversed second half
        while(prev != nullptr) {
            if(prev->val != head->val) {
                return false;
            }

            prev = prev->next;
            head = head->next;
        }

        return true;
    }
};