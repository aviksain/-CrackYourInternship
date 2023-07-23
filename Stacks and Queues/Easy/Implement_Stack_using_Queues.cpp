// Solution 1 (using 2 stacks) ------------->>>>>>>>>>>

class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {
        
    }
    
    void push(int x) {
        while(!q1.empty()) {
            int it = q1.front();
            q1.pop();
            q2.push(it);
        }
        q1.push(x);
        while(!q2.empty()) {
            int it = q2.front();
            q2.pop();
            q1.push(it);
        }
    }
    
    int pop() {
        int it = q1.front();
        q1.pop();
        return it;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};








// Solution 2 (using 1 stack)  ----------------------->>>>>>>>>>>>>>>>>

class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        int n = q.size()-1;
        while(n > 0) {
            q.push(q.front());
            q.pop();
            n--;
        }    
    }
    
    int pop() {
        int num = q.front();
        q.pop();
        return num;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};



