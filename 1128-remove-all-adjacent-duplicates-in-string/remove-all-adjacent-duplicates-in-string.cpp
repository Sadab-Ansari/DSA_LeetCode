class Solution {
public:
    string removeDuplicates(string s) {

        // Stack to store characters
        stack<char> st;

        // Traverse each character of the string
        for(char ch : s){

            // If stack is not empty and top character
            // is same as current character,
            // remove the duplicate pair.
            if(!st.empty() && st.top() == ch){
                st.pop();
            }
            else{
                // Otherwise keep the character
                st.push(ch);
            }
        }

        // Store answer
        string ans = "";

        // Stack gives characters in reverse order
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        // Reverse to restore original order
        reverse(ans.begin(), ans.end());

        return ans;
    }
};