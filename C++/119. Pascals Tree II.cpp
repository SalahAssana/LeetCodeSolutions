class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row = {1};

        for (int i = 0; i < rowIndex; ++i) {
            vector<int> new_row(row.size() + 1, 1);

            for (int j = 1; j < new_row.size()-1; ++j) {
                new_row[j] = row[j] + row[j-1];
            }

            row = move(new_row);
        }

        return row;
    }
};
