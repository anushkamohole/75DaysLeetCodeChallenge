class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> baskets; 
        int left = 0;
        int maxFruits = 0;

        for (int right = 0; right < fruits.size(); right++) {
            // 1. Expand the window: Add the current fruit to our baskets
            baskets[fruits[right]]++;

            // 2. Shrink the window: If we have more than 2 types of fruit
            while (baskets.size() > 2) {
                // Remove one piece of the left-most fruit
                baskets[fruits[left]]--;
                
                // If we completely run out of that fruit type, remove it from the basket map
                if (baskets[fruits[left]] == 0) {
                    baskets.erase(fruits[left]);
                }
                
                // Shrink the window from the left
                left++;
            }

            // 3. Record the maximum valid window size we've seen so far
            maxFruits = max(maxFruits, right - left + 1);
        }

        return maxFruits;
    }
};