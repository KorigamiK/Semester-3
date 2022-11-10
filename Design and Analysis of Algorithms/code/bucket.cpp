#include <iostream>
#include <vector>
using namespace std;

void bucketSort(float arr[], int n) {
    // Create n empty buckets
    vector<float> b[n];

    // Put array elements in different buckets
    for (int i = 0; i < n; i++) {
        int bi = n * arr[i]; // Index in bucket
        b[bi].push_back(arr[i]);
    }

    // Sort individual buckets
    for (int i = 0; i < n; i++)
        sort(b[i].begin(), b[i].end());

    // Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++)
            arr[index++] = b[i][j];
}

// * Driver program to test above functions
int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    float arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    bucketSort(arr, n);

    cout << "Sorted array is ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
