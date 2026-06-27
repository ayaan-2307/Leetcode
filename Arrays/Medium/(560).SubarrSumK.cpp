// LeetCode 560. Subarray Sum Equals K

/*
=======================================================
Approach 1: Brute Force

Method:
- Consider every possible subarray.
- Compute the sum of each subarray by traversing all its
  elements.
- If the sum equals k, increment the count.

Time Complexity: O(n³)
Space Complexity: O(1)
=======================================================
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {

                int sum = 0;

                for (int x = i; x <= j; x++) {
                    sum += nums[x];
                }

                if (sum == k)
                    count++;
            }
        }

        return count;
    }
};


/*
=======================================================
Approach 2: Better (Running Sum)

Method:
- Fix the starting index of the subarray.
- Extend the ending index one element at a time while
  maintaining a running sum.
- If the running sum equals k, increment the count.

Time Complexity: O(n²)
Space Complexity: O(1)
=======================================================
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {

            int sum = 0;

            for (int j = i; j < n; j++) {
                sum += nums[j];

                if (sum == k)
                    count++;
            }
        }

        return count;
    }
};


/*
=======================================================
Approach 3: Optimal (Prefix Sum + Hash Map)

Method:
- Maintain a running prefix sum.
- Store the frequency of every prefix sum in an
  unordered_map.
- If (prefixSum - k) has already occurred, then every
  occurrence represents a subarray ending at the current
  index whose sum is k.

Time Complexity: O(n)
Space Complexity: O(n)
=======================================================
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> mp;
        mp[0] = 1;  // Empty prefix

        int prefixSum = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {

            prefixSum += nums[i];

            if (mp.find(prefixSum - k) != mp.end()) {
                count += mp[prefixSum - k];
            }

            mp[prefixSum]++;
        }

        return count;
    }
};