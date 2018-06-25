/*Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) – Push element x onto stack.
pop() – Removes the element on top of the stack.
top() – Get the top element.
getMin() – Retrieve the minimum element in the stack.
Note that all the operations have to be constant time operations.

Questions to ask the interviewer :

Q: What should getMin() do on empty stack? 
A: In this case, return -1.

Q: What should pop do on empty stack? 
A: In this case, nothing. 

Q: What should top() do on empty stack?
A: In this case, return -1
 
NOTE : If you are using your own declared global variables, make sure to clear them out in the constructor.
*/


vector<int> st;
vector<int> m;

MinStack::MinStack() {
    st.clear();
    m.clear();
}

void MinStack::push(int x) {
    st.push_back(x);
        
    if(m.size() == 0)
        m.push_back(x);
    else 
    {
        if(x <= m.back())
            m.push_back(x);
        else
            m.push_back(m.back());
    }
}

void MinStack::pop(){
    if(st.size() != 0)
    {
        st.pop_back();
        m.pop_back();
    }
}

int MinStack::top() {
    if(st.size() == 0)
        return -1;
        
    return st.back();
}

int MinStack::getMin() {
    if(m.size() == 0)
        return -1;
    
    return m.back();
}

