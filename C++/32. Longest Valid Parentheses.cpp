class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int output = 0;
        vector<int> dp(s.size(), 0);
        
        for (int i = 1; i < s.size(); i++)
        {
            // If we incounter a closing bracket we have a possible valied parentheses
            if (s[i] == ')')
            {
                // If the previous bracket is an open
                // the max length will be the max lenth of previous max length + 2
                if (s[i-1] == '(')
                {
                    // Just check to make sure we don't go out of bounds
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                }
                // If the previous bracket is not an open
                // but there is an open before a previous valid parentheses set
                // the max length will be the length of the longest set so far +
                // previous longest set + 2
                else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(')
                {
                    dp[i] = 
                            // Longest set so far
                            dp[i - 1]
                            // Previous longest set
                            + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0)
                            // Length of new parentheses set
                            + 2;
                }
            }
            
            // Store new longest valid parentheses
            output = max(output, dp[i]);
        }
        
        return output;
    }
};