#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 12  // Розмір масиву (два нулі)

void initializeArray(int array[], int size);
void printArray(int array[], int size);
int countElementsLessThanSeven(int array[], int size);
int getProductBetweenZeros(int array[], int size);

int main() {
    int array[SIZE];
    srand(time(NULL));

    initializeArray(array, SIZE);
    printf("Згенерований масив:\n");
    printArray(array, SIZE);

    int count = countElementsLessThanSeven(array, SIZE);
    printf("\nКількість елементів масиву, менших за число 7: %d\n", count);

    int product = getProductBetweenZeros(array, SIZE);
    printf("Добуток елементів масиву, розташованих між першим й другим нульовими елементами: %d\n", product);

    return 0;
}

void initializeArray(int array[], int size) {
    int zeroCount = 0;
    for (int i = 0; i < size; i++) {
        if (zeroCount < 2) {
            if (rand() % 4 == 0) {
                array[i] = 0;
                zeroCount++;
            } else {
                array[i] = rand() % 201 - 100;  // Генеруємо випадкове число в діапазоні [-100, 100]
            }
        } else {
            array[i] = rand() % 201 - 100;
        }
    }
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int countElementsLessThanSeven(int array[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] < 7) {
            count++;
        }
    }
    return count;
}

int getProductBetweenZeros(int array[], int size) {
    int product = 1;
    int firstZeroIndex = -1;
    int secondZeroIndex = -1;

    for (int i = 0; i < size; i++) {
        if (array[i] == 0) {
            if (firstZeroIndex == -1) {
                firstZeroIndex = i;
            } else if (secondZeroIndex == -1) {
                secondZeroIndex = i;
                break;
            }
        }
    }

    if (firstZeroIndex != -1 && secondZeroIndex != -1) {
        for (int i = firstZeroIndex + 1; i < secondZeroIndex; i++) {
            product *= array[i];
        }
    } else {
        product = 0;
    }

    return product;
}
