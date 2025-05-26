//////////Insert in Sorted Circular Linked List

////////https://www.geeksforgeeks.org/problems/sorted-insert-for-circular-linked-list/1

class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        //CodeGenius
        Node *NN=new Node(data),*temp=head;
        
        //case 1;
        if(head->data>data){
            NN->next=head;
            while(temp->next != head) temp=temp->next;
            temp->next=NN;
            return NN;
        }
        //case 2;
        while(temp->next!=head && temp->next->data <=data) temp=temp->next;
        NN->next=temp->next;
        temp->next=NN;
        return head;
    }
};