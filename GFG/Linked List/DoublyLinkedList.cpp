///////Introduction to Doubly LinkedList

#include <bits/stdc++.h>
using namespace std;
#include<iostream>
class Node {
    public:
    int data;
    Node* next;
    Node* prev;
    public:
    Node(int data1, Node* next1, Node* prev1){
        data = data1;
        next = next1;
        prev = prev1;
    }
    public:
    Node(int data1){
        data = data1;
        next =nullptr;
        prev = nullptr;
    }
};

Node* convert2DLL( vector<int> &arr){
    Node* head= new Node(arr[0]);
    Node* prev = head;
    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i],nullptr,prev);
        prev->next =temp;
        prev =temp;
    }
    return head;
}
void print(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    // while(head!=NULL){
    //     cout<<head->data<<" ";
    //     head=head->next;
    // }
}
// int main(){
//     vector<int> arr = {10, 20, 30, 40, 50};
//     Node* head = convert2DLL(arr);
//     print(head);
    
// }

Node* deleteHead(Node* head){
    if(head==NULL || head->next ==NULL) return NULL;
    Node* temp = head;
    head = head->next;
    head->prev= nullptr;
    temp->next=nullptr;
    delete temp;
    return head;
}
// int main(){
//     vector<int> arr = {10, 20, 30, 40, 50};
//     Node* head = convert2DLL(arr);
//     head = deleteHead(head);
//     print(head);
//     return 0;
// }

Node* deleteTail(Node* head){
    if(head==NULL || head->next ==NULL) return NULL;
    Node* tail = head;
    while(tail->next != NULL){
        tail =tail->next;
    }
    Node* newTail = tail->prev;
    newTail->next = NULL;
    tail->prev = NULL;
    delete tail;
    return head;
}
// int main(){
//     vector<int> arr = {10, 20, 30, 40, 50};
//     Node* head = convert2DLL(arr);
//     head = deleteTail(head);
//     print(head);
//     return 0;
// }

Node* removeKthElement(Node* head,int k){
    if(head==NULL) return NULL;
    int cnt =0;
    Node* kNode = head;
    while(kNode!=NULL){
        cnt++;
        if(cnt==k) break;
        kNode=kNode->next;
    }
    Node* prevv = kNode->prev;
    Node* frontt = kNode->next;
    if(prevv == NULL && frontt == NULL){
        return NULL;
    }
    else if(prevv == NULL){
        return deleteHead(head);
    }
    else if(frontt == NULL){
        return deleteTail(head);
    }
    prevv->next = frontt;
    frontt->prev = prevv;
    kNode->next = nullptr;
    kNode->prev = NULL;
    delete kNode;
    return head;
}
// int main(){
//     vector<int> arr = {10, 20, 30, 40, 50};
//     Node* head = convert2DLL(arr);
//     head = removeKthElement(head,1);
//     print(head);
//     return 0;
// }


//temp != head; ////temp is never head node 
void deleteNode(Node* temp){
    Node* prevv = temp->prev;
    Node* frontt = temp->next;
    if(frontt == NULL){
        prevv->next == NULL;
        temp->prev = NULL;
        free(temp);
        return;
    }
    prevv->next = frontt;
    frontt->prev = prevv;
    temp->next = nullptr;
    temp->prev = NULL;
    free(temp);
}
// int main(){
//     vector<int> arr = {10, 20, 30, 40, 50};
//     Node* head = convert2DLL(arr);
//     deleteNode(head->next->next);
//     print(head);
//     return 0;
// }



////////INsertion in Doubly LinkedList///////

Node* insertBeforeHead(Node* head, int val){
    Node* newHead = new Node(val,head,nullptr);
    head->prev = newHead;
    return newHead;
}
// int main(){
//     vector<int> arr = {10, 20, 30, 40, 50};
//     Node* head = convert2DLL(arr);
//     head = insertBeforeHead(head,15);
//     print(head);
//     return 0;
// }

Node* insertBeforeTail(Node* head, int val){
    if(head == NULL) return new Node(val);
    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    Node* prevv = tail->prev;
    Node* newNode = new Node(val,tail,prevv);
    tail->prev = newNode;
    prevv->next = newNode;
    return head;
}
// int main(){
//     vector<int> arr = {10, 20, 30, 40, 50};
//     Node* head = convert2DLL(arr);
//     head = insertBeforeTail(head,60);
//     print(head);
//     return 0;
// }

Node* insertBeforeKthElement(Node* head, int k ,int val){
    if(k==1) return new Node(val,head,nullptr);
    int cnt =0;
    Node* kNode = head;
    while(kNode!=NULL){
        cnt++;
        if(cnt==k) break;
        kNode=kNode->next;
    }
    Node* prevv = kNode->prev;
    Node* newNode = new Node(val,kNode,prevv);
    kNode->prev = newNode;
    prevv->next = newNode;
    return head;
}
// int main(){
//     vector<int> arr = {10, 20, 30, 40, 50};
//     Node* head = convert2DLL(arr);
//     head = insertBeforeKthElement(head,3,25);
//     print(head);
//     return 0;
// }

void insertBeforeNode(Node* temp,int val){
    Node* prevv = temp->prev;
    Node* newNode = new Node(val,temp,prevv);
    temp->prev = newNode;
    prevv->next = newNode;
}
int main(){
    vector<int> arr={10,20,30,40,50};
    Node* head = convert2DLL(arr);
    insertBeforeNode(head->next->next->next,35);
    print(head);
    return 0;
}