// LeetCode 54. Spiral Matrix

/*
=======================================================
Approach: Optimal (Boundary Traversal)

Method:
- Maintain four boundaries: top, bottom, left, and right.
- Traverse the matrix layer by layer in four directions:
  left → right, top → bottom, right → left, and
  bottom → top.
- After completing each direction, update the
  corresponding boundary.
- Continue until all elements have been visited.

Time Complexity: O(m * n)
Space Complexity: O(1) (excluding the output array)
=======================================================
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> ans;

        int top = 0;
        int bottom = m - 1;
        int left = 0;
        int right = n - 1;

        while (top <= bottom && left <= right) {

            // Traverse Left -> Right
            for (int j = left; j <= right; j++) {
                ans.push_back(matrix[top][j]);
            }
            top++;

            // Traverse Top -> Bottom
            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;

            // Traverse Right -> Left
            if (top <= bottom) {
                for (int j = right; j >= left; j--) {
                    ans.push_back(matrix[bottom][j]);
                }
                bottom--;
            }

            // Traverse Bottom -> Top
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return ans;
    }
};