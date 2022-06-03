#include <iostream>
#include <vector>
#include "../src/utils/tools.hpp"
#include "../src/sortAlgorithms.hpp"
#include "../src/utils/dataFile.cpp"

using namespace std;

const int NUM_ALGORITHMS = 1;
const int NUM_INTANCES = 1;
const string PATH_SAVE_DATA = "../data/out/";

bool saveOnFile(AlgorithmDetails details[NUM_ALGORITHMS][NUM_INTANCES])
{
    string data;
    for (int i = 0; i < NUM_ALGORITHMS; i++)
    {
        for (int j = 0; j < NUM_INTANCES; j++)
        {
            data += "SORT_STR\t" +
                    to_string(details[i][j].numComparisons) + "\t" +
                    to_string(details[i][j].numSwaps) + "\t" +
                    to_string(details[i][j].time.count()) + "\t" +
                    to_string(details[i][j].sizeIntance) + "\n";
        }
    }
    cout << "Digite o nome do arquivo: ";
    string nome;
    cin >> nome;

    saveData(PATH_SAVE_DATA, nome, data);
    return true;
}

int main()
{
    AlgorithmDetails detail;
    vector<int> arr = {2, 3, 4, 1, 8, 6, 2};
    tools::printArray(arr);
    detail = selectionSort<int>(
        arr,
        [](int a, int b) -> bool
        {
            return a > b;
        },
        tools::printArray);
    cout << "Ordenacao concluida!" << endl;
    cout << "Tempo de execucao: " << detail.time.count() << "us" << endl;
    cout << "Numero de comparacoes: " << detail.numComparisons << endl;
    cout << "Numero de trocas: " << detail.numSwaps << endl;
    cout << "Numero de elementos: " << detail.sizeIntance << "\n\n";

    AlgorithmDetails aux[1][1];
    aux[0][0] = detail; 
    saveOnFile(aux);

    // tools::pause();
}