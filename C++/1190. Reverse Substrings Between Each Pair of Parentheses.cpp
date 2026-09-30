class Solution {
public:
    string reverseParentheses(string s) {
        string result;
        int n = s.size();

        result.reserve(n);
        stack<int> st;

        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (c == '(') st.push(i);
            else if (c == ')') {
                int end = i;
                int start = st.top() + 1; st.pop();

                while(start < end) {
                    char temp = s[start];
                    s[start] = s[end];
                    s[end] = temp;

                    start++;
                    end--;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (c >= 'a' && c <= 'z') result.push_back(c);
        }

        return result;
    }
};
