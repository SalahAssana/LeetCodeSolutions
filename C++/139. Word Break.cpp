class Solution
{
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        unordered_set<string> wordDictHash(wordDict.begin(), wordDict.end());
        
        s = "!" + s;
        vector<bool> dpArray(s.size());
        dpArray[0] = true;
        
        for(int i=0; i<s.size(); i++)
        {
            for(int j=i+1; j<s.size(); j++)
            {
                if(dpArray[j]) continue;
                
                if(wordDictHash.find(s.substr(i+1, j-i))!=wordDictHash.end() && dpArray[i])
                    dpArray[j] = true;
            }
        }
        
        return dpArray[dpArray.size()-1];
    }
};