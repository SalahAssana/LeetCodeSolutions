class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids)
    {
        size_t n = asteroids.size();
        sort(asteroids.begin(), asteroids.end());
        size_t mid = 0, right = n;
        for (; mid < n && (mass >= asteroids[mid]); ++mid)
            ;
        uint64_t total_mass = accumulate(asteroids.begin(), asteroids.begin() + mid, (uint64_t)mass);
        right = mid;
        while (right < n && total_mass >= asteroids[right])
            total_mass += asteroids[right++];
        return right == n;
    }
};
