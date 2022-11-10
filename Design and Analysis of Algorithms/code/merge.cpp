#include <iostream>
using namespace std;

// merge two sorted subarrays arr[low..mid] and arr[mid+1..high]
void merge(int arr[], int low, int mid, int high)
{
    // create a temp array
    int temp[high - low + 1];

    // crawlers for both intervals and for temp
    int i = low, j = mid + 1, k = 0;

    // traverse both arrays and in each iteration add smaller of both elements in temp
    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    // add elements left in the first interval
    while (i <= mid)
        temp[k++] = arr[i++];

    // add elements left in the second interval
    while (j <= high)
        temp[k++] = arr[j++];

    // copy temp to original interval
    for (int i = low; i <= high; i++)
        arr[i] = temp[i - low];
}

// Recursive implementation of merge sort
void mergeSort(int arr[], int low, int high)
{
    // base condition
    if (low == high)
        return;

    // find the mid value
    int mid = (low + (high - low) / 2);

    // recursively split the array into two halves until it can no more be split
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);

    merge(arr, low, mid, high);
}

int main()
{
    int arr[] = { 3, 5, 8, 4, 1, 9, -2 };
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
