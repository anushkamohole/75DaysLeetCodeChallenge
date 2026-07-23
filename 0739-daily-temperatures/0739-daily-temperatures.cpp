class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        int hottest = 0;
        
        // Iterate backward from the last day
        for (int i = n - 1; i >= 0; i--) {
            int currentTemp = temperatures[i];
            
            // If this is the hottest day we've seen from the right, 
            // it's impossible to find a warmer day in the future.
            if (currentTemp >= hottest) {
                hottest = currentTemp;
                continue; // ans[i] remains 0
            }
            
            // Start looking at the very next day
            int daysToWait = 1;
            
            // JUMP LOOP:
            // While the future day we are looking at is cooler or equal to today
            while (temperatures[i + daysToWait] <= currentTemp) {
                // Instead of moving 1 day at a time, we jump by the number of days 
                // the future day had to wait to find a warmer temperature.
                daysToWait += ans[i + daysToWait];
            }
            
            // We broke out of the while loop, meaning we found a warmer day!
            ans[i] = daysToWait;
        }
        
        return ans;
    }
};
/*
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        
        // Outer loop: pick a day
        for (int i = 0; i < n; i++) {
            // Inner loop: look at all future days
            for (int j = i + 1; j < n; j++) {
                if (temperatures[j] > temperatures[i]) {
                    ans[i] = j - i; // Found a warmer day, calculate distance
                    break;          // Stop looking for this day
                }
            }
        }
        
        return ans;
    }
};
*/