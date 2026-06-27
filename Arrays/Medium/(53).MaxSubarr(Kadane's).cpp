// LeetCode 53. Maximum Subarray

/*
=======================================================
Approach 1: Brute Force

Method:
- Consider every possible subarray.
- Compute the sum of each subarray.
- Keep track of the maximum subarray sum found.

Time Complexity: O(n³)
Space Complexity: O(1)
=======================================================
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int sum = 0;

                for (int k = i; k <= j; k++) {
                    sum += nums[k];
                }

                maxSum = max(maxSum, sum);
            }
        }

        return maxSum;
    }
};


/*
=======================================================
Approach 2: Better

Method:
- Fix the starting index of the subarray.
- Extend the ending index one element at a time while
  maintaining the running sum.
- Update the maximum subarray sum after every extension.

Time Complexity: O(n²)
Space Complexity: O(1)
=======================================================
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN;

        for (int i = 0; i < n; i++) {
            int sum = 0;

            for (int j = i; j < n; j++) {
                sum += nums[j];
                maxSum = max(maxSum, sum);
            }
        }

        return maxSum;
    }
};


/*
=======================================================
Approach 3: Optimal (Kadane's Algorithm)

Method:
- Traverse the array while maintaining a running sum.
- Update the maximum sum whenever the current sum becomes
  larger.
- If the running sum becomes negative, reset it to zero,
  as it cannot contribute to a maximum subarray.

Time Complexity: O(n)
Space Complexity: O(1)
=======================================================
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long maxSum = INT_MIN;
        long long sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            if (sum > maxSum)
                maxSum = sum;

            if (sum < 0)
                sum = 0;
        }

        return maxSum;
    }
};