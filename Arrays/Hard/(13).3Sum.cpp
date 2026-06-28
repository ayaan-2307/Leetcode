// LeetCode 15. 3Sum

/*
=======================================================
Approach 1: Brute Force

Method:
- Use three nested loops to generate every possible triplet.
- If the sum of the three elements is 0,
  sort the triplet and insert it into a set to avoid duplicates.
- Convert the set into a vector and return it.

Time Complexity: O(n^3 * log m)
- O(n^3) for checking all triplets.
- O(log m) for inserting into the set.

Space Complexity: O(m)
- m is the number of unique triplets stored in the set.
=======================================================
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        set<vector<int>> st;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {

                    if (nums[i] + nums[j] + nums[k] == 0) {

                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        sort(temp.begin(), temp.end());

                        st.insert(temp);
                    }
                }
            }
        }

        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};


/*
=======================================================
Approach 2: Better (Hashing)

Method:
- Fix the first element using a loop.
- For every fixed element, use a hash set to find the
  third element needed to make the sum zero.
- If the third element is already present in the hash set,
  a valid triplet is found.
- Sort the triplet before inserting it into a set to
  remove duplicates.

Time Complexity: O(n^2 * log m)
- O(n^2) for iterating over pairs.
- O(log m) for inserting into the set.

Space Complexity: O(n + m)
- O(n) for the hash set.
- O(m) for storing unique triplets.
=======================================================
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        set<vector<int>> st;

        for (int i = 0; i < n; i++) {

            unordered_set<int> hashSet;

            for (int j = i + 1; j < n; j++) {

                int third = -(nums[i] + nums[j]);

                if (hashSet.find(third) != hashSet.end()) {

                    vector<int> temp = {nums[i], nums[j], third};
                    sort(temp.begin(), temp.end());

                    st.insert(temp);
                }

                hashSet.insert(nums[j]);
            }
        }

        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};


/*
=======================================================
Approach 3: Optimal (Sorting + Two Pointers)

Method:
- Sort the array.
- Fix the first element using a loop.
- Use two pointers (left and right) to find the remaining
  two elements whose sum equals the negative of the fixed element.
- If the sum is smaller than 0, move the left pointer forward.
- If the sum is greater than 0, move the right pointer backward.
- If the sum is 0, store the triplet and move both pointers,
  skipping duplicate values to avoid repeated triplets.
- Also skip duplicate values for the fixed element.

Time Complexity: O(n^2)
- Sorting takes O(n log n).
- The two-pointer search runs in O(n) for each element.

Space Complexity: O(1)
- Excluding the space required for the output.
=======================================================
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {

            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1;
            int right = n - 1;

            while (left < right) {

                int sum = nums[i] + nums[left] + nums[right];

                if (sum < 0) {
                    left++;
                }
                else if (sum > 0) {
                    right--;
                }
                else {

                    ans.push_back({nums[i], nums[left], nums[right]});

                    left++;
                    right--;

                    while (left < right && nums[left] == nums[left - 1])
                        left++;

                    while (left < right && nums[right] == nums[right + 1])
                        right--;
                }
            }
        }

        return ans;
    }
};