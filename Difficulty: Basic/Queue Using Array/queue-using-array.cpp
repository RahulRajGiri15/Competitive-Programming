class myQueue {
    queue<int>que;
    int qs;
  public:
    myQueue(int n) {
        // Define Data Structures
        qs = n;
    }

    bool isEmpty() {
        // check if the queue is empty
        return (que.empty());
    }

    bool isFull() {
        // check if the queue is full
        return (que.size() == qs);
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue.
        if(que.size() != qs){
            que.push(x);
        }
    }

    void dequeue() {
        // Removes the front element of the queue.
        if(!que.empty()){
            que.pop();
        }
    }

    int getFront() {
        // Returns the front element of the queue.
        if(!que.empty()){
            return que.front();
        }
        return -1;
    }

    int getRear() {
        // Return the last element of queue
        if(!que.empty()){
            return que.back();
        }
        return -1;
    }
};