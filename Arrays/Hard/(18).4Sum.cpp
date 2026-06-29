// LeetCode 18. 4Sum

/*
=======================================================
Approach 1: Brute Force

Method:
- Use four nested loops to generate every possible quadruplet.
- If the sum of the four elements equals the target,
  sort the quadruplet and insert it into a set to avoid duplicates.
- Convert the set into a vector and return it.

Time Complexity: O(n^4 * log m)
- O(n^4) for checking all quadruplets.
- O(log m) for inserting into the set.

Space Complexity: O(m)
- m is the number of unique quadruplets stored in the set.
=======================================================
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> st;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    for (int l = k + 1; l < n; l++) {

                        long long sum =
                            (long long)nums[i] + nums[j] + nums[k] + nums[l];

                        if (sum == target) {

                            vector<int> temp = {
                                nums[i], nums[j], nums[k], nums[l]
                            };

                            sort(temp.begin(), temp.end());
                            st.insert(temp);
                        }
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
- Fix the first two elements using two loops.
- Use a hash set to store previously seen elements while
  traversing the remaining array.
- Compute the fourth element required to reach the target.
- If the fourth element is present in the hash set,
  a valid quadruplet is found.
- Sort the quadruplet before inserting it into a set
  to remove duplicates.

Time Complexity: O(n^3 * log m)
- O(n^3) for iterating over triplets.
- O(log m) for inserting into the set.

Space Complexity: O(n + m)
- O(n) for the hash set.
- O(m) for storing unique quadruplets.
=======================================================
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> st;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                unordered_set<long long> hashSet;

                for (int k = j + 1; k < n; k++) {

                    long long fourth =
                        (long long)target - nums[i] - nums[j] - nums[k];

                    if (hashSet.find(fourth) != hashSet.end()) {

                        vector<int> temp = {
                            nums[i], nums[j], nums[k], (int)fourth
                        };

                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }

                    hashSet.insert(nums[k]);
                }
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
- Fix the first two elements using two loops.
- Use two pointers (left and right) to find the
  remaining two elements whose sum equals the target.
- If the sum is smaller than the target, move the
  left pointer forward.
- If the sum is greater than the target, move the
  right pointer backward.
- If the sum equals the target, store the quadruplet
  and move both pointers, skipping duplicate values.
- Also skip duplicate values for the first and second
  fixed elements.

Time Complexity: O(n^3)
- Sorting takes O(n log n).
- The two-pointer search runs in O(n) for each pair.

Space Complexity: O(1)
- Excluding the space required for the output.
=======================================================
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {

            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < n; j++) {

                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int left = j + 1;
                int right = n - 1;

                while (left < right) {

                    long long sum =
                        (long long)nums[i] + nums[j] +
                        nums[left] + nums[right];

                    if (sum < target) {
                        left++;
                    }
                    else if (sum > target) {
                        right--;
                    }
                    else {

                        ans.push_back({
                            nums[i], nums[j],
                            nums[left], nums[right]
                        });

                        left++;
                        right--;

                        while (left < right &&
                               nums[left] == nums[left - 1])
                            left++;

                        while (left < right &&
                               nums[right] == nums[right + 1])
                            right--;
                    }
                }
            }
        }

        return ans;
    }
};