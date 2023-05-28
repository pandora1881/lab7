#include <stdio.h>

void changeminus(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            arr[i] = -1;
        }
    }
}

void changeplus(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            arr[i] = 1;
        }
    }
}

int main()
{
    int n;
    printf("Введіть кількість елементів послідовності: ");
    scanf("%d", &n);

    int arr[n];
    printf("Введіть елементи послідовності:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    changeminus(arr, n);
    changeplus(arr, n);

    printf("Результат:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
