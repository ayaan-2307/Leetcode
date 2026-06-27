// LeetCode 169. Majority Element

/*
=======================================================
Approach 1: Brute Force

Method:
- For every element, count its frequency by traversing
  the entire array.
- If the frequency exceeds n/2, return that element.

Time Complexity: O(n²)
Space Complexity: O(1)
=======================================================
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


/*
=======================================================
Approach 2: Better (Hash Map)

Method:
- Store the frequency of each element in a hash map.
- As soon as an element's frequency becomes greater than
  n/2, return it.

Time Complexity: O(n)
Space Complexity: O(n)
=======================================================
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;
        int n = nums.size();

        for (int x : nums) {
            freq[x]++;

            if (freq[x] > n / 2)
                return x;
        }

        return -1;
    }
};


/*
=======================================================
Approach 3: Optimal (Moore's Voting Algorithm)

Method:
- Maintain a candidate and its count.
- If the count becomes zero, choose the current element
  as the new candidate.
- Increment the count if the current element matches the
  candidate; otherwise, decrement it.
- Verify that the candidate appears more than n/2 times
  before returning it.

Time Complexity: O(n)
Space Complexity: O(1)
=======================================================
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate;

        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) {
                count = 1;
                candidate = nums[i];
            }
            else if (candidate == nums[i]) {
                count++;
            }
            else {
                count--;
            }
        }

        int freq = 0;

        for (int x : nums) {
            if (x == candidate)
                freq++;
        }

        if (freq > nums.size() / 2)
            return candidate;

        return -1;
    }
};