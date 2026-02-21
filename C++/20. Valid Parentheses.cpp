class Solution {
public:
    bool isValid(string s)
    {
        if (s.size() == 0) return true;
        if (s.size() == 1) return false;
        
        stack<char> open;
        
        for (char bracket : s)
        {
            if (bracket == '{' || bracket == '[' || bracket == '(')
            {
                open.push(bracket);
            }
            else
            {
                if(open.size() == 0 ) return false;
                
                char open_bracket = open.top(); open.pop();
                
                if (open_bracket == '[' && bracket != ']')
                {
                    return false;
                }
                if (open_bracket == '(' && bracket != ')')
                {
                    return false;
                }
                if (open_bracket == '{' && bracket != '}')
                {
                    return false;
                }
            }
        }
        
        if(open.size() == 0) return true;
        return false;
    }
};