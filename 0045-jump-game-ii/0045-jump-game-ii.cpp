#include <vector>
#include <algorithm>

class Solution {
public:
    int jump(std::vector<int>& nums) {
        int jumps = 0;
        int current_end = 0;
        int farthest = 0;
        
        // We don't need to process the last element because once we reach 
        // or can pass it, we are done.
        for (int i = 0; i < nums.size() - 1; ++i) {
            // Update the maximum reachable index from the current position
            farthest = std::max(farthest, i + nums[i]);
            
            // If we have reached the end of the current jump coverage
            if (i == current_end) {
                jumps++;             // Commit to a jump
                current_end = farthest; // Update our boundary to the furthest reachable point
                
                // Optimization: If we can already reach the last index, break early
                if (current_end >= nums.size() - 1) {
                    break;
                }
            }
        }
        
        return jumps;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna