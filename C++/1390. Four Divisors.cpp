class Solution {
public:
    int sumFourDivisors(vector<int>& nums)
    {
        int result = 0;
        unordered_map<int, int> m;

        for (auto num : nums) {
            if (m[num] == -1)
                continue;
            else if (m[num] > 0) {
                result += m[num];
            } else {
                int div_count = 2, div_sum = 1 + num;
                for (int i = 2; i <= num / 2; ++i) {
                    int divisible = num % i == 0;
                    div_count += divisible;
                    div_sum += i * divisible;
                }

                if (div_count == 4) {
                    result += div_sum;
                    m[num] = div_sum;
                } else {
                    m[num] = -1;
                }
            }
        }

        return result;
    }
};
