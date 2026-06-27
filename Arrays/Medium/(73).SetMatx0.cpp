// LeetCode 73. Set Matrix Zeroes

/*
=======================================================
Approach 1: Brute Force

Method:
- Whenever a 0 is encountered, mark all non-zero elements
  in its row and column with a temporary value (-1).
- After processing the entire matrix, replace all marked
  cells with 0.

Time Complexity: O((m * n) * (m + n))
Space Complexity: O(1)
=======================================================
*/

class Solution {
public:
    void markRow(vector<vector<int>>& matrix, int i) {
        for (int j = 0; j < matrix[0].size(); j++) {
            if (matrix[i][j] != 0)
                matrix[i][j] = -1;
        }
    }

    void markCol(vector<vector<int>>& matrix, int j) {
        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[i][j] != 0)
                matrix[i][j] = -1;
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    markRow(matrix, i);
                    markCol(matrix, j);
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == -1)
                    matrix[i][j] = 0;
            }
        }
    }
};


/*
=======================================================
Approach 2: Better

Method:
- Use two auxiliary arrays to keep track of which rows
  and columns contain a zero.
- Traverse the matrix once to mark the affected rows and
  columns.
- Traverse again and set a cell to zero if either its row
  or column is marked.

Time Complexity: O(m * n)
Space Complexity: O(m + n)
=======================================================
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> row(m, 0), col(n, 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (row[i] || col[j])
                    matrix[i][j] = 0;
            }
        }
    }
};


/*
=======================================================
Approach 3: Optimal

Method:
- Use the first row and first column as marker arrays.
- If matrix[i][j] == 0, mark:
      matrix[i][0] = 0
      matrix[0][j] = 0
- Use a separate variable (col0) to track whether the
  first column should be zero, since matrix[0][0]
  cannot represent both the first row and first column.
- Traverse the matrix in reverse order and update cells
  based on the markers.

Time Complexity: O(m * n)
Space Complexity: O(1)
=======================================================
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        int col0 = 1;

        // Step 1: Mark rows and columns
        for (int i = 0; i < m; i++) {

            if (matrix[i][0] == 0)
                col0 = 0;

            for (int j = 1; j < n; j++) {

                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Step 2: Fill the matrix using the markers
        for (int i = m - 1; i >= 0; i--) {

            for (int j = n - 1; j >= 1; j--) {

                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }

            if (col0 == 0)
                matrix[i][0] = 0;
        }
    }
};