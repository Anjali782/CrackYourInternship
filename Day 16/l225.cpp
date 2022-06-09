class MyStack {
public:
    queue<int> main, temp;
    MyStack() {}
    
    void push(int x) {
        while(main.size()){
            temp.push(main.front());
            main.pop();
        }
        main.push(x);
        while(temp.size()){
            main.push(temp.front());
            temp.pop();
        }
    }
    
    int pop() {
        int t=main.front();
        main.pop();
        return t;
    }
    
    int top() {
        return main.front();
    }
    
    bool empty() {
        return main.size()==0;
    }
};
