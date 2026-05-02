class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary)
    {
        vector<string> result;

        for (auto& query : queries) {
            for (auto& word : dictionary) {
                int n = query.size();
                int dist = 0;

                for (int i = 0; i < n; ++i) {
                    dist += query[i] != word[i];
                }

                if (dist <= 2) {
                    result.push_back(query);
                    break;
                }
            }
        }

        return result;
    }
};
