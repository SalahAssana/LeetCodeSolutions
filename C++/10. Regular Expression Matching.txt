class Solution {
public:
    bool isMatch(string s, string p)
    {
        unordered_map<string, bool> dpTable;
        return isMatch(s, p, ' ', dpTable);
    }
private:
    bool isMatch(string s, string p, char prevChar, unordered_map<string, bool> &dpTable)
    {
        // Generate a string to be the key
        string key = s + " - " + p;
        
        if (dpTable.count(key))
        {
            return dpTable[key];
        }
        
        bool ans = false;
        
        // If we reached end of input string
        if (s.size() == 0)
        {
            // If both strings ended then we have a match
            if (p.size() == 0)
            {
                ans = true;
            }
            
            if (prevChar != ' ')
            {
                ans = isMatch(s, p.substr(1), ' ', dpTable);
            }
            else if (p.size() > 1 && p[1] == '*')
            {
                ans = isMatch(s, p.substr(2), ' ', dpTable);
            }
        }
        // If we are out of pattern there is no way it could match
        else if (p.size() == 0)
        {
            ans = false;  
        }
        // If we are in a star loop
        else if (prevChar != ' ')
        {
            // If it's possible to generate a match
            if (s[0] == prevChar || prevChar == '.')
            {
                ans = isMatch(s.substr(1), p, prevChar, dpTable) || isMatch(s, p.substr(1), ' ', dpTable);
            }
            // If the previous char does not match the needed on we can't use *
            else
            {
                ans = isMatch(s, p.substr(1), ' ', dpTable);
            }
        }
        // Check if it's possible to generate the necessary char for string
        else if (p.size() > 1 && p[1] == '*')
        {
            ans = isMatch(s, p.substr(1), p[0], dpTable);
        }
        // If there is a match move on to next character
        else if (s[0] == p[0] || p[0] == '.')
        {
            ans = isMatch(s.substr(1), p.substr(1), ' ', dpTable);
        }
        
        dpTable[key] = ans;
        
        // If there is no possible way to make a match then return false
        return ans;
    }
};