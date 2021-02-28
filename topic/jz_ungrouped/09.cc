class CQueue {
public:
    std::stack<int> first;
    std::stack<int> second;
    CQueue() {

    }
    
    void appendTail(int value) {
        first.push(value);
    }
    
    int deleteHead() {
        if(second.empty()) {
            while(!first.empty()) {
                second.push(first.top());
                first.pop();
            }
        }
        if(second.empty()) {
            return -1;
        } else {
            auto tmp = second.top();
            second.pop();
            return tmp;
        }
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */