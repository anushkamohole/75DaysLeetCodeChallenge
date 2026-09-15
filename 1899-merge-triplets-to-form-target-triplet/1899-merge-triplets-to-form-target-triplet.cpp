class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool foundFirst = false;
        bool foundSecond = false;
        bool foundThird = false;

        for (const auto& triplet : triplets) {
            
            // Skip invalid triplets
            if (triplet[0] > target[0] || triplet[1] > target[1] || triplet[2] > target[2]) {
                continue;
            }

            if (triplet[0] == target[0]) foundFirst = true;
            if (triplet[1] == target[1]) foundSecond = true;
            if (triplet[2] == target[2]) foundThird = true;

            if (foundFirst && foundSecond && foundThird) {
                return true; 
            }
        }

        return foundFirst && foundSecond && foundThird;
    }
};