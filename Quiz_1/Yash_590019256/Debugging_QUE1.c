/*  1. Bug or Logical Flaw in the Code
Bug:
The main logical flaw is the initialization of currentSum to 0.
When all elements are negative, currentSum is reset to 0 whenever it becomes negative, which means maxSum will never be updated to any of the actual (negative) array values if they are all less than zero.
This leads to incorrect results for arrays with all negative numbers.
   2. Case: Array Contains All Negative Numbers
Explanation:
With the current logic, currentSum is reset to 0 whenever it goes negative.
For an all-negative array, after the first iteration, currentSum will always be less than 0 and thus reset to 0 every time.
This means maxSum will only be updated if the first element is the largest, and only if the logic allows.
    3. Output for int arr[] = {-3, -2, -1, -4};
Step-by-step Execution:
maxSum = -3, currentSum = 0
i = 0: currentSum = -3; maxSum stays -3; currentSum reset to 0
i = 1: currentSum = -2; maxSum updated to -2; currentSum reset to 0
i = 2: currentSum = -1; maxSum updated to -1; currentSum reset to 0
i = 3: currentSum = -4; maxSum stays -1; currentSum reset to 0
Return value:
-1 (which is correct in this case, but only because the largest single element is found; the logic is still flawed for some variations).
    4. Corrected Version of the Function*/
#include <stdio.h>

int maxSubarraySum(int nums[], int n) 
{
    int maxSum = nums[0];
    int currentSum = nums[0];

    for (int i = 1; i < n; i++) 
    {
        if (currentSum + nums[i] > nums[i])
            currentSum += nums[i];
        else
            currentSum = nums[i];

        if (currentSum > maxSum)
            maxSum = currentSum;
    }
    return maxSum;
}

int main() 
{
    int arr[] = {-3, -2, -1, -4};
    int size = sizeof(arr) / sizeof(arr[0]);

    int result = maxSubarraySum(arr, size);
    printf("Maximum Subarray Sum: %d\n", result);

    return 0;
}
