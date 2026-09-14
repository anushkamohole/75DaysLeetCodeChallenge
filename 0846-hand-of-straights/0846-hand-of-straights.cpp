class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) {
            return false;
        }

        map<int, int> cardCount;
        for (int card : hand) {
            cardCount[card]++;
        }

        for (auto it = cardCount.begin(); it != cardCount.end(); ++it) {
            int startCard = it->first;
            int count = it->second;

            
            if (count > 0) {
                for (int i = 0; i < groupSize; ++i) {
                    if (cardCount[startCard + i] < count) {
                        return false;
                    }
                    cardCount[startCard + i] -= count;
                }
            }
        }

        return true;
    }
};