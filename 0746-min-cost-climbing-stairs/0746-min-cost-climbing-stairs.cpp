class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int secondStepAhead = cost[n - 1]; 
        int firstStepAhead = cost[n - 2];

        for (int i = n - 3; i >= 0; --i) {
            int currentCost = cost[i] + min(firstStepAhead, secondStepAhead);

            secondStepAhead = firstStepAhead;
            firstStepAhead = currentCost;
        }
        return min(firstStepAhead, secondStepAhead);
    }
};