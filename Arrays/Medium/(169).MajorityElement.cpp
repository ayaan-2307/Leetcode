// LeetCode 169. Majority Element

/*
-------------------------------------------------------
Approach: Brute Force

Method:
- For every element, count its frequency by traversing
  the entire array.
- If the frequency exceeds n/2, return that element.

Time Complexity: O(n²)
Space Complexity: O(1)
-------------------------------------------------------
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int cnt = 0;

            for (int j = 0; j < n; j++) {
                if (nums[j] == nums[i])
                    cnt++;
            }

            if (cnt > n / 2)
                return nums[i];
        }

        return -1;
    }
};