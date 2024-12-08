class Solution
{
public:
    bool canDistribute(const vector<int>& nums, int maxOperations, int maxBalls)        
    {
        int operations = 0;

        // Step 4: Traverse sorted array in reverse (largest to smallest)
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (nums[i] <= maxBalls) 
            {
                break;
            }
                

            // Calculate required splits for larger bags
            operations += (nums[i] - 1) / maxBalls;

            if (operations > maxOperations) 
            {
                return false;
            }
        }

        return true;
    }
    int minimumSize(vector<int>& nums, int maxOperations)
    {
        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        // Step 2: Define binary search range
        int low = 1; // Minimum possible maxBalls
        int high = nums.back(); // Maximum number of balls in the largest bag
        int result = high;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            // Step 3: Feasibility check
            if (canDistribute(nums, maxOperations, mid))
            {
                result = mid; // Update result with feasible maxBalls
                high = mid - 1; // Try smaller maximum
            }
            else
            {
                low = mid + 1; // Try larger maximum
            }
        }

        return result;
    }
};