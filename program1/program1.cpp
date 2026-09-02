#include <iostream>
using namespace std;

// Function to merge two sorted parts
void merge(int arr[], int low, int mid, int high) {
    int i = low;
    int j = mid + 1;
    int k = 0;

    int temp[high - low + 1];

    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    // Copy remaining elements from left part
    while (i <= mid)
        temp[k++] = arr[i++];

    // Copy remaining elements from right part
    while (j <= high)
        temp[k++] = arr[j++];

    // Copy back to original array
    for (i = low, k = 0; i <= high; i++, k++)
        arr[i] = temp[k];
}

// ---------------- Recursive Merge Sort ----------------

void recursiveMergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;

        recursiveMergeSort(arr, low, mid);
        recursiveMergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

// ---------------- Iterative Merge Sort ----------------

void iterativeMergeSort(int arr[], int n) {
    for (int size = 1; size < n; size *= 2) {

        for (int low = 0; low < n - size; low += 2 * size) {

            int mid = low + size - 1;
            int high = min(low + 2 * size - 1, n - 1);

            merge(arr, low, mid, high);
        }
    }
}

// Function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;
}

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr1[n], arr2[n];

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
        arr2[i] = arr1[i];
    }

    // Recursive Merge Sort
    recursiveMergeSort(arr1, 0, n - 1);

    cout << "\nSorted using Recursive Merge Sort: ";
    printArray(arr1, n);

    // Iterative Merge Sort
    iterativeMergeSort(arr2, n);

    cout << "Sorted using Iterative Merge Sort: ";
    printArray(arr2, n);

    return 0;
}