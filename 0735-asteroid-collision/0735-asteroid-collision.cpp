class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st; // Using a vector as a stack so we can return it directly
        
        for (int ast : asteroids) {
            bool destroyed = false;
            
            // While a collision is happening (+ top of stack, - current asteroid)
            while (!st.empty() && st.back() > 0 && ast < 0) {
                if (st.back() < -ast) {
                    st.pop_back(); // The right-moving asteroid in stack explodes
                    continue;      // Keep checking the next asteroid in the stack
                } else if (st.back() == -ast) {
                    st.pop_back(); // Both explode
                }
                
                // If we reach here, the current asteroid was either equal or smaller,
                // meaning it is destroyed and shouldn't be added to the stack.
                destroyed = true;
                break; 
            }
            
            // If the current asteroid survived all collisions, add it to the final state
            if (!destroyed) {
                st.push_back(ast);
            }
        }
        
        return st;
    }
};