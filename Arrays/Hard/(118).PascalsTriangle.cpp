// LeetCode 118. Pascal's Triangle

/*
-------------------------------------------------------
Approach: Row-by-Row Construction

Method:
- Create the Pascal Triangle one row at a time.
- For each row:
    - Allocate space for (i + 1) elements.
    - Set the first and last elements to 1.
    - Compute the middle elements using the two adjacent
      elements from the previous row.
- Repeat until all rows are generated.

Time Complexity:
- O(numRows²)
  Each element of the triangle is visited exactly once.

Space Complexity:
- O(numRows²)
  Required to store the resulting Pascal Triangle.
-------------------------------------------------------
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;

        for (int i = 0; i < numRows; i++) {
            v.push_back(vector<int>(i + 1));

            int col = 0;
            for (int j = 0; j < i + 1; j++) {
                if (j == 0 || j == i) {
                    v[i][j] = 1;
                } else {
                    v[i][j] = v[i - 1][col] + v[i - 1][col + 1];
                    col++;
                }
            }
        }

        return v;
    }
};

// LeetCode 118. Pascal's Triangle

/*
-------------------------------------------------------
Approach: Optimized Row Initialization

Method:
- Initialize each row with all elements as 1.
- The first and last elements are already correct.
- Compute only the middle elements using Pascal's rule:
      current = upper-left + upper
- Continue until all rows are generated.

Time Complexity:
- O(numRows²)
  Every element is processed once.

Space Complexity:
- O(numRows²)
  Required to store the resulting Pascal Triangle.
-------------------------------------------------------
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for (int i = 0; i < numRows; i++) {
            ans.push_back(vector<int>(i + 1, 1));

            for (int j = 1; j < i; j++) {
                ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
        }

        return ans;
    }
};