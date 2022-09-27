//1
//design circular queue

class MyCircularQueue {
    private:
    vector<int> v;
    int front=0,rear=0,size=0;
public:
    MyCircularQueue(int k) {
        v.resize(k);
    }
    
    bool enQueue(int value) {
        if(isFull())
            return false;
        int k=v.size();
        v[rear%k]=value;
        rear++;
        size++;
        return true;
            
    }
    
    bool deQueue() {
        if(isEmpty())
            return false;
        int k=v.size();
        v[front%k]=-1;
        front++;
        size--;
        return true;
        
    }
    
    int Front() {
        int k=v.size();
        if(size==0)
            return -1;
        return v[(front)%k];
        
    }
    
    int Rear() {
        int k=v.size();
        if(size==0)
            return -1;
        return v[(rear-1)%k];
    }
    
    bool isEmpty() {
        if(size==0)
            return true;
        return false;
        
    }
    
    bool isFull() {
        int k=v.size();
        if(size==k)
            return true;
        return false;
    }
};

