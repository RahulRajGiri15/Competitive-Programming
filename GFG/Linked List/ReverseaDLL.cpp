////////Reverse a DLL 

#include <bits/stdc++.h>
#include<iostream>
using namespace std;
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

Node* convertarr2DLL( vector<int> &arr){
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
    Node* temp =head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

//////////Brute force 
// Node* reverseDLL(Node* head){
//     stack<int> st;
//     Node* temp = head;
//     while(temp !=NULL){
//         st.push(temp->data);
//         temp=temp->next;
//     }
//     temp = head;
//     while(temp != NULL){
//         temp->data = st.top();
//         st.pop();
//         temp=temp->next;
//     }
//     return head;
// }

// int main(){
//     vector<int> arr = {10, 20, 30, 40, 50};
//     Node* head = convertarr2DLL(arr);
//     head = reverseDLL(head);
//     print(head);
//     return 0;
// }

///////optimal solution

Node* reverseDLL(Node* head){
    Node* last = nullptr;
    Node* current = head;
    while(current !=NULL){
        last = current->prev;
        current->prev = current->next;
        current->next = last;
        current = current->prev;
    }
    return last->prev;
}
int main(){
    vector<int> arr = {10, 20, 30, 40, 50};
    Node* head = convertarr2DLL(arr);
    head = reverseDLL(head);
    print(head);
    return 0;
}