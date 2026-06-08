class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int st = 0, end = arr.size() - 1;

        while (st <= end) {
            int mid = st + (end - st) / 2;
            
            // Calculate how many numbers are missing before index 'mid'
            int missing = arr[mid] - (mid + 1);

            if (missing < k) {
                st = mid + 1; // We need more missing numbers, go right
            } else {
                end = mid - 1; // We have too many missing numbers (or exactly k), go left
            }
        }

        // EDGE CASE: What if the kth missing number is BEFORE the very first array element?
        // Example: arr = [5, 6, 7] and k = 2. 
        // The binary search will keep going left until 'end' drops out of bounds to -1.
        // Therefore, the kth missing positive integer is simply 'k' itself.
        if (end < 0) {
            return k;
        }

        // Step 1: Find out exactly how many numbers are missing before our 'anchor' (arr[end])
        int missing_before_end = arr[end] - (end + 1);

        // Step 2: Calculate how many more missing numbers we need to count to reach 'k'
        int more_needed = k - missing_before_end;

        // Step 3: Add the remaining steps to our anchor number to find the final answer
        return arr[end] + more_needed;
    }
};
/*int findKthPositive(vector<int>& arr, int k) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] <= k) {
                k++; // A slot was taken, push our target up by 1
            } else {
                break; // The array numbers are now bigger than our target. We are done!
            }
        }
        return k;
    }
    */