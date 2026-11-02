
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

In the 0/1 Knapsack problem, we create a DP table for every possible weight capacity from 0 up to the given maximum capacity. 
This is because, when considering whether to include an item, we calculate the remaining capacity by subtracting the item's weight from the current capacity.
We then use the previously calculated optimal value for that remaining capacity to determine the maximum total value without exceeding the knapsack's weight limit.


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
