class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == INT32_MIN && divisor == -1) return INT32_MAX;
        if (divisor == INT32_MIN) return dividend == INT32_MIN ? 1 : 0;
        if (divisor == 1) return dividend;
        
		// subtract 1 temporarily, add back later
        bool isMin = false;
        if (dividend == INT32_MIN)
        {
            isMin = true;
            dividend++;
        }
        
        int quotient = 0;
        int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
        
        dividend = abs(dividend);
        divisor = abs(divisor);
        
        while (dividend >= divisor)
        {
            int accumilator = divisor, k = 1;
            
			// Note that accumilator << 1 could be less than 0
            while ((accumilator << 1) > 0 && (accumilator << 1) <= dividend)
            {
                accumilator <<= 1;
                k <<= 1;    // Count the number of shifts
            }
            
            dividend -= accumilator;
            quotient += k;
        }
        
        if (isMin)
        {
            dividend++;
            
            while (dividend >= divisor)
            {
                quotient++;
                dividend -= divisor;
            }
        }
        
        return sign == true ? quotient : -quotient;
    }
};