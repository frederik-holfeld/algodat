// by Frederik Holfeld

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Sorting and search algorithms taken from previous exercise apart from unknownSort().

void quickSort(int arr[], int l, int r) {
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

int linearSearch(int arr[], int key, int size) {
  for (int i = 0; i < size; i++) {
    if (arr[i] == key) return i;
  }
  return -1;
}

int binarySearch(int arr[], int key, int size) {
  int middle, left = 0, right = size - 1;

  while (left <= right) {
    middle = (left + right) / 2;

    if (arr[middle] == key) return middle;
    else if (arr[middle] > key) right = middle - 1;
    else if (arr[middle] < key) left = middle + 1;
  }
  return -1;
}

void fillArray(int arr[], int max, int size) {
  for (int i = 0; i < size; i++) {
    arr[i] = rand() % max + 1;
  }
}

void unknownSort(int *arr, int size) {
  for (int i = 1; i < size; i++) {
    if (arr[i - 1] > arr[i]) {
      int tmp = arr[i];
      arr[i] = arr[i - 1];
      arr[i - 1] = tmp;
      printf("%d mit %d vertauscht!\n", arr[i], arr[i - 1]);
      if (i - 2 >= 0) {
        i = i - 2;
        printf("Zwei Schritte nach links!\n");
      }
    }
    printf("Ein Schritt nach rechts!\n");
  }
}

void arrayAusgeben(int *arr, int size) {
  printf("\n");
  for (int i = 0; i < size; i++) {
    printf("%d\n", arr[i]);
  }
}

int main() {
  /*
  Bei der Zeitmessung wurde mir nicht klar, in welcher Einheit die Ausgabe von
  clock() ist, und das Makro CLOCKS_PER_SEC hat bei mir 1000000 in printf
  ausgegeben, was mit der Taktrate meines Computers von 3,6-3,8 GHz nichts zu
  tun hat. Daher erscheint mir die beste Lösung, direkt den Integer von clock()
  zu verwenden, da es ja eher um die Relation der Geschwindigkeiten geht.
  */

  srand(time(NULL));

  int arr1Size = 1040000;
  int arr1[arr1Size];
  fillArray(arr1, 50000, arr1Size);
  int arr2Size = arr1Size;
  int arr2[arr2Size];
  fillArray(arr2, 50000, arr2Size);

  // Aufgabe 1
  printf("Aufgabe 1:\n");

  int key = rand() % 50000 + 1;

  int start = clock();
  linearSearch(arr1, key, arr1Size);
  printf("Linear search clocks: %d\n", clock() - start);

  start = clock();
  quickSort(arr1, 0, arr1Size - 1);
  binarySearch(arr1, key, arr1Size);
  printf("Binary search clocks with quicksort: %d\n", clock() - start);

  start = clock();
  binarySearch(arr1, key, arr1Size);
  printf("Binary search clocks without quicksort: %d\n", clock() - start);


  // Aufgabe 2
  printf("\nAufgabe 2:\n");

  int keysSize = 10000;
  int keys[keysSize];
  fillArray(keys, 50000, keysSize);

  long timeSum = 0;

  for (int i = 0; i < keysSize; i++) {
    start = clock();
    linearSearch(arr2, keys[i], arr2Size);
    timeSum = timeSum + clock() - start;
  }
  printf("Average linear search clocks: %d\n", timeSum / keysSize);

  start = clock();
  quickSort(arr2, 0, arr2Size - 1);
  binarySearch(arr2, keys[0], arr2Size);
  timeSum = clock() - start;
  for (int i = 1; i < keysSize; i++) {
    start = clock();
    binarySearch(arr2, keys[i], arr2Size);
    timeSum = timeSum + clock() - start;
  }
  printf("Average binary search clocks: %d\n", timeSum / keysSize);


  // Aufgabe 3
  printf("\nAufgabe 3:\n");

  int arr3Size = 5;
  int arr3[arr3Size];
  fillArray(arr3, 30, arr3Size);

  unknownSort(arr3, arr3Size);
  arrayAusgeben(arr3, arr3Size);

  return 0;
}

/*
Bei Aufgabe 2 habe ich beobachtet, dass die lineare Suche, wie erwartet, je nach
Position des Elements, stark unterschiedliche Laufzeiten haben kann, das Mittel
ist bei n von 10.000 dann aber doch recht konstant zwischen 105 und 110.
Beim Binary Search ist aufgefallen, dass das einmalige Sortieren mit Quick Sort
bereits ca. 2/3 der Laufzeit beansprucht. Die Suche ist hingegen aber so
schnell, dass 10.000 Iterationen lediglich ein Drittel zur Laufzeit beitragen.
Dies bedeutet, dass der Binary Sort möglichst bei Datenmengen angewendet werden
sollte, die sich nicht ständig ändern und wieder neu sortiert werden müssen, da
die lange Sortierdauer die Effizienz der Suche überwiegt und dann eine lineare
Suche womöglich schneller sein könnte.
*/
