/**
 * @file sortAlgorithms.hpp
 * @author Marcos Daniel (marcos.dev@gmail.com)
 * @brief File for the declaration of the sorting functions
 * @version 0.1
 * @date 2022-05-07
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <vector>
#include <chrono>

struct AlgorithmDetails
{
    unsigned long numSwaps = 0, numComparisons = 0;
    std::chrono::microseconds time = std::chrono::microseconds(0);
    int sizeIntance = 0;
};

// Implementation of the sorting functions

template <typename T>
AlgorithmDetails bubbleSort(
    std::vector<T> &arr,
    void (*print)(std::vector<T> arr) = NULL)
{
    AlgorithmDetails details;
    int i, j, temp;
    for (i = 0; i < arr.size() - 1; i++)
    {
        for (j = 0; j < arr.size() - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                details.numSwaps++;
                if (print != NULL)
                    print(arr);
            }
            details.numComparisons++;
        }
    }
    return details;
}

template <typename T>
AlgorithmDetails insertionSort(
    std::vector<T> &arr,
    void (*print)(std::vector<T> arr) = NULL)
{
    AlgorithmDetails details;
    int p = 1;
    while (p < arr.size())
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
                details.numSwaps++;
                if (print != NULL)
                    print(arr);
            }
            else
            {
                break;
            }
            details.numComparisons++;
        }
        p++;
    }
    return details;
}

template <typename T>
AlgorithmDetails selectionSort(
    std::vector<T> &arr,
    void (*print)(std::vector<T> arr) = NULL)
{
    AlgorithmDetails details;
    int min;
    for (int i = 0; i < arr.size(); i++)
    {
        min = i;
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
            details.numComparisons++;
        }
        if (min == i)
            continue;
        int aux = arr[i];
        arr[i] = arr[min];
        arr[min] = aux;
        details.numSwaps++;
        if (print != NULL)
            print(arr);
    }
    return details;
}

template <typename T>
AlgorithmDetails shellSort(
    std::vector<T> &arr,
    void (*print)(std::vector<T> arr) = NULL)
{
    AlgorithmDetails details;
    int h = 1;

    while ((3 * h + 1) < arr.size())
    {
        h = 3 * h + 1;
    }

    while (h >= 1)
    {
        for (int i = 0; i < arr.size() - h; i++)
        {
            if (arr[i] > arr[i + h])
            {
                int aux = arr[i];
                arr[i] = arr[i + h];
                arr[i + h] = aux;
                details.numSwaps++;
                if (print != NULL)
                    print(arr);
            }
            details.numComparisons++;
        }
        h /= 3;
    }
    return details;
}

template <typename T>
AlgorithmDetails quickSort(
    std::vector<T> &arr,
    int init,
    int end,
    AlgorithmDetails &details,
    void (*print)(std::vector<T> arr) = NULL)
{

    T aux = arr[(end + init) / 2];
    arr[(end + init) / 2] = arr[end];
    arr[end] = aux;

    int pivotIndex = end, lessN = init, higherN = init;

    for (int i = init; i <= end; i++)
    {
        /*std::cout << "P: " << pivotIndex << "\n"
                  << "INIT " << init << "\n"
                  << "end " << end << "\n"
                  << "i " << i << "\n\n";*/
        //std::cout << i << "\n";
        if (arr[i] <= arr[pivotIndex]) //
        {
            T aux = arr[i];
            arr[i] = arr[lessN];
            arr[lessN] = aux;
            details.numSwaps++;

            lessN++;
            higherN++;

            if (print != NULL)
                print(arr);
        }
        else
        {
            higherN++;
        }
        details.numComparisons++;
    }
    // system("pause");

    pivotIndex = lessN - 1;

    if ((pivotIndex - 1) > init)
        quickSort(arr, init, pivotIndex - 1, details, print);

    if ((pivotIndex + 1) < end)
        quickSort(arr, pivotIndex + 1, end, details, print);

    return details;
}

template <typename T>
AlgorithmDetails quickSortWrapper(
    std::vector<T> &arr,
    void (*print)(std::vector<T> arr) = NULL)
{
    AlgorithmDetails details;
    try
    {
        quickSort(arr, 0, arr.size() - 1, details, print);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return details;
}

template <typename T>
AlgorithmDetails mergeSort(
    std::vector<T> &arr,
    int start,
    int end,
    AlgorithmDetails &details,
    void (*print)(std::vector<T> arr) = NULL)
{
    int size = end - start + 1, middle = (end + start) / 2;
    if (size > 2)
    {
        mergeSort(arr, start, middle, details, print);
        mergeSort(arr, middle + 1, end, details, print);

        // Intercala
        int i = start, j = middle + 1;
        int arr_aux[size];
        for (int k = 0; k < size; k++)
        {
            if ((arr[i] <= arr[j] && i <= middle) || j > end)
            {
                arr_aux[k] = arr[i];
                i++;
            }
            else if (j <= end)
            {
                arr_aux[k] = arr[j];
                j++;
            }
            details.numComparisons++;
        }
        for (int i = 0; i < size; i++)
        {
            arr[i + start] = arr_aux[i];
            details.numSwaps++;
        }
        if (print != NULL)
            print(arr);
    }
    else
    {
        if (arr[start] > arr[end])
        {
            int aux = arr[start];
            arr[start] = arr[end];
            arr[end] = aux;
            details.numSwaps++;
            if (print != NULL)
                print(arr);
        }
        details.numComparisons++;
    }
    return details;
}

template <typename T>
AlgorithmDetails mergeSortWrapper(
    std::vector<T> &arr,
    void (*print)(std::vector<T> arr) = NULL)
{
    AlgorithmDetails details;
    mergeSort(arr, 0, arr.size() - 1, details, print);
    return details;
}