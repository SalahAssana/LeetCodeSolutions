class Solution {
public:
    vector<int> plusOne(vector<int>& digits)
    {
        for (int k = digits.size() - 1; k >= 0; --k)
        {
            // If the current value is less then 9 we just increment an return
            if (digits[k] < 9)
            { 
                digits[k]++; 
                return digits; 
            }
            // Otherwise it will become a 0 and the 1 will carry
            else
            {
                digits[k] = 0;
            }
        }
        
        // If we exit the loop we need to append a 0 to the end
        digits[0] = 1, digits.push_back(0);
        return digits;
    }
};