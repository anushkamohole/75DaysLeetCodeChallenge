class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int cols = matrix[0].size();
        vector<int> heights(cols, 0);
        int maxArea = 0;
        
        // Process the matrix row by row
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < cols; j++) {
                // If it's a '1', increase the height. If '0', reset to 0.
                if (matrix[i][j] == '1') {
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }
            // Calculate the max area for the histogram at the current row
            maxArea = max(maxArea, largestRectangleArea(heights));
        }
        
        return maxArea;
    }
    
    // Helper function using a Monotonic Stack
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st; // Stores indices, maintaining an increasing order of heights
        int max_area = 0;
        int n = heights.size();
        
        for (int i = 0; i <= n; i++) {
            // We use a dummy height of 0 at the very end (i == n) to force the stack to empty out
            int currentHeight = (i == n) ? 0 : heights[i];
            
            // If we find a smaller height, it acts as a right boundary for the bars in the stack
            while (!st.empty() && currentHeight < heights[st.top()]) {
                int height = heights[st.top()]; // The height of the bar we are evaluating
                st.pop();
                
                // Calculate the width. 
                // Right boundary is the current index 'i'.
                // Left boundary is the new top of the stack.
                int width;
                if (st.empty()) {
                    width = i; // If stack is empty, it means this height extends all the way to index 0
                } else {
                    width = i - st.top() - 1; 
                }
                
                max_area = max(max_area, height * width);
            }
            
            st.push(i); // Push the current index onto the stack
        }
        
        return max_area;
    }
};