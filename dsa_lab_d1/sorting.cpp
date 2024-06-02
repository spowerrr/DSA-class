#include <bits/stdc++.h>

void selectionSort(int arr[], int n) {
  int i, j, min_idx, min;

  for (i = 0; i < n - 1; i++) {
    min = arr[i];
    min_idx = i;
    for (j = i + 1; j < n; j++)
      if (arr[j] < min) {
        min = arr[j];
        min_idx = j;
      }
    if (min_idx != i) {
      int temp = arr[i];
      arr[i] = arr[min_idx];
      arr[min_idx] = temp;
    }
  }
}

void insertionSort(int arr[], int n) {
  for (int i = 1; i < n; i++) {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) { // asccending order
      arr[j + 1] = arr[j];           // right shift
      j--;
    }
    arr[j + 1] = key;
  }
}

void evenOddInsertionSort(int arr[], int n) {
  for (int i = 2; i < n; i++) {
    int key = arr[i];
    int j = i - 2;
    if (i % 2 == 0) {
      while (j >= 0 && arr[j] < key) { // descending order
        arr[j + 2] = arr[j];           // right shift
        j -= 2;
      }
      arr[j + 2] = key;
    } else {
      while (j >= 0 && arr[j] > key) // asccending order
      {
        arr[j + 2] = arr[j]; // right shift
        j -= 2;
      }
      arr[j + 2] = key;
    }
  }
}

int main() {
  int arr[] = {64, 25, 12, 22, 11};
  int n = sizeof(arr) / sizeof(arr[0]);
  // selectionSort(arr, n);
  // insertionSort(arr,n);
  evenOddInsertionSort(arr, n);
  printf("Sorted array: \n");
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
  return 0;
}
