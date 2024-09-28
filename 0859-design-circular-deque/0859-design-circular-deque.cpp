class MyCircularDeque {
public:
    typedef struct Node{
        Node *pre;
        int val;
        Node *next;
        Node(int d){
            val=d;
            pre=NULL;
            next=NULL;
        }
    }Node;

    Node* head, *tail;
    int size, k;

    MyCircularDeque(int k1) {
        head=NULL;
        tail=NULL;
        k=k1;
        size=0;
    }
    
    bool insertFront(int value) {
        if(size==k) return false;

        Node *cur = new Node(value);
        size++;
        if(head==NULL){
            head=cur;
            tail=cur;
        } else{
            cur->next = head;
            head->pre = cur;
            head = cur;
        }

        return true;
    }
    
    bool insertLast(int value) {
        if(size==k) return false;

        Node *cur = new Node(value);
        size++;

        if(head==NULL){
            tail=cur;
            head=cur;
        } else{
            tail->next = cur;
            cur->pre = tail;
            tail = cur;
        }

        return true;
    }
    
    bool deleteFront() {
        if(size==0) return false;

        if(size==1){
            tail=NULL;
            head=NULL;
        } else{
            head = head->next;
            head->pre = NULL;
        }

        size--;
        return true;
    }
    
    bool deleteLast() {
        if(size==0) return false;

        if(size==1){
            tail=NULL;
            head=NULL;
        } else{
            tail=tail->pre;
            tail->next = NULL;
        }

        size--;
        return true;
    }
    
    int getFront() {
        if(size==0) return -1;
        return head->val;
    }
    
    int getRear() {
        if(size==0) return -1;
        return tail->val;
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size==k;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */