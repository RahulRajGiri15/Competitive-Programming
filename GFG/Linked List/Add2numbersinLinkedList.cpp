/////////////Add 2 numbers in LinkedList

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    public:
    Node(int data1, Node* next1){
        data=data1;
        next=next1;
    }
    public:
    Node(int data1){
        data=data1;
        next=nullptr;
    }
};

Node* add2num(Node* head1, Node* head2){
    Node* dummyHead = new Node(-1);
    Node* curr = dummyHead;
    Node* temp1 = head1;
    Node* temp2 = head2;
    int carry = 0;
    while(temp1 != nullptr && temp2 != NULL){
        int sum = carry;
        if(temp1) sum += temp1->data;
        if(temp2) sum += temp2->data;
        curr->next = new Node(sum%10);
        curr = curr->next;
        carry = sum/10;
        if(temp1) temp1= temp1->next;
        if(temp2 != NULL) temp2 = temp2->next;
        if(carry){
            Node* newNode = new Node(carry);
            curr->next = newNode;
            //curr->next = new Node(carry);
        }
    }

    return dummyHead->next;
}

////leetcode
////////https://leetcode.com/problems/add-two-numbers/

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
        ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) {
        ListNode* dummyHead = new ListNode(-1);
        ListNode* curr = dummyHead;
        ListNode* temp1 = head1;
        ListNode* temp2 = head2;
        int carry = 0;
        while(temp1 != nullptr || temp2 != NULL){
            int sum = carry;
            if(temp1) sum += temp1->val;
            if(temp2) sum += temp2->val;
            //curr->next = new ListNode(sum%10);
            ListNode* newnode = new ListNode(sum%10);
            curr->next = newnode;
            curr = curr->next;
            carry = sum/10;
            if(temp1) temp1= temp1->next;
            if(temp2 != NULL) temp2 = temp2->next;
            if(carry){
                // ListNode* newNode = new ListNode(carry);
                // curr->next = newNode;
                curr->next = new ListNode(carry);
            }
        }
        return dummyHead->next;
        }
    };
    