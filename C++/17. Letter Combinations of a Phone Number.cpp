class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> output;
        
        unordered_map<char, string> phone = {{'2', "abc"},
                                             {'3', "def"},
                                             {'4', "ghi"},
                                             {'5', "jkl"},
                                             {'6', "mno"},
                                             {'7', "pqrs"},
                                             {'8', "tuv"},
                                             {'9', "wxyz"}};
        
        if (digits.size() != 0)
        {
            backtrack("", digits, phone, output);
        }
        return output;
    }
    
private:
    void backtrack(string combination, string digit, unordered_map<char, string> &phone, vector<string> &output)
    {
        if (digit.size() == 0)
        {
            output.push_back(combination);
        }
        else
        {
            string letters = phone[digit[0]];
            
            for (char letter : letters)
            {
                backtrack(combination + letter, digit.substr(1), phone, output);
            }
        }
    }
};