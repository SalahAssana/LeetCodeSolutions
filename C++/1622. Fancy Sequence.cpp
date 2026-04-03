class Fancy {
public:
    Fancy()
    {
    }

    void append(int val)
    {
        stuff.push_back(val);
    }

    void addAll(int inc)
    {
        for (auto& val : stuff) {
            val = val + inc;
        }
    }

    void multAll(int m)
    {
        for (auto& val : stuff) {
            val = (val * m) % mod;
        }
    }

    int getIndex(int idx)
    {
        if (idx >= stuff.size())
            return -1;
        else
            return stuff[idx] % mod;
    }

    const uint64_t mod = 1000000000 + 7;

    vector<uint64_t> stuff;
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */
