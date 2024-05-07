#include <stdio.h>

void create_Array(int a[], int n) {
    int i;
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
}

void display_Array(int a[], int n) {
    int i;
    printf("The array:\n");
    for (i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }
}

int binary_Search(int a[], int low, int high, int key) {
    if (low > high)
        return -1; // element not found

    int mid = (low + high) / 2;

    if (key == a[mid])
        return mid; // element found

    if (key > a[mid])
        return binary_Search(a, mid+1, high, key); // search in the right half
    else
        return binary_Search(a, low, mid-1, key); // search in the left half
}

int main() {
    int a[100], n, key, index;
    printf("Enter the length of the array:");
    scanf("%d", &n);
    create_Array(a, n);
    display_Array(a, n);
    printf("\nEnter the value to be searched:");
    scanf("%d", &key);
    index = binary_Search(a, 0, n - 1, key);
    if (index == -1)
        printf("Element not found");
    else
        printf("%d is found at %d position", key, index + 1);
    return 0;
}
