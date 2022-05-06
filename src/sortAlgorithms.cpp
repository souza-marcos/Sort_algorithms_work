/**
 * @file sortAlgorithms.cpp
 * @author Marcos Daniel (marcos.dev@gmail.com)
 * @brief File for the implementation of the sorting algorithms
 * @version 0.1
 * @date 2022-05-06
 *
 * @copyright Copyright (c) 2022
 *
 */


/**
 * @brief Function to sort the array using the bubble sort algorithm
 *
 * @param arr Array to be sorted
 * @param n Size of the array
 * @return int Number of swaps
 */
int bubleSort(int arr[], int n)
{
    int i, j, temp, count = 0;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                count++;
            }
        }
    }
    return count;
}

/**
 * @brief Function to sort the array using the insertion sort algorithm
 *
 * @param arr Array to be sorted
 * @param n Size of the array
 * @return int Number of swaps
 */
int insertionSort(int arr[], int n)
{
    int p = 1, count = 0;
    while (p < n)
    {
        int i = p - 1;
        while (i >= 0)
        {
            if (arr[i + 1] < arr[i])
            {
                int temp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = temp;
                i--;
                count++;
            }
            else
            {
                break;
            }
        }
        p++;
    }
    return count;
}


/**
 * @brief Function to sort the array using the selection sort algorithm
 * 
 * @param arr Array to be sorted
 * @param n Size of the array
 * @return int Number of swaps
 */
int selectionSort(int arr[], int n)
{
    int min, count = 0;
    for (int i = 0; i < n; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (min == i)
            continue;
        int aux = arr[i];
        arr[i] = arr[min];
        arr[min] = aux;
        count++;
    }
    return count;
}

/**
 * @brief Function to sort the array using the shell sort algorithm
 * 
 * @param arr Array to be sorted
 * @param n Size of the array
 * @return int Number of swaps
 */
int shellSort(int arr[], int n)
{
    int h = 1, count = 0;
    
    while((3*h + 1) < n){
        h = 3*h + 1;
    }

    while (h >= 1)
    {
        for (int i = 0; i < n - h; i++)
        {
            if (arr[i] > arr[i + h]) //45, 56, 12, 43, 95, 19, 8, 67
            {
                int aux = arr[i];
                arr[i] = arr[i + h];
                arr[i + h] = aux;
                count++;
            }
        }
        h /= 3;
    }
    return count;
}
