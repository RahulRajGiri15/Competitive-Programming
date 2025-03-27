////////Check if a LinkedList is Palindrome or Not

/////https://leetcode.com/problems/palindrome-linked-list/

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

 //////////method 1--brute force/----using stack property
class Solution {
    public:
        bool isPalindrome(ListNode* head) {
            stack<int> st ; 
            ListNode* temp = head;
            while(temp){
                st.push(temp->val);
                temp= temp->next;
            }
            temp = head;
            while(temp != NULL){
                if(temp->val != st.top()) return false; 
                st.pop();
                temp=temp->next;
            }
            return true;
        }
    };