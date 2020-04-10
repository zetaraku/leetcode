// Title: Min Stack
// Description:
//     Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
//         push(x) -- Push element x onto stack.
//         pop() -- Removes the element on top of the stack.
//         top() -- Get the top element.
//         getMin() -- Retrieve the minimum element in the stack.
//     Hint #1: Consider each node in the stack having a minimum value. (Credits to @aakarshmadhavan)
// Link: https://leetcode.com/problems/min-stack/

// Time complexity: O(1) for { push(x), pop(), top(), getMin() }
// Space complexity: O(n)
class MinStack {
private:
    enum { DATA_SLOT, MIN_DATA_SLOT };
    stack<tuple<int,int>> data;
    
public:
    MinStack() {
        
    }
    
    void push(int x) {
        data.push(std::make_tuple(
            /* DATA_SLOT */ x,
            /* MIN_DATA_SLOT */ !data.empty() ? std::min(getMin(), x) : x
        ));
    }
    
    void pop() {
        data.pop();
    }
    
    int top() {
        return std::get<DATA_SLOT>(data.top());
    }
    
    int getMin() {
        return std::get<MIN_DATA_SLOT>(data.top());
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
