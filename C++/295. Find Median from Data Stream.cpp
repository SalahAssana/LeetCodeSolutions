class MedianFinder
{
    // max heap
    priority_queue<int> low;
    // min heap
    priority_queue<int, vector<int>, greater<int>> high;
    
public:    
    void addNum(int num)
    {
        // Add to max heap
        low.push(num);
        
        // Balance heaps so mid stays at the top
        high.push(low.top());
        low.pop();
        
        // The max heap will at most have 1 more value then min heap
        if (low.size() < high.size())
        {
            low.push(high.top());
            high.pop();
        }
    }
    
    double findMedian()
    {
        return low.size() > high.size() ? low.top() : ((double) ((low.top() + high.top())*0.5));
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */