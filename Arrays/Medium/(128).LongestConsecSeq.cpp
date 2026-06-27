// LeetCode 128. Longest Consecutive Sequence

/*
=======================================================
Approach 1: Brute Force

Method:
- For every element, repeatedly search for the next
  consecutive element (current + 1) in the array using
  linear search.
- Count the length of the consecutive sequence starting
  from each element and keep track of the maximum length.

Time Complexity: O(n³)
Space Complexity: O(1)
=======================================================
*/

class Solution {
public:
    bool linearSearch(vector<int>& nums, int target) {
        for (int x : nums) {
            if (x == target)
                return true;
        }
        return false;
    }

    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int longest = 0;

        for (int i = 0; i < n; i++) {
            int x = nums[i];
            int cnt = 1;

            while (linearSearch(nums, x + 1)) {
                x++;
                cnt++;
            }

            longest = max(longest, cnt);
        }

        return longest;
    }
};


/*
=======================================================
Approach 2: Better (Sorting)

Method:
- Sort the array to bring consecutive elements together.
- Traverse the sorted array while counting consecutive
  elements and skipping duplicates.
- Keep track of the longest consecutive sequence.

Time Complexity: O(n log n)
Space Complexity: O(1)
=======================================================
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;

        sort(nums.begin(), nums.end());

        int longest = 1;
        int cnt = 1;

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                continue;
            }
            else if (nums[i] == nums[i - 1] + 1) {
                cnt++;
            }
            else {
                cnt = 1;
            }

            longest = max(longest, cnt);
        }

        return longest;
    }
};


/*
=======================================================
Approach 3: Optimal (Hash Set)

Method:
- Insert all elements into a hash set for O(1) lookup.
- Only start counting from elements that do not have a
  predecessor (x - 1).
- Extend the sequence by checking for consecutive
  elements and update the maximum length.

Time Complexity: O(n)
Space Complexity: O(n)
=======================================================
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        if (n == 0)
            return 0;

        unordered_set<int> st;

        for (int i = 0; i < n; i++) {
            st.insert(nums[i]);
        }

        int maxCount = 1;

        for (auto it : st) {
            if (st.find(it - 1) == st.end()) {
                int count = 1;
                int x = it;

                while (st.find(x + 1) != st.end()) {
                    count++;
                    x++;
                }

                maxCount = max(maxCount, count);
            }
        }

        return maxCount;
    }
};