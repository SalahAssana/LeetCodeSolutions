class Solution {
public:
    int reverse(int x)
    {
        long int reversed_int{};
        
        while (x)
        {
            reversed_int = reversed_int * 10 + x % 10;
            x /= 10;
        }
        
        return (reversed_int > INT_MIN && reversed_int < INT_MAX) ? (int) reversed_int : 0;
    }
};