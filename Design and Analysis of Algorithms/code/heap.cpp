#include <iostream>
using namespace std;

// swap 2 variables
void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

// Function to heapify the tree
void heapify(int arr[], int n, int i) {
  int largest = i;   // Initialize largest as root
  int l = 2 * i + 1; // left = 2*i + 1
  int r = 2 * i + 2; // right = 2*i + 2

  // If left child is larger than root
  if (l < n && arr[l] > arr[largest])
    largest = l;

  // If right child is larger than largest so far
  if (r < n && arr[r] > arr[largest])
    largest = r;

  // If largest is not root
  if (largest != i) {
    swap(arr[i], arr[largest]);
    // Recursively heapify the affected sub-tree
    heapify(arr, n, largest);
  }
}

// Function to build a Max-Heap from the given array
void buildHeap(int arr[], int n) {
  // Index of last non-leaf node
  int startIdx = (n / 2) - 1;

  // Perform reverse level order traversal from last non-leaf node and heapify
  // each node
  for (int i = startIdx; i >= 0; i--) {
    heapify(arr, n, i);
  }
}

// Function to sort an array using Heap Sort
void heapSort(int arr[], int n) {
  // Build a max heap
  buildHeap(arr, n);

  // Heap sort
  for (int i = n - 1; i > 0; i--) {
    // Swap
    swap(arr[0], arr[i]);
    // Heapify root element to get highest element at root again
    heapify(arr, i, 0);
  }
}

// Function to print an array
void printArray(int arr[], int n) {
  for (int i = 0; i < n; ++i)
    cout << arr[i] << " ";
  cout << endl;
}

// Driver code
int main() {
  int arr[] = {1, 12, 9, 5, 6, 10};
  int n = sizeof(arr) / sizeof(arr[0]);

  heapSort(arr, n);

  cout << "Sorted array is " << endl;
  printArray(arr, n);
}
