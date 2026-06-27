// LeetCode 48. Rotate Image

/*
=======================================================
Approach 1: Brute Force

Method:
- Create a temporary matrix of the same size.
- For each element, place it in its rotated position
  using temp[j][n - 1 - i] = matrix[i][j].
- Copy the temporary matrix back to the original matrix.

Time Complexity: O(n²)
Space Complexity: O(n²)
=======================================================
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> temp(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                temp[j][n - 1 - i] = matrix[i][j];
            }
        }

        matrix = temp;
    }
};


/*
=======================================================
Approach 2: Optimal (Transpose + Reverse)

Method:
- Transpose the matrix by swapping matrix[i][j] with
  matrix[j][i].
- Reverse every row of the transposed matrix.
- This rotates the matrix by 90° clockwise in-place.

Time Complexity: O(n²)
Space Complexity: O(1)
=======================================================
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Step 1: Transpose the matrix
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: Reverse each row
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};