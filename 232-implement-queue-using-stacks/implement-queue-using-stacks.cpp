class MyQueue {
public:

    stack<int> st1;   // Input stack
    stack<int> st2;   // Output stack

    MyQueue() {

    }

    void push(int x) {

        // Always push into input stack
        st1.push(x);
    }

    int pop() {

        // Move elements only if output stack is empty
        if (st2.empty()) {

            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }

        int value = st2.top();
        st2.pop();

        return value;
    }

    int peek() {

        if (st2.empty()) {

            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }

        return st2.top();
    }

    bool empty() {

        return st1.empty() && st2.empty();
    }
};