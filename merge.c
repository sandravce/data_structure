#include <stdio.h>

void display_array(int arr[], int size) 
{
    for(int i = 1; i <= size; i++) 
    {
        printf("%d\n", arr[i]);
    }   
}

// Bubble sort function (1-based indexing)
void bubble_sort(int arr[], int size) 
{
    for(int i = 1; i <= size - 1; i++) 
    {
        for(int j = 1; j <= size - i; j++) 
        {
            if(arr[j] > arr[j + 1]) 
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Merge two sorted arrays a[1..n] and a2[1..m] into merged[]
void merge_arrays(int a[], int n, int a2[], int m, int merged[]) 
{
    int i = 1, j = 1, k = 1;

    while(i <= n && j <= m) 
    {
        if(a[i] < a2[j]) 
        {
            merged[k++] = a[i++];
        } 
        else 
        {
            merged[k++] = a2[j++];
        }
    }

    while(i <= n) 
    {
        merged[k++] = a[i++];
    }

    while(j <= m) 
    {
        merged[k++] = a2[j++];
    }
}

int main()
{
    int n, a[50], a2[50], i, b, j;

    printf("Enter how many elements you need to store to array 1:");
    scanf("%d", &n);

    if(n > 50)
    {
        printf("Maximum number of elements which can be inserted into array 1 is 50.\n");
        return 1;
    }

    printf("Enter the elements :\n");
    for(i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }

    // Sort array 1 separately
    bubble_sort(a, n);
    printf("\nSorted array 1:\n");
    display_array(a, n);

    // Array 2 input
    printf("Enter how many elements you need to store to array 2:");
    scanf("%d", &b);

    if(b > 50)
    {
        printf("Maximum number of elements which can be inserted into array 2 is 50.\n");
        return 1;
    }

    printf("Enter the elements :\n");
    for(i = 1; i <= b; i++)
    {
        scanf("%d", &a2[i]);
    }

    // Sort array 2 separately
    bubble_sort(a2, b);
    printf("\nSorted array 2:\n");
    display_array(a2, b);

    // Now merge the two sorted arrays
    int merged[100];
    merge_arrays(a, n, a2, b, merged);

    printf("\nMerged sorted array:\n");
    for(i = 1; i <= n + b; i++)
    {
        printf("%d\n", merged[i]);
    }

    return 0;
}


