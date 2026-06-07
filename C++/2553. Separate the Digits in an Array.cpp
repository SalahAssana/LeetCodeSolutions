class Solution {
public:
    vector<int> separateDigits(vector<int>& nums)
    {
        vector<int> result;
        stack<int> digits;

        for (auto num : nums) {
            if (num < 10) {
                result.push_back(num);
                continue;
            }
            while (num) {
                digits.push(num % 10);
                num /= 10;
            }

            while (digits.size()) {
                result.push_back(digits.top());
                digits.pop();
            }
        }

        return result;
    }
};
