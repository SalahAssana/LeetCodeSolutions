class Solution {
public:
    int countPrimeSetBits(int left, int right)
    {
        int result = 0;
        while (left <= right) {
            int bit_count = count_bits(left++);
            result += isPrime(bit_count);
        }

        return result;
    }

    int count_bits(int num)
    {
        int result = 0;
        for (int i = 0; i < 32; ++i) {
            result += (num & (1 << i)) != 0;
        }
        return result;
    }

    bool isPrime(int num)
    {
        switch (num) {
        case 2:
        case 3:
        case 5:
        case 7:
        case 11:
        case 13:
        case 17:
        case 19:
        case 23:
        case 29:
        case 31:
        case 37:
        case 41:
        case 43:
        case 47:
        case 53:
        case 57:
        case 59:
        case 61:
            return true;
        }

        return false;
    }
};
