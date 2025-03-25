//////////Introduction to LinkedList - Traversal - Length - Search an Element

///////


/////introduction

#include <bits/stdc++.h>
using namespace std;
#include<iostream>
class Node {
    public:
    int data;
    Node* next;
    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
    public:
    Node(int data1){
        data = data1;
        next =nullptr;
    }
};

////basic intro

// int main(){
//     vector<int> arr ={1,2,3,4};
//     Node* y = new Node(arr[0],nullptr);
//     cout<<y->data;
//     cout<<endl;
//     Node* z = new Node(arr[2]);
//     cout<<z->data<<endl;
//     cout<<z->next;
    
// }

////convert array to linked list

Node* converarr2LL(vector<int> arr){
    Node* head = new Node(arr[0]);
    Node* mover= head;
    for(int i=1;i<arr.size();i++){
        Node* temp= new Node(arr[i]);
        mover->next = temp; 
        mover =temp;
    }
    return head;
}

// int main(){
//     vector<int> arr ={11,2,3,4};
//     Node* head = converarr2LL(arr);
//     cout<<head->data;
// }

//////traversal of linked list

// int main(){
//     vector<int> arr={1,2,3,4};
//     Node* head =converarr2LL(arr);
//     Node* temp = head;
//     while(temp){
//         cout<<temp->data<<" ";
//         temp = temp->next;
//     }
// }

////////length of linked list

int LengthofLL(Node* head){
    int count=0;
    Node* temp = head;
    while(temp!=nullptr){
        count++;
        temp = temp->next;
    }
    return count;
}
// int main(){
//     vector<int> arr={1,2,4,5,9};
//     Node* head = converarr2LL(arr);
//     int len = LengthofLL(head);
//     cout<<len;
// }

///////to  check a digit is present or not

int checkdigit(Node* head, int k){
    Node* temp =head;
    while(temp){
         if(temp->data == k) return 1 ;
         temp =temp->next;
    }
    return 0;
}
int main(){
    vector<int> arr={1,3,5,67,9};
    Node* head = converarr2LL(arr);
    int k=5;
    int ans = checkdigit(head,k);
    cout<<ans;
}