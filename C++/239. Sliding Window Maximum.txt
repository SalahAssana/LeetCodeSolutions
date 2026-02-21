class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        deque<int> q;
        vector<int> ans;
        
        for(int i = 0 ; i < nums.size(); i++)
        {
            while(!q.empty() and i-q.front()>=k) q.pop_front(); //delete the elements out of this window.
            while(!q.empty() and nums[q.back()] < nums[i]) q.pop_back(); //always bring max element to front.
            q.push_back(i); //now push the element (in index form) in the queue.
            if(i >= k-1) ans.push_back(nums[q.front()]); //store the result of this window.
        }
        
        return ans; //return the results
    }
};