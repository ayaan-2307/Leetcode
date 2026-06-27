// LeetCode 229. Majority Element II

/*
-------------------------------------------------------
Approach: Brute Force

Method:
- For every element in the array, count its frequency
  by traversing the entire array.
- If its frequency is greater than n/3 and it has not
  already been added to the answer, add it.
- Since there can be at most two majority elements,
  stop once two elements are found.

Time Complexity:
- O(n²)
  For each element, we may traverse the entire array.

Space Complexity:
- O(1)
  Ignoring the output vector.
-------------------------------------------------------
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();

        for (int i = 0; i < n; i++) {

            if (!ans.empty() && ans[0] == nums[i])
                continue;

            if (ans.size() == 2 && ans[1] == nums[i])
                continue;

            int count = 0;

            for (int j = 0; j < n; j++) {
                if (nums[j] == nums[i])
                    count++;
            }

            if (count > n / 3)
                ans.push_back(nums[i]);

            if (ans.size() == 2)
                break;
        }

        return ans;
    }
};

// LeetCode 229. Majority Element II

/*
-------------------------------------------------------
Approach: Better (Hash Map)

Method:
- Traverse the array and store the frequency of each
  element using a hash map.
- Traverse the hash map and collect all elements whose
  frequency is greater than n/3.
- Return the collected elements.

Time Complexity:
- O(n)
  One traversal to build the frequency map and another
  traversal over the distinct elements.

Space Complexity:
- O(n)
  Hash map stores the frequency of each distinct element.
-------------------------------------------------------
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;
        vector<int> ans;
        int n = nums.size();

        for (int x : nums)
            freq[x]++;

        for (const auto &it : freq) {
            if (it.second > n / 3)
                ans.push_back(it.first);
        }

        return ans;
    }
};

// LeetCode 229. Majority Element II

/*
-------------------------------------------------------
Approach: Optimal (Boyer-Moore Voting Algorithm)

Method:
- Since an element must appear more than n/3 times,
  there can be at most two majority elements.
- Maintain two candidates and their respective counts.
- Traverse the array:
    - If the current element matches a candidate,
      increment its count.
    - Else if a candidate's count becomes zero,
      replace it with the current element.
    - Otherwise, decrement both counts.
- Perform a second traversal to verify the frequencies
  of the two candidates.
- Return the candidates whose frequency exceeds n/3.

Time Complexity:
- O(n)
  Two linear traversals of the array.

Space Complexity:
- O(1)
  Only a constant number of variables are used.
-------------------------------------------------------
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int e1 = INT_MIN, e2 = INT_MIN;
        int c1 = 0, c2 = 0;

        for (int num : nums) {
            if (c1 == 0 && num != e2) {
                e1 = num;
                c1 = 1;
            }
            else if (c2 == 0 && num != e1) {
                e2 = num;
                c2 = 1;
            }
            else if (num == e1) {
                c1++;
            }
            else if (num == e2) {
                c2++;
            }
            else {
                c1--;
                c2--;
            }
        }

        c1 = c2 = 0;

        for (int num : nums) {
            if (num == e1)
                c1++;
            else if (num == e2)
                c2++;
        }

        vector<int> ans;

        if (c1 > n / 3)
            ans.push_back(e1);

        if (c2 > n / 3)
            ans.push_back(e2);

        return ans;
    }
};