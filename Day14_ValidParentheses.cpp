class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char c: s) {
            cout << c << " ";
            if(st.empty() || c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if((c == ')' && st.top() == '(') || (c == '}' && st.top() == '{') || (c == ']' && st.top() == '['))
                    st.pop();
                else
                    st.push(c);
            }
        }

        return st.empty() ? true : false;
    }
};