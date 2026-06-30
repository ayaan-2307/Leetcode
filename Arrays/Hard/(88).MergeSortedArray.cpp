// LeetCode 88. Merge Sorted Array

/*
=======================================================
Approach 1: Brute Force (Extra Array)

Method:
- Use two pointers to traverse both sorted arrays.
- Compare the current elements and insert the smaller one
  into a temporary array.
- After one array is exhausted, copy the remaining elements
  from the other array.
- Copy the merged array back into nums1.

Time Complexity: O(m + n)
- Each element is processed exactly once.

Space Complexity: O(m + n)
- Extra array is used to store the merged result.
=======================================================
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        vector<int> temp;

        int i = 0, j = 0;

        while (i < m && j < n) {

            if (nums1[i] <= nums2[j]) {
                temp.push_back(nums1[i++]);
            }
            else {
                temp.push_back(nums2[j++]);
            }
        }

        while (i < m) {
            temp.push_back(nums1[i++]);
        }

        while (j < n) {
            temp.push_back(nums2[j++]);
        }

        for (int i = 0; i < m + n; i++) {
            nums1[i] = temp[i];
        }
    }
};


/*
=======================================================
Approach 2: Better (Sort After Copying)

Method:
- Copy all elements of nums2 into the empty positions
  at the end of nums1.
- Sort the entire nums1 array.

Time Complexity: O((m + n) log(m + n))
- Sorting dominates the complexity.

Space Complexity: O(1)
- Ignoring the space used by the sorting algorithm.
=======================================================
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        for (int i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];
        }

        sort(nums1.begin(), nums1.end());
    }
};


/*
=======================================================
Approach 3: Optimal (Three Pointers)

Method:
- Start from the end of both arrays.
- Compare the largest remaining elements.
- Place the larger element at the end of nums1.
- Continue until one array is exhausted.
- If elements remain in nums2, copy them into nums1.

Time Complexity: O(m + n)
- Each element is processed exactly once.

Space Complexity: O(1)
- No extra space is used.
=======================================================
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (i >= 0 && j >= 0) {

            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            }
            else {
                nums1[k--] = nums2[j--];
            }
        }

        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};