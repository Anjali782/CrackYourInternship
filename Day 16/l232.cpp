class MyQueue {
public:
    stack<int> input;
    stack<int> output;
    
    MyQueue() {}
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        int res = -1; 
        if(!output.empty()){   
            res = output.top();
            output.pop();
            return res;
        }
        
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }
        
        res= output.top();
        output.pop();
        return res;
    }
    
    int peek() {
        int res = -1;  
        if(!output.empty()){  
            res = output.top();
            return res;
        }
       
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }
        
        res= output.top();
        return res;
    }
    
    bool empty() {
        return (input.empty() && output.empty());
    }
};
