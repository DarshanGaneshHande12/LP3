#include <iostream>
#include <vector>
using namespace std;

// Partition using first element as pivot
int partition(vector<int>& arr, int low, int high)
{
    int pivot = arr[low];

    int i = low + 1;
    int j = high;

    while (i <= j)
    {
        while (i <= high && arr[i] <= pivot)
            i++;

        while (j >= low + 1 && arr[j] > pivot)
            j--;

        if (i < j)
            swap(arr[i], arr[j]);
    }

    swap(arr[low], arr[j]);

    return j;
}

// Quick Sort function
void quickSort(vector<int>& arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements: ";

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";

    for (int x : arr)
        cout << x << " ";

    return 0;
}


/*
    QUICK SORT:

    1. Quick Sort is a Divide and Conquer algorithm.
    2. It uses the first element as the pivot.
    3. Smaller elements go to the left and greater elements go to the right.
    4. The pivot reaches its correct sorted position.
    5. Recursively sort the left and right subarrays.

    SAMPLE INPUT:
    8
    5 3 8 4 2 7 1 6

    SAMPLE OUTPUT:
    1 2 3 4 5 6 7 8


    TIME COMPLEXITY:

    1. BEST CASE: O(n log n)
       - Pivot divides the array into two equal halves.
       - Partitioning takes O(n) at each level.
       - There are O(log n) levels.

    2. AVERAGE CASE: O(n log n)
       - Pivot divides the array into reasonably balanced parts on average.
       - Partitioning takes O(n) per level.
       - Average recursion depth is O(log n).

    3. WORST CASE: O(n^2)
       - Pivot is always the smallest or largest element.
       - One partition becomes empty, and the other has (n-1) elements.
       - Work becomes n + (n-1) + (n-2) + ... + 1.
       - This results in O(n^2).

    NOTE:
    Since we use the first element as pivot, an already sorted
    array can result in the worst-case O(n^2).


    SPACE COMPLEXITY:

    Average Case: O(log n) - Recursion stack.
    Worst Case: O(n) - Recursion stack.

    Quick Sort is generally an in-place sorting algorithm.
*/
