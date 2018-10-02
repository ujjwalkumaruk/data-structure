#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 100
#define val 73
int *arr, *check;

int partition (int start, int end) {
  int pivot = arr[end], index = start;
  for (int i = start; i < end; i++) {
    // printf("%d ", arr[i]);
    if (arr[i] <= pivot) {
      int temp = arr[index];
      arr[index] = arr[i];
      arr[i] = temp;
      index++;
    }
  } 
  int temp = arr[index];
  arr[index] = arr[end];
  arr[end] = temp;
  return index;
}

void quicksort (int start, int end) {
  if (start < end) {
    int index = partition(start, end);
    quicksort (start, index - 1);
    quicksort (index + 1, end);
  }
}

int interpolation_search (int start, int end) {
  if (arr[end] - arr[start] == 0)
    return -1;
  int mid = start + (val - arr[start]) * (end - start) / (arr[end] - arr[start]);
  if (mid < 0 || mid > n - 1)
    return -1;
  if (arr[mid] == val) {
    return mid;
  } else if (val > arr[mid]) {
    return interpolation_search (mid + 1, end);
  } else {
    return interpolation_search (start, mid - 1);
  }
}

int main() {
  srand(time(NULL));
  int temp;
  arr = (int *) malloc (n * sizeof(int));
  check = (int *) calloc (0, 1001 * sizeof(int));
  for (int i = 0; i < n; i++) {
    while(1) {
      temp = rand() % 1000 + 1;
      if (check[temp] == 0) {
        arr[i] = temp;
        check[temp] = 1;
        break;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  quicksort (0, n - 1);
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  int index = interpolation_search(0, n - 1);
  if (index != -1) {
    printf("%d found at index %d\n", val, index);
  } else {
    printf("%d not found.\n", val);
  }
  free (arr);
  free (check);
  return 0;
}