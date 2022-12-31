// by Frederik Holfeld

#include <stdio.h>
#include <string.h>


// Blueprints for sorting and search algorithms was probably provided on the assignment sheet.

void bubbleSort(char arr[]) {
  for (int i = 0; i < strlen(arr); i++) {
    for (int j = 1; j < strlen(arr); j++) {
      if (arr[j - 1] < arr[j]) {
        int buff = arr[j];
        arr[j] = arr[j - 1];
        arr[j - 1] = buff;
      }
    }
  }
}

void quickSort(char arr[], int l, int r) {
  int i = l;
  int j = r;
  int mid = arr[(l + r) / 2];
  do {
    while (arr[i] < mid) i++;
    while (mid < arr[j]) j--;
    if (i <= j) {
      int buff = arr[i];
      arr[i] = arr[j];
      arr[j] = buff;
      i++;
      j--;
    }
  } while (i <= j);
  if (l < j) quickSort(arr, l, j);
  if (i < r) quickSort(arr, i, r);
}

int linearSearch(char arr[], char x) {
  for (int i = 0; i < strlen(arr); i++) {
    if (arr[i] == x) return i;
  }
  return -1;
}

int binarySearch(char arr[], char x) {
  int middle, left = 0, right = strlen(arr) - 1;

  quickSort(arr, 0, strlen(arr) - 1);

  while (left <= right) {
    middle = (left + right) / 2;

    if (arr[middle] == x) return middle;
    else if (arr[middle] > x) right = middle - 1;
    else if (arr[middle] < x) left = middle + 1;
  }
  return -1;
}

int main() {
  char string[] = "Hello World";
  bubbleSort(string);
  printf("Die Ausgabe von 1.1 lautet: '%s'.\n", string);
  quickSort(string, 0, strlen(string) - 1);
  printf("Die Ausgabe von 1.2 lautet: '%s'.\n", string);

  char string2[] = "Hello World";
  char key = 'd';
  printf("Die Ausgabe von 2.1 mit Schlüssel '%c' lautet: %d.\n", key, linearSearch(string2, key));
  printf("Die Ausgabe von 2.2 mit Schlüssel '%c' lautet: %d.\n", key, binarySearch(string2, key));
  return 0;
}
