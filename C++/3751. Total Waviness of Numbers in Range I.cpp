class Solution {
public:
    long long totalWaviness(long long num1, long long num2)
    {
        long long result = 0;
        for (auto num = num2; num >= num1; --num) {
            result += waviness_count(num);
        }

        return result;
    }

    int waviness_count(long long num)
    {
        int count = 0;
        int right = num % 10;
        num /= 10;
        int mid = num % 10;
        num /= 10;
        while (num) {
            int left = num % 10;
            num /= 10;

            count += (mid > right && mid > left) + (mid < right && mid < left);
            right = mid;
            mid = left;
        }

        return count;
    }

    unordered_map<long long, int> num_wav;
};
