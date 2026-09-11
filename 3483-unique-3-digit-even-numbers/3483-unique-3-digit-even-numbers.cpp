class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);
        for (int d : digits) {
            freq[d]++;
        }

        int count = 0;
        for (int num = 100; num <= 998; num += 2) {
            int d1 = num / 100;         // hundreds
            int d2 = (num / 10) % 10;   // tens
            int d3 = num % 10;          // units

            vector<int> required(10, 0);
            required[d1]++;
            required[d2]++;
            required[d3]++;

            if (required[d1] <= freq[d1] &&
                required[d2] <= freq[d2] &&
                required[d3] <= freq[d3]) {
                count++;
            }
        }

        return count;
    }
};