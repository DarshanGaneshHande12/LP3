
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack(vector<int>& weight, vector<int>& value, int n, int W)
{
    // DP table: (n+1) rows and (W+1) columns
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // i represents the number of items considered
    for (int i = 1; i <= n; i++)
    {
        // w represents the current knapsack capacity
        for (int w = 1; w <= W; w++)
        {
            // If current item is heavier than capacity,
            // we cannot include it.
            if (weight[i - 1] > w)
            {
                dp[i][w] = dp[i - 1][w];
            }
            else
            {
                // Choice 1: Do not include the current item
                int exclude = dp[i - 1][w];

                // Choice 2: Include the current item
                // Calculate remaining capacity and use its previous best value.
                int include = value[i - 1] +
                              dp[i - 1][w - weight[i - 1]];

                // Store the maximum of both choices
                dp[i][w] = max(include, exclude);
            }
        }
    }

    return dp[n][W];
}

int main()
{
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    vector<int> weight(n), value(n);

    cout << "Enter weights: ";
    for (int i = 0; i < n; i++)
        cin >> weight[i];

    cout << "Enter values: ";
    for (int i = 0; i < n; i++)
        cin >> value[i];

    cout << "Enter knapsack capacity: ";
    cin >> W;

    cout << "Maximum value: "
         << knapsack(weight, value, n, W);

    return 0;
}

/*
    0/1 KNAPSACK - DYNAMIC PROGRAMMING

    1. PROBLEM:
       - We are given items with weights and values.
       - Each item can either be selected (1) or rejected (0).
       - We cannot select fractions of an item.
       - Our objective is to maximize total value without
         exceeding the knapsack capacity.

    2. DP TABLE:
       - Rows represent the number of items considered.
       - Columns represent every possible capacity from 0 to W.
       - dp[i][w] represents the maximum value obtainable
         using the first i items with capacity w.

    3. WHY DO WE CREATE A COLUMN FOR EVERY CAPACITY?

       Suppose the maximum capacity is 7.
       We create columns for capacities 0, 1, 2, 3, 4, 5, 6, 7.

       This is because when we consider including an item,
       we need to calculate the remaining capacity.

       Remaining capacity = Current capacity - Item weight

       We then look up the best value for that remaining
       capacity using the previous items.

       Example:
       Item B has weight 3 and value 4.
       Current capacity = 4.

       Remaining capacity = 4 - 3 = 1.

       Therefore:
       Include B = value of B + dp[1][1]
                 = 4 + 1
                 = 5

       Here, dp[1][1] represents the best value obtained
       using the previous items (item A) with capacity 1.

       This allows us to select both A and B.

       We calculate smaller capacities first and reuse
       their results to calculate larger capacities.
       This is the main idea of Dynamic Programming.

    4. DP CONDITIONS:

       If item weight > current capacity:
           dp[i][w] = dp[i-1][w]

       Otherwise, we have two choices:

       Exclude the item:
           dp[i-1][w]

       Include the item:
           value[i-1] + dp[i-1][w-weight[i-1]]

       Select the maximum of both choices.

       We use the previous row (i-1) when including an item
       to ensure that the same item is not selected again.

    5. SAMPLE INPUT:

       Number of items: 4
       Weights: 1 3 4 5
       Values:  1 4 5 7
       Capacity: 7

    6. SAMPLE OUTPUT:

       Maximum value: 9

       Selected items: B and C
       Total weight = 3 + 4 = 7
       Total value  = 4 + 5 = 9

    7. TIME COMPLEXITY:

       O(n * W)

       We have two nested loops:
       - Outer loop runs n times (number of items).
       - Inner loop runs W times (capacity).

       Each DP cell is calculated in O(1) time.

    8. SPACE COMPLEXITY:

       O(n * W)

       We create a 2D DP table with (n+1) rows
       and (W+1) columns.
*/
