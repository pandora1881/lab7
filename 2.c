#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initializeArray(int array[], int size)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 201 - 100; // генеруємо випадкове число з діапазону [-100, 100]
    }
}

void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int countElementsLessThanSeven(int array[], int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] < 7)
        {
            count++;
        }
    }
    return count;
}

int getProductBetweenZeros(int array[], int size)
{
    int product = 1;
    int firstZeroIndex = -1;
    int secondZeroIndex = -1;

    for (int i = 0; i < size; i++)
    {
        if (array[i] == 0)
        {
            if (firstZeroIndex == -1)
            {
                firstZeroIndex = i;
            }
            else
            {
                secondZeroIndex = i;
                break;
            }
        }
    }

    if (firstZeroIndex != -1 && secondZeroIndex != -1 && secondZeroIndex > firstZeroIndex + 1)
    {
        for (int i = firstZeroIndex + 1; i < secondZeroIndex; i++)
        {
            product *= array[i];
        }
    }
    else
    {
        product = 0; // якщо немає двох нульових елементів або вони знаходяться поруч, добуток буде 0
    }

    return product;
}

int main()
{
    const int SIZE = 10; // розмір масиву
    int array[SIZE];

    initializeArray(array, SIZE);
    printf("Масив: ");
    printArray(array, SIZE);

    int count = countElementsLessThanSeven(array, SIZE);
    printf("Кількість елементів масиву, менших за число 7: %d\n", count);

    int product = getProductBetweenZeros(array, SIZE);
    printf("Добуток елементів масиву, розташованих між першим й другим нульовими елементами: %d\n", product);

    return 0;
}
