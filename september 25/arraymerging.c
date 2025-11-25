// write a c program to display merged 2 sorted arrays

#include <stdio.h>

// Function to input array elements
void inputArray(int arr[], int n) {
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

// Function to display array elements
void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to sort array (simple bubble sort)
void sortArray(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to merge two sorted arrays
void mergeArrays(int a[], int n, int b[], int m, int result[]) {
    int i = 0, j = 0, k = 0;

    while (i < n && j < m) {
        if (a[i] <= b[j])
            result[k++] = a[i++];
        else
            result[k++] = b[j++];
    }

    // Copy remaining elements
    while (i < n)
        result[k++] = a[i++];

    while (j < m)
        result[k++] = b[j++];
}

int main() {
    int n, m;

    // Input size for array 1
    printf("Enter number of elements for Array 1: ");
    scanf("%d", &n);
    int a[n];

    // Input size for array 2
    printf("Enter number of elements for Array 2: ");
    scanf("%d", &m);
    int b[m];

    // Input arrays
    printf("\n--- Input Array 1 ---\n");
    inputArray(a, n);

    printf("\n--- Input Array 2 ---\n");
    inputArray(b, m);

    // Sort arrays
    sortArray(a, n);
    sortArray(b, m);

    // Display sorted arrays
    printf("\nSorted Array 1: ");
    displayArray(a, n);

    printf("Sorted Array 2: ");
    displayArray(b, m);

    // Merge arrays
    int merged[n + m];
    mergeArrays(a, n, b, m, merged);

    // Display merged array
    printf("\nMerged Sorted Array: ");
    displayArray(merged, n + m);

    return 0;
}
