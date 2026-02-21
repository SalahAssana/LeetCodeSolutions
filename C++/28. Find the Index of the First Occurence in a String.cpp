class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if(needle == "") return 0;
        
        int subSize = needle.length();
        int haySize = haystack.length();
        
        for (int i = 0; i <= haySize-subSize; i++)
        {
            if (haystack.substr(i,subSize) == needle)
            {
                return i;
            }
        }
        
        return -1;
    }
};