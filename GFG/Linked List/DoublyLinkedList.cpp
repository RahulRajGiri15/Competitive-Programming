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
int main(){
    vector<int> arr = {10, 20, 30, 40, 50};
    Node* head = convert2DLL(arr);
    print(head);
    
}
