#include<iostream>
#include<vector>  
using namespace std;

/*
 ============================================================
  PROBLEM: COUNT INVERSIONS IN AN ARRAY
 ============================================================

  WHAT IS AN INVERSION?
  ---------------------
  A pair (i, j) is called an inversion if:
      - i < j  (i comes before j in the array)
      - arr[i] > arr[j]  (but the value at i is greater than value at j)

  Example:
      Array = {6, 3, 5, 2, 7}
      Inversions = (6,3), (6,5), (6,2), (3,2), (5,2)
      Total Inversions = 5

 ============================================================
  OPTIMIZED APPROACH: MERGE SORT
 ============================================================

  KEY INSIGHT:
  ------------
  During the merge step of Merge Sort, when we find that
  arr[j] < arr[i], it means ALL elements from index i to mid
  are greater than arr[j], because the left half is already sorted.
  So we can count (mid - i + 1) inversions in one shot.

  This allows us to count inversions while sorting the array
  at the same time!

 ============================================================
  STEP BY STEP BREAKDOWN
 ============================================================

  STEP 1 - DIVIDE:
  ----------------
  - Find the middle of the array
  - Recursively divide the left half  --> InverCount(arr, start, mid)
  - Recursively divide the right half --> InverCount(arr, mid+1, end)
  - Count inversions in each half

  STEP 2 - MERGE & COUNT:
  -----------------------
  - Take two sorted halves
  - Use two pointers i (left half) and j (right half)
  - Compare arr[i] and arr[j]:

      CASE 1: arr[i] <= arr[j]
          --> No inversion, place arr[i] in temp array
          --> Move i forward

      CASE 2: arr[j] < arr[i]
          --> arr[j] is smaller than arr[i]
          --> Since left half is sorted, arr[j] is also smaller
              than ALL elements from i to mid
          --> So inversions = (mid - i + 1)
          --> Place arr[j] in temp array
          --> Move j forward

  STEP 3 - COPY REMAINING ELEMENTS:
  -----------------------------------
  - If any elements are left in the left half, copy them
  - If any elements are left in the right half, copy them

  STEP 4 - UPDATE ORIGINAL ARRAY:
  --------------------------------
  - Copy the sorted temp array back into the original array
  - This ensures the array is sorted for the next merge step

 ============================================================
  EXAMPLE WALKTHROUGH: {6, 3, 5, 2, 7}
 ============================================================

  DIVIDE:
      Left  = {6, 3, 5}   Right = {2, 7}

      Left further divides:
          {6, 3, 5} --> {6, 3} and {5}
          {6, 3}    --> {6} and {3}

  MERGE & COUNT:
      Merge {6} and {3}:
          arr[j]=3 < arr[i]=6 --> inversions += (mid - i + 1) = 1
          Sorted: {3, 6}  | Count = 1

      Merge {3, 6} and {5}:
          arr[j]=5 < arr[i]=6 --> inversions += 1
          Sorted: {3, 5, 6}  | Count = 1

      Merge {2} and {7}:
          No inversion
          Sorted: {2, 7}  | Count = 0

      Merge {3, 5, 6} and {2, 7}:
          arr[j]=2 < arr[i]=3 --> inversions += 3  (3,2), (5,2), (6,2)
          arr[i]=3 < arr[j]=7 --> no inversion
          arr[i]=5 < arr[j]=7 --> no inversion
          arr[i]=6 < arr[j]=7 --> no inversion
          Sorted: {2, 3, 5, 6, 7}  | Count = 3

  TOTAL INVERSIONS = 1 + 1 + 0 + 3 = 5

 ============================================================
  COMPLEXITY ANALYSIS
 ============================================================

  Time Complexity:
      - Overall        : O(n log n)

 ============================================================
 */

int merge(vector<int>& arr, int start, int mid, int end)
{
    vector<int> temp(end - start + 1);

    int i = start;
    int j = mid + 1;
    int k = 0;

    int inversionCount = 0;

    while(i <= mid && j <= end)
    {
        if(arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = arr[j];
            k++;
            j++;

            inversionCount += (mid - i + 1);
        }
    }

    while(i <= mid)
    {
        temp[k] = arr[i];
        i++; k ++;
    }

    while(j <= end)
    {
        temp[k] = arr[j];
        k++; j++;
    }

    for (int i = 0; i < end - start + 1; i++)
    {
        arr[i + start] = temp[i];
    }

    return inversionCount;
}

int InverCount(vector<int>& arr, int start, int end)
{
    if(start >= end)
        return 0;

    int mid = start + (end - start) / 2;

    int inversionCount = 0;

    inversionCount += InverCount(arr, start, mid);
    inversionCount += InverCount(arr, mid + 1, end);

    inversionCount += merge(arr, start, mid, end);

    return inversionCount;
}

int main()
{
    vector<int> arr = {6,3,5,2,7};

    int result = InverCount(arr, 0, arr.size() - 1);
    cout << "Number of inversions are: " << result << endl;

    return 0;
}