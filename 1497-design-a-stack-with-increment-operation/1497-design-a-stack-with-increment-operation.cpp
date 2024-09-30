class CustomStack {
public:
    vector<int> stack;
    int top;
    CustomStack(int maxSize) {
        stack.resize(maxSize);
        top=-1;
    }
    
    void push(int x) {
        if(top==stack.size()-1) return;
        stack[++top] = x;
    }
    
    int pop() {
        if(top==-1) return -1;

        return stack[top--];
    }
    
    void increment(int k, int val) {
        for(int i=0; i<=min(top, k-1); i++) stack[i]+=val;
    }
};

// 1 2 3
// 101 102 103
// 201 202 103


/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */