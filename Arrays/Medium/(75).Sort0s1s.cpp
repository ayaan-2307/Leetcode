// LeetCode 75. Sort Colors

/*
=======================================================
Approach 1: Brute Force (Sorting)

Method:
- Sort the array using the built-in sorting algorithm.
- Since the array contains only 0s, 1s, and 2s,
  sorting automatically arranges them in order.

Time Complexity: O(n log n)
Space Complexity: O(1)
=======================================================
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    }
};


/*
=======================================================
Approach 2: Better (Counting)

Method:
- Count the number of 0s, 1s, and 2s in one traversal.
- Overwrite the array by placing all 0s first,
  followed by 1s, and then 2s.

Time Complexity: O(n)
Space Complexity: O(1)
=======================================================
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;

        for (int x : nums) {
            if (x == 0)
                cnt0++;
            else if (x == 1)
                cnt1++;
            else
                cnt2++;
        }

        int i = 0;

        while (cnt0--)
            nums[i++] = 0;

        while (cnt1--)
            nums[i++] = 1;

        while (cnt2--)
            nums[i++] = 2;
    }
};


/*
=======================================================
Approach 3: Optimal (Dutch National Flag Algorithm)

Method:
- Maintain three pointers: low, mid, and high.
- Elements before 'low' are 0s, elements after 'high' are 2s,
  and elements between 'low' and 'mid' are 1s.
- Traverse the array once, swapping elements into their
  correct positions based on their value.

Time Complexity: O(n)
Space Complexity: O(1)
=======================================================
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1) {
                mid++;
            }
            else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};