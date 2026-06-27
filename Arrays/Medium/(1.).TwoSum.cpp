// LeetCode 1. Two Sum

/*
-------------------------------------------------------
Approach: Optimal (Hash Map)

Method:
- Traverse the array once while storing each element and
  its index in a hash map.
- For each element, calculate its complement
  (target - current element).
- If the complement is already present in the hash map,
  return the stored index and the current index.
- Otherwise, insert the current element and its index into
  the hash map.

Time Complexity: O(n) average case
Space Complexity: O(n)
-------------------------------------------------------
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mpp;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            if (mpp.find(complement) != mpp.end()) {
                return {mpp[complement], i};
            }

            mpp[nums[i]] = i;
        }

        return {-1, -1};
    }
};




// LeetCode 1. Two Sum

/*
-------------------------------------------------------
Approach: Brute Force

Method:
- Check every possible pair of elements in the array.
- If the sum of a pair equals the target, return their
  indices.
- Since every pair is examined, this guarantees finding
  the correct answer if it exists.

Time Complexity: O(n²)
Space Complexity: O(1)
-------------------------------------------------------
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }

        return {-1, -1};
    }
};