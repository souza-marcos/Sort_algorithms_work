#include <iostream>
#include "../src/sortAlgorithms.hpp"
#include "../src/utils/dataFile.cpp"
#include "../src/utils/tools.hpp"
#include <vector>

using namespace std;

bool compare(int a, int b)
{
    return (a >= b);
}

int main()
{

    vector<int> arr;
    getDataFromInstance("../data/in/", "ListaInversamenteOrdenada-100000.txt", arr);
    // tools::printArray<int>(arr);"ListaInversamenteOrdenada-100000.txt"
    /*quickSortWrapper<int>(
        arr,
        [](int a, int b) -> bool
        {
            return a > b;
        });*/

    AlgorithmDetails details;
    quickSortWrapper(arr);
    tools::printArray<int>(arr);
}