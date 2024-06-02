#include <bits/stdc++.h>
using namespace std;

// Structure to represent frequency of elements
struct Frequency {
  int x, count;
};

// Function to sort an array using insertion sort

void insertionSort(int arr[], int n) {
  for (int i = 1; i < n; i++) {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) { // Sort in ascending order
      arr[j + 1] = arr[j]; // Right shift element to make space for key
      j--;
    }
    arr[j + 1] = key; // Insert key in correct position
  }
}

// Function to find the frequency of each element in the array
void findFrequency(struct Frequency f[], int arr[], int n) {
  f[0].x = arr[0]; // Initialize first element of frequency array
  f[0].count = 1;  // Set count of first element to 1
  int k = 0;       // Index for frequency array
  int i, j;
  for (i = 1; i < n; i++) {
    // Search for arr[i] in frequency array
    for (j = 0; j <= k; j++) {
      if (f[j].x == arr[i]) {
        f[j].count++; // Increment count if element found
        break;
      }
    }

    // If arr[i] is not found in the frequency array, add it
    if (j > k) {
      k++;
      f[k].x = arr[i]; // Add new element to frequency array
      f[k].count = 1;  // Set count of new element to 1
    }
  }
}

// Function to sort Frequency array by count (descending) and value (ascending)
void sortFrequency(struct Frequency f[], int n) {
  for (int i = 1; i < n; i++) {
    struct Frequency key = f[i];
    int j = i - 1;

    // Sort by count in descending order
    // If counts are equal, sort by value in ascending order
    while (j >= 0 && (f[j].count < key.count ||
                      (f[j].count == key.count && f[j].x > key.x))) {
      f[j + 1] = f[j]; // Shift elements to right
      j--;
    }
    f[j + 1] = key; // Insert key in correct position
  }
}

int main() {
  // Input array
  int arr[] = {8, 8, 8, 5, 2, 3, 2, 5};
  int n = sizeof(arr) / sizeof(arr[0]); // Calculate size of array

  // Frequency array
  // Initialize frequency array with 0
  // in cpp we can't initialize like this struct Frequency f[n] = {0};
  struct Frequency f[n];

  for (int i = 0; i < n; ++i) {
    f[i].x = 0;
    f[i].count = 0;
  }

  insertionSort(arr, n); // Sort the input array
  printf("Sorted array: \n");
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]); // Print sorted array
  printf("\n");

  findFrequency(f, arr, n); // Find frequency of each element
  // just to check the frequency array
  printf("f[0].x: %d\n", f[0].x);
  printf("f[0].count: %d\n", f[0].count);
  printf("f[1].x: %d\n", f[1].x);
  printf("f[1].count: %d\n", f[1].count);
  printf("f[2].x: %d\n", f[2].x);
  printf("f[2].count: %d\n", f[2].count);
  printf("f[3].x: %d\n", f[3].x);
  printf("f[3].count: %d\n", f[3].count);
  // printf("f[4].x: %d\n", f[4].x);
  // printf("f[4].count: %d\n", f[4].count);
  // printf("f[5].x: %d\n", f[5].x);
  // printf("f[5].count: %d\n", f[5].count);
  // printf("f[6].x: %d\n", f[6].x);
  // printf("f[6].count: %d\n", f[6].count);
  // printf("f[7].x: %d\n", f[7].x);
  // printf("f[7].count: %d\n", f[7].count);

  // Find number of unique elements
  int uniqueCount = 0;
  while (uniqueCount < n && f[uniqueCount].count != 0) {
    uniqueCount++;
  }
  printf("uniqueCount: %d\n", uniqueCount);
  // Sort the frequency array
  sortFrequency(f, uniqueCount);

  // Print sorted array based on frequency
  printf("Array sorted by frequency: \n");
  for (int i = 0; i < uniqueCount; ++i) {
    for (int j = 0; j < f[i].count; ++j) {
      printf("%d ", f[i].x);
    }
  }
  printf("\n");

  return 0;
}
