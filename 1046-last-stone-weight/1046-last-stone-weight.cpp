class Solution {
public:
    int lastStoneWeight(std::vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        
        while (pq.size() > 1) {
            int y = pq.top(); pq.pop(); // Get the heaviest stone
            int x = pq.top(); pq.pop(); // Get the second heaviest stone
            
            if (x != y) {
                pq.push(y - x); // Push the remaining weight back
            }
        }
        
        // Return the remaining stone weight, or 0 if empty
        return pq.empty() ? 0 : pq.top();
    }
};