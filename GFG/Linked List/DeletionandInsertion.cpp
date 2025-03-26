//////////GFG/Linked List/Deletion and Insertion in LL

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
Node* convertarr2LL(vector<int> arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++){
        Node* temp= new Node(arr[i]);
        mover->next = temp;
        mover=temp;
    }
    return head;
}

void print(Node* head){
    Node* temp= head;
    while(temp){
        cout<<temp->data<<" ";
        temp= temp->next;
    }
}

Node* deletehead(Node* head){
    if(head==nullptr) return head;  // If list is empty, return NULL
    Node* temp = head;
    head= head->next;
    free(temp);
    return head;
}


// int main(){
//     vector <int> arr={100,2,3,4};
//     Node* head= convertarr2LL(arr);
//     head=deletehead(head);
//     print(head);
// }

Node* deletelast(Node* head){
    if(head==NULL || head->next == nullptr) return head; // if list is empty or has only one element
    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    delete (temp->next);
    temp->next = NULL;
    return head;
}
// int main(){
//     vector <int> arr={100,2,3,4};
//     Node* head= convertarr2LL(arr);
//     head=deletelast(head);
//     print(head);
// }

Node* removeK(Node* head,int k){
    if(head==nullptr) return head;
    if(k==1) {
        Node* temp = head;
        head=head->next;
        free(temp);
        return head;
    }
    int cnt=0;
    Node* temp =head;
    Node* prev = NULL;
    while(temp != NULL){
        cnt++;
        if(cnt==k) {
            prev->next = prev->next->next;
            free(temp);
        }
        prev =temp;
        temp= temp->next;
    }
    return head;
}

// int main(){
//     vector <int> arr={100,2,3,4};
//     Node* head= convertarr2LL(arr);
//     head=deletelast(head);
//     print(head);
// }

Node* removeEl(Node* head, int el){
    if(head==NULL) return head;
    if(head->data == el){
        Node* temp = head;
        head=head->next;
        free(temp);
        return head;
    }
    Node* temp =head;
    Node* prev =NULL;
    while(temp!=NULL){
        if(temp->data == el){
            prev->next = prev->next->next;
            free(temp);
        }
        prev = temp;
        temp=temp->next;
    }
    return head;
}

// int main(){
//     vector<int> arr={100,2,3,4};
//     Node* head= convertarr2LL(arr);
//     head=removeEl(head,100);
//     print(head);
// }


//////////Insertion /////////

Node* inserthead(Node* head,int val){
    Node* temp = new Node(val);
    temp->next =head;
    return temp;
}
// int main(){
//     vector<int> arr={100,2,3,4};    
//     Node* head= convertarr2LL(arr);
//     head=inserthead(head,1089);
//     //head = new Node(2133,head);;
//     print(head);
// }

Node* insertTail(Node* head,int val){
    if(head == NULL) return new Node(val);
    Node* temp = head;
    while(temp->next != NULL){
        temp =temp->next;
    }
    temp->next = new Node(val);
    return head;
}
// int main(){
//     vector<int> arr={100,2,3,4};
//     Node* head= convertarr2LL(arr);
//     head=insertTail(head,1769); 
//     print(head);
// }

Node* inserPosition(Node* head,int val ,int k){
    if(head == NULL) {
        if(k== 1) return new Node(val);
        else return head;
    }
    if(k==1){
        Node* temp = new Node(val);
        temp-> next = head;
        return temp;
        // return new Node(val,head);
    }
    int cnt = 0;
    Node* temp = head;
    while(temp != NULL){
        cnt++;
        if(cnt==(k-1)){
            Node* newwnode = new Node(val,temp->next);
            temp->next = newwnode;
            break;
        }
        temp = temp->next;
    }
    return head;
}

// int main(){
//     vector<int> arr={100,2,3,4};
//     Node* head= convertarr2LL(arr);
//     head=inserPosition(head,1769,3);
//     print(head);
// }

//// insert el before the value val

Node* insertBeforeValue(Node* head, int el ,int val){
    if(head->data == val){
        Node* temp = new Node(el,head);
        return temp;
    }
    Node* temp = head;
    while(temp->next !=NULL){
        if(temp->next->data == val){
            Node* newwnode = new Node(el,temp->next);
            temp->next = newwnode;
            break;
        }
        temp =temp->next;
    }
    return head;
}

int main(){
    vector<int> arr={100,2,3,4};
    Node* head= convertarr2LL(arr);
    head=insertBeforeValue(head,1769,4);
    print(head);
}