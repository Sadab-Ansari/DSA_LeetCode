class Solution {
public:
    bool backspaceCompare(string s, string t) {

        stack<char> st1;
        stack<char> st2;

        // Process first string
        for(char ch : s){

            if(ch != '#'){
                st1.push(ch);
            }
            else if(!st1.empty()){
                st1.pop();
            }
        }

        // Process second string
        for(char ch : t){

            if(ch != '#'){
                st2.push(ch);
            }
            else if(!st2.empty()){
                st2.pop();
            }
        }

        // Compare both stacks
        return st1 == st2;
    }
};