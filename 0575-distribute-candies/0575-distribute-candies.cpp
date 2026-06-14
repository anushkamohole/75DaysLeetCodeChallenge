class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        // The doctor's limit
        int limit = candyType.size() / 2;
        
        // Populate a set with the candy types to find the unique count
        unordered_set<int> unique_candies(candyType.begin(), candyType.end());
        
        // Return the smaller of the two values
        return min((int)unique_candies.size(), limit);
    }
};