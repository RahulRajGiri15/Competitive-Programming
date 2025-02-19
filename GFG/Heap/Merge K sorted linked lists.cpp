////Merge K sorted linked lists

class Solution {
    public:
      #define p pair<int,Node*>
      Node* mergeKLists(vector<Node*>& arr) {
          Node* newHead = new Node(-1);   ////we make a node with value -1 
          priority_queue<p , vector<p>,greater<p>>pq;  //// MinHeap
          for(int i =0 ;i<arr.size();i++){
              Node* temp =arr[i];             //////////temp is storing node data
              pq.push({temp->data,temp});
          }
          Node* temp =newHead;   ///////new temp node
          while(!pq.empty()){
              Node* curr = pq.top().second;   //// curr is storeing node of linked list 
              pq.pop();                       //// deleting the above (top) element 
              temp->next = curr;              /// temp stroes curr (-1 -> curr)
              temp=temp->next;
              if(curr->next) pq.push({curr->next->data,curr->next}); //next ele in minHeaHeap
          }
          return newHead->next;
      }
  };
  
