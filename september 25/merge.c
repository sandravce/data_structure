#include <stdio.h>

#define MAX_SIZE 20   // maximum allowed size

// Function to sort an array using Selection Sort
void sort_array(int arr[], int n) {
    int i, j, minIndex, temp;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// Function to merge two sorted arrays
void merge_arrays(int arr1[], int n1, int arr2[], int n2, int merged[]) {
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }
    while (i < n1) {
        merged[k++] = arr1[i++];
    }
    while (j < n2) {
        merged[k++] = arr2[j++];
    }
}

// Function to display an array
void display_array(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// ---------- MAIN ----------
int main() {
    int n1, n2, i;

    printf("Enter size of first array (max %d): ", MAX_SIZE);
    scanf("%d", &n1);

    if (n1 > MAX_SIZE) {
        printf("Error: Array size cannot be greater than %d\n", MAX_SIZE);
        return 0;  // stop the program
    }

    int A[n1];
    printf("Enter %d elements for first array:\n", n1);
    for (i = 0; i < n1; i++) {
        scanf("%d", &A[i]);
    }

    printf("\nEnter size of second array (max %d): ", MAX_SIZE);
    scanf("%d", &n2);

    if (n2 > MAX_SIZE) {
        printf("Error: Array size cannot be greater than %d\n", MAX_SIZE);
        return 0;
    }

    int B[n2];
    printf("Enter %d elements for second array:\n", n2);
    for (i = 0; i < n2; i++) {
        scanf("%d", &B[i]);
    }

    int merged[n1 + n2];

    // Sort arrays
    sort_array(A, n1);
    sort_array(B, n2);

    printf("\nSorted Arrays:\n");
    display_array(A, n1);
    display_array(B, n2);

    // Merge arrays
    merge_arrays(A, n1, B, n2, merged);

    printf("\nMerged Array:\n");
    display_array(merged, n1 + n2);

    return 0;
}
