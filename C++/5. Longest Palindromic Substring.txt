int find_len(string s, int l, int r, int half_len)
{
    int ans=0;
    
    for(int i=0;i<half_len;i++)
    {
        ans = i;
        
        if (s[l]!=s[r])
        {
            ans--;
            break;
        }
        
        l--;
        r++;
    }
    
    return ans;
}

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int N = s.length();
        int odd, l, r, half_len;
        int start = 0, max_len = 1, len;
        
        for (int center = 1; center < 2*N-2; center++)
        {
            odd = center % 2;
            l = (center - odd)/2; 
            r = (center + odd)/2;
            
            half_len = (center < N) ? 1+l : N-r ;
            half_len = find_len(s, l, r, half_len);
            
            len = odd + 1 + 2*half_len;
            
            if (len > max_len)
            {
                max_len = len;
                start = l+1-(max_len+1-odd)/2;
            }
        }
        return s.substr(start,max_len);
    }
};