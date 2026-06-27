// LeetCode 2149. Rearrange Array Elements by Sign

/*
=======================================================
Approach 1: Brute Force

Method:
- Store all positive elements in one array and all
  negative elements in another array.
- Traverse both arrays simultaneously and place one
  positive followed by one negative element into the
  original array.

Time Complexity: O(n)
Space Complexity: O(n)
=======================================================
*/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos, neg;

        for (int x : nums) {
            if (x > 0)
                pos.push_back(x);
            else
                neg.push_back(x);
        }

        vector<int> ans;
        int i = 0, j = 0;

        while (i < pos.size() && j < neg.size()) {
            ans.push_back(pos[i++]);
            ans.push_back(neg[j++]);
        }

        return ans;
    }
};


/*
=======================================================
Approach 2: Optimal

Method:
- Create the answer array of the same size.
- Maintain two indices: one for positive (even indices)
  and one for negative (odd indices).
- Place each element directly into its correct position
  in a single traversal.

Time Complexity: O(n)
Space Complexity: O(n)
=======================================================
*/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int pos = 0, neg = 1;
        vector<int> ans(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                ans[pos] = nums[i];
                pos += 2;
            }
            else {
                ans[neg] = nums[i];
                neg += 2;
            }
        }

        return ans;
    }
};