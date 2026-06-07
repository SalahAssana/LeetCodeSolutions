class Solution {
public:
    int rotatedDigits(int n)
    {
        int result = 0;
        for (int i = 1; i <= n; ++i) {
            int num = rotate_number(i);
            result += (num != i) && (num != -1);
        }

        return result;
    }

    int rotate_number(int num)
    {
        int result = 0;
        int pos = 1;
        while (num) {
            int digit = num % 10;
            int rdigit = rotate_digit(digit);
            if (rdigit == -1)
                return -1;
            result += rdigit * pos;
            pos *= 10;
            num /= 10;
        }

        return result;
    }

    int rotate_digit(int x)
    {
        switch (x) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 8:
            return 8;
        case 2:
            return 5;
        case 5:
            return 2;
        case 6:
            return 9;
        case 9:
            return 6;
        }

        return -1;
    }
};
