class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> output;
        backtrack(output, "", 0, 0, n);
        return output;
    }
    
private:
    void backtrack(vector<string> &output, string cur_str, int open, int close, int max_size)
    {
        if (open + close == max_size*2)
        {
            output.push_back(cur_str);
            return;
        }
        
        if (open < max_size)
        {
            backtrack(output, cur_str+"(", open+1, close, max_size);
        }
        if (close < open)
        {
            backtrack(output, cur_str+")", open, close+1, max_size);
        }
    }
};