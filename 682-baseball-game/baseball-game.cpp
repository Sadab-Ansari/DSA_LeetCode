class Solution {
public:
    int calPoints(vector<string>& operations) {

        // Stack stores all valid scores
        stack<int> st;

        // Traverse every operation
        for (string op : operations) {

            // Remove previous score
            if (op == "C") {
                st.pop();
            }

            // Double previous score
            else if (op == "D") {
                st.push(st.top() * 2);
            }

            // Sum of previous two scores
            else if (op == "+") {

                // Last score
                int first = st.top();
                st.pop();

                // Second last score
                int second = st.top();

                // Put first score back
                st.push(first);

                // Push their sum
                st.push(first + second);
            }

            // It is a normal number
            else {

                // Convert string to integer
                st.push(stoi(op));
            }
        }

        // Calculate total score
        int sum = 0;

        while (!st.empty()) {
            sum += st.top();
            st.pop();
        }

        return sum;
    }
};