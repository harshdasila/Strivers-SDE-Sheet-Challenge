#include<stack>
class Queue {
    stack<int>input,output;
    
    public:
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        input.push(val);
    }

    int deQueue() {
        if(output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
            if(output.empty()) return -1;
            int ele = output.top();
            output.pop();
            return ele; 
        }
        
        int ele = output.top();
        output.pop();
        return ele; 
    }

    int peek() {
       if(output.empty()){
           while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
            if(output.empty()) return -1;
           int ele  = output.top();
           return ele;
       }
       int ele = output.top();
       return ele;
    }

    bool isEmpty() {
        return (input.empty() && output.empty());
    }
};