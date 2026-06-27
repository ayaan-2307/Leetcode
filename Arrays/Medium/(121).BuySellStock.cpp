// LeetCode 121. Best Time to Buy and Sell Stock

/*
=======================================================
Approach 1: Brute Force

Method:
- Consider every possible day as the buying day.
- For each buying day, check every later day as the
  selling day.
- Calculate the profit for each pair and keep track of
  the maximum profit.

Time Complexity: O(n²)
Space Complexity: O(1)
=======================================================
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                maxProfit = max(maxProfit, prices[j] - prices[i]);
            }
        }

        return maxProfit;
    }
};


/*
=======================================================
Approach 2: Optimal

Method:
- Keep track of the minimum stock price seen so far.
- For each day, calculate the profit by selling on that
  day after buying at the minimum price.
- Update the maximum profit and the minimum price while
  traversing the array once.

Time Complexity: O(n)
Space Complexity: O(1)
=======================================================
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int mini = prices[0];

        for (int i = 1; i < prices.size(); i++) {
            int cost = prices[i] - mini;
            profit = max(profit, cost);
            mini = min(mini, prices[i]);
        }

        return profit;
    }
};