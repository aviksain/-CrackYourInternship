// Solution 1   T.C- O(n) ---------------->>>>>>>>>>

class MyQueue {
public:
    stack<int> main,helper;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!main.empty()) {
            helper.push(main.top());
            main.pop();
        }
        main.push(x);
        while(!helper.empty()) {
            main.push(helper.top());
            helper.pop();
        }
    }
    
    int pop() {
        int num = main.top();
        main.pop();
        return num;
    }
    
    int peek() {
        return main.top();
    }
    
    bool empty() {
        return main.empty();
    }
};




// Solution 2  Amortized T.C. - O(1)  ----------------->>>>>>>>>>>>>>>>>>

class MyQueue {
public:
    stack<int> input,output;
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if(output.empty()) {
            while(!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }

        int num = output.top();
        output.pop();
        return num;
    }
    
    int peek() {
        if(output.empty()) {
            while(!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }

        return output.top();
    }
    
    bool empty() {
        return (input.empty() && output.empty());
    }
};

