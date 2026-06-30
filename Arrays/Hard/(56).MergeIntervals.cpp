// LeetCode 56. Merge Intervals

/*
=======================================================
Approach 1: Brute Force

Method:
- Sort the intervals based on their starting time.
- Traverse each interval and treat it as the start of
  a merged interval.
- Extend the current interval by checking all following
  overlapping intervals.
- Store the merged interval in the answer.

Time Complexity: O(n^2)
- O(n log n) for sorting.
- O(n^2) for checking overlapping intervals.

Space Complexity: O(n)
- Space required for storing the merged intervals.
=======================================================
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {

            int start = intervals[i][0];
            int end = intervals[i][1];

            if (!ans.empty() && end <= ans.back()[1])
                continue;

            for (int j = i + 1; j < n; j++) {

                if (intervals[j][0] <= end) {
                    end = max(end, intervals[j][1]);
                }
                else {
                    break;
                }
            }

            ans.push_back({start, end});
        }

        return ans;
    }
};


/*
=======================================================
Approach 2: Optimal (Sorting + Single Traversal)

Method:
- Sort the intervals based on their starting time.
- Traverse the sorted intervals.
- If the current interval does not overlap with the last
  merged interval, add it to the answer.
- Otherwise, merge it by updating the ending time of the
  last merged interval.

Time Complexity: O(n log n)
- Sorting takes O(n log n).
- Single traversal takes O(n).

Space Complexity: O(n)
- Space required for storing the merged intervals.
=======================================================
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        for (auto interval : intervals) {

            if (ans.empty() || interval[0] > ans.back()[1]) {
                ans.push_back(interval);
            }
            else {
                ans.back()[1] = max(ans.back()[1], interval[1]);
            }
        }

        return ans;
    }
};