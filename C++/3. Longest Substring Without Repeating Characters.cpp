class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> char_set;
        
        int start = 0;
        int end = 0;
        int n = s.size();
        int max_size = 0;
        
        while (start < n && end < n)
        {
            if (char_set.find(s[end]) == char_set.end())
            {
                char_set.insert(s[end]);
                end++;
                max_size = max(max_size, end-start);
            }
            else
            {
                char_set.erase(s[start]);
                start++;
            }
        }
        
        return max_size;
    }
};