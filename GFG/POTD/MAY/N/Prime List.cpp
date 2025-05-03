////////Prime List
////https://www.geeksforgeeks.org/problems/prime-list--170646/1

class Solution {
    public:
      bool prime(int n){
          if(n<=1) return false;
          for(int i=2;i*i<=n;i++){
              if(n%i==0) return false;
          }
          return true;
      }
      int nearestprime(int n){
          if(prime(n)) return n;
          int prev=n-1;
          int next=n+1;
          while(true){
          if(prev>=2 && prime(prev)) return prev;
          if(prime(next)) return next;
          --prev;
          ++next;
          }
      }
      Node *primeList(Node *head) {
          // CodeGenius
          Node* temp=head;
          while(temp){
              temp->val=nearestprime(temp->val);
              temp=temp->next;
          }
          return head;        
      }
  };