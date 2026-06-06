class Solution {
public:
    int search(vector<int>& A, int tar) {
        int st = 0, end = A.size() - 1;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (A[mid] == tar) {
                return true; 
            }

            // THE NEW ESCAPE HATCH
            // If we can't tell which side is sorted because of duplicates at the edges...
            if (A[st] == A[mid] && A[mid] == A[end]) {
                st++;
                end--;
                continue; // Skip the rest of the loop and recalculate mid
            }

            // Normal Left-Sorted Check
            if (A[st] <= A[mid]) { 
                if (A[st] <= tar && tar <= A[mid]) {
                    end = mid - 1;
                } else {
                    st = mid + 1;
                }
            } 
            // Normal Right-Sorted Check
            else { 
                if (A[mid] <= tar && tar <= A[end]) {
                    st = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }

        return false; 
    }
};