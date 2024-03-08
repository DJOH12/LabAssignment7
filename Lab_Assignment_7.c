#include <stdio.h>
#include <stdlib.h>

void printSwaps(int swaps[], int array[], int size) {
    int totalSwaps = 0;
    for (int i = 0; i < size; ++i) {
        printf("%d: %d\n", array[i], swaps[array[i]]);
        totalSwaps += swaps[array[i]];
    }
    printf("Total # of swaps: %d\n\n", totalSwaps);
}

void initArray(int swaps[], int size) {
    for (int i = 0; i < size; ++i) {
        swaps[i] = 0;
    }
}

int bubbleSort(int array[], int size) {
    int swaps[101];
    initArray(swaps, 101);
    int totalSwaps = 0;

    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                swaps[array[j]]++;
                swaps[array[j + 1]]++;
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                totalSwaps++;
            }
        }
    }

    printSwaps(swaps, array, size);
    return totalSwaps;
}

int selectionSort(int array[], int size) {
    int swaps[101];
    initArray(swaps, 101);
    int totalSwaps = 0;

    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swaps[array[i]]++;
            swaps[array[minIndex]]++;
            int temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp;
            totalSwaps++;
        }
    }

    printSwaps(swaps, array, size);
    return totalSwaps;
}

int main() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int size1 = sizeof(array1) / sizeof(array1[0]);
    int size2 = sizeof(array2) / sizeof(array2[0]);
    int sortedArray1[size1], sortedArray2[size2];

    printf("array1 bubble sort:\n");
    for (int i = 0; i < size1; i++) sortedArray1[i] = array1[i]; // Copy original array
    bubbleSort(sortedArray1, size1);

    printf("array2 bubble sort:\n");
    for (int i = 0; i < size2; i++) sortedArray2[i] = array2[i]; // Copy original array
    bubbleSort(sortedArray2, size2);

    printf("array1 selection sort:\n");
    for (int i = 0; i < size1; i++) sortedArray1[i] = array1[i]; // Copy original array
    selectionSort(sortedArray1, size1);

    printf("array2 selection sort:\n");
    for (int i = 0; i < size2; i++) sortedArray2[i] = array2[i]; // Copy original array
    selectionSort(sortedArray2, size2);

    return 0;
}
