class Solution
{
public:
    int myAtoi(string str)
    {
        long long int output = 0;
        int result;
        
        stringstream ss(str);
        ss >> output;
        
        if(output > INT_MAX)
        {
            return INT_MAX;
        }
        else if(output < INT_MIN)
        {
            return INT_MIN;
        }
        else
        {
            result = output;
        }
        
        return result; 
    }
};