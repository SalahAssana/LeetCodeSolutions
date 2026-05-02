class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums)
    {
        string result;
        unordered_set<uint32_t> vals;

        for (auto num : nums) {
            vals.insert(convert_to_base_10(num));
        }

        for (auto num : vals) {
            cout << num << ",";
        }

        cout << "\n";

        int n = nums[0].size();
        int right = convert_to_base_10(string(n, '1'));

        uint32_t num = 0;
        for (uint32_t i = 0; i <= right; ++i) {
            if (vals.find(i) == vals.end()) {
                num = i;
                cout << "found: " << i << "\n";
                break;
            }
        }

        result = convert_to_string(num, n);

        return result;
    }

    string convert_to_string(uint32_t num, int n)
    {
        string result(n, '0');
        int r = n;

        n--;
        while (n >= 0) {
            result[r - n - 1] = '0' + ((num >> n) & 1);
            n--;
        }

        return result;
    }

    uint32_t convert_to_base_10(const string& binary)
    {
        uint32_t result = 0;
        for (auto digit : binary) {
            result = (result << 1) | (digit == '1');
        }
        return result;
    }
};
