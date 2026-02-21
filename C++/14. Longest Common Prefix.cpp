class Solution
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        if (strs.size() == 0) return "";
        
        return longestCommonPrefix(strs, 0 , strs.size() - 1);
    }
    
private:
    
    string longestCommonPrefix(vector<string>& strs, int l, int r)
    {
        if (l == r)
        {
            return strs[l];
        }
        else
        {
            int mid = (l + r)/2;
            string lcpLeft =   longestCommonPrefix(strs, l , mid);
            string lcpRight =  longestCommonPrefix(strs, mid + 1,r);
            return commonPrefix(lcpLeft, lcpRight);
       }
    }

    string commonPrefix(string left, string right)
    {
        int min_length = min(left.length(), right.length());   
        
        for (int i = 0; i < min_length; i++)
        {
            if (left[i] != right[i])
                return left.substr(0, i);
        }
        
        return left.substr(0, min_length);
    }
};