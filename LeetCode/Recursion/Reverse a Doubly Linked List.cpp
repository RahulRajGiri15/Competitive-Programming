/////Reverse a Doubly Linked List


/////////https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1

/*
class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/
class Solution {
    public:
      // Function to reverse a doubly linked list
      DLLNode* reverseDLL(DLLNode* head) {
          // Your code here
          if(head == NULL)return head;
          DLLNode* temp = head;
          DLLNode* back =NULL;
          
          while(temp){
              DLLNode* front = temp->next;
              temp->next=back;
              temp->prev=front;
              back = temp;
              temp = front;
          }
          return back;
          
      }
  };
  