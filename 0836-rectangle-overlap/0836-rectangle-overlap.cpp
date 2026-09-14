class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // Check if there is a valid intersection on the X-axis
        bool xOverlap = max(rec1[0], rec2[0]) < min(rec1[2], rec2[2]);
        
        // Check if there is a valid intersection on the Y-axis
        bool yOverlap = max(rec1[1], rec2[1]) < min(rec1[3], rec2[3]);
        
        // Overlap only happens if they intersect on BOTH axes
        return xOverlap && yOverlap;
    }
};