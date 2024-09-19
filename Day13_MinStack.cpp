// Approach 1, Using 2 stacks

class MinStack {
public:

    stack<int> st;
    stack<int> minStack;

    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(minStack.empty() || val <= minStack.top())
            minStack.push(val);
    }
    
    void pop() {
        if(st.top() == minStack.top())
            minStack.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};


// Approach 2, Using a single stack of pair<int, int>

class MinStack {
public:

    stack<pair<int, int>> st;

    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty())
            st.push({val, val});
        else
            st.push({val, min(st.top().second, val)});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};