#include <iostream>
#include <vector>
#include <functional>
#include "sortAlgorithms.hpp"
#include "utils/tools.hpp"
#include "utils/dataFile.cpp"

using namespace std;

const string PATH_GET_DATA = "../data/in/";
const string PATH_SAVE_DATA = "../data/out/";
const int NUM_ALGORITHMS = 4;
const int NUM_INTANCES = 12;

string switchInstance(int n)
{
    switch (n)
    {
    case 1:
        return "ListaAleatoria-1000.txt";
    case 2:
        return "ListaAleatoria-10000.txt";
    case 3:
        return "ListaAleatoria-100000.txt";
    case 4:
        return "ListaInversamenteOrdenada-1000.txt";
    case 5:
        return "ListaInversamenteOrdenada-10000.txt";
    case 6:
        return "ListaInversamenteOrdenada-100000.txt";
    case 7:
        return "ListaOrdenada-1000.txt";
    case 8:
        return "ListaOrdenada-10000.txt";
    case 9:
        return "ListaOrdenada-100000.txt";
    case 10:
        return "ListaQuaseOrdenada-1000.txt";
    case 11:
        return "ListaQuaseOrdenada-10000.txt";
    case 12:
        return "ListaQuaseOrdenada-100000.txt";
    }
    return "";
}

template <typename T>
std::function<AlgorithmDetails(std::vector<T> &, void (*print)(std::vector<T> arr))> switchSort(int n)
{

    switch (n)
    {
    case 1:
        return bubbleSort<T>;
    case 2:
        return insertionSort<T>;
    case 3:
        return selectionSort<T>;
    case 4:
        return shellSort<T>;
    case 5:
        return mergeSortWrapper<T>;
    case 6:
        return quickSortWrapper<T>;
    }

    return NULL;
}

string switchSortStr(int n)
{
    switch (n)
    {
    case 1:
        return "bubbleSort";
    case 2:
        return "insertionSort";
    case 3:
        return "selectionSort";
    case 4:
        return "shellSort";
    case 5:
        return "mergeSort";
    case 6:
        return "quickSort";
    }
    return "";
}

AlgorithmDetails sort(
    std::vector<int> &arr,
    std::function<AlgorithmDetails(std::vector<int> &arr, void (*print)(std::vector<int> arr))> sortAlgorithm,
    void (*print)(std::vector<int> arr) = NULL)
{
    AlgorithmDetails details;
    auto start = std::chrono::high_resolution_clock::now();
    details = sortAlgorithm(arr, print);
    auto end = std::chrono::high_resolution_clock::now();
    details.time = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    details.sizeIntance = arr.size();

    return details;
}

void runAll()
{
    vector<int> arr;
    for (int i = 1; i <= NUM_INTANCES; i++)
    {
        string instance = switchInstance(i);

        for (int j = 1; j <= NUM_ALGORITHMS; j++)
        {
            getDataFromInstance(PATH_GET_DATA, instance, arr);
            cout << "Instance: " << instance << endl;
            cout << "Sort: " << switchSortStr(j) << endl;
            cout << "Ordenando..." << endl;

            AlgorithmDetails detail = sort(arr, switchSort<int>(j));

            cout << "Ordenacao concluida!" << endl;
            cout << "Tempo de execucao: " << detail.time.count() << "us" << endl;
            cout << "Numero de comparacoes: " << detail.numComparisons << endl;
            cout << "Numero de trocas: " << detail.numSwaps << endl;
            cout << "Numero de elementos: " << detail.sizeIntance << "\n\n";
        }
        cout << "------------------------------------------------------\n\n";
    }
}

void runAllResearch()
{
    AlgorithmDetails details[NUM_ALGORITHMS][NUM_INTANCES][10];
    AlgorithmDetails result[NUM_ALGORITHMS][NUM_INTANCES];
    vector<int> arr;
    for (int i = 1; i <= NUM_INTANCES; i++)
    {
        string instance = switchInstance(i);

        for (int j = 1; j <= NUM_ALGORITHMS; j++)
        {
            for (int k = 1; k <= 10; k++)
            {
                getDataFromInstance(PATH_GET_DATA, instance, arr);
                cout << "Sort: " << switchSortStr(j) << " Instance: " << instance << endl;
                cout << "Ordenando..." << endl;
                details[j - 1][i - 1][k - 1] = sort(arr, switchSort<int>(j));
                cout << "Ordenacao concluida!" << endl;
            }
        }
        cout << "------------------------------------------------------\n\n";
    }
    cout << "Teste finalizado!" << endl;

    for (int i = 0; i < NUM_ALGORITHMS; i++)
    {
        for (int j = 0; j < NUM_INTANCES; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                result[i][j].time += details[i][j][k].time;
                result[i][j].numComparisons += details[i][j][k].numComparisons;
                result[i][j].numSwaps += details[i][j][k].numSwaps;
            }
            result[i][j].time = result[i][j].time / 10;
            result[i][j].numComparisons = result[i][j].numComparisons / 10;
            result[i][j].numSwaps = result[i][j].numSwaps / 10;

            cout << "Algoritmo: " << switchSortStr(i + 1) << endl;
            cout << "Numero de comparacoes: " << result[i][j].numComparisons << endl;
            cout << "Numero de trocas: " << result[i][j].numSwaps << endl;
            cout << "Tempo de execucao: " << result[i][j].time.count() << "us" << endl;
            cout << "Numero de elementos: " << result[i][j].sizeIntance << "\n\n";
        }
    }
}

int switchModeMenu()
{
    cout << "\nEscolha um modo de execucao:\n";
    cout << "(1) - Normal  ->     1 instancia, 1 metodo ordenacao\n";
    cout << "(2) - Teste   ->   vetor usuario, 1 metodo ordenacao\n";
    cout << "(3) - Pesquisa-> todas instacias, todos metodos ordenamento x10\n";
    cout << "(0) - Pesquisa-> todas instacias, todos metodos ordenamento x1\n";
    int mode;
    cin >> mode;
    return mode;
}
int switchSortMenu()
{
    cout << "Trabalho Pratico 1 - AEDII"
         << "\nMENU"
         << "\nEscolha um metodo de ordenacao:"
         << "\n(1) Bubble Sort"
         << "\n(2) Insertion Sort"
         << "\n(3) Selection Sort"
         << "\n(4) Shell Sort"
         << "\n(5) Merge Sort"
         << "\n(6) Quick Sort"
         << "\n\nSua opcao: ";
    int sortMethod;
    cin >> sortMethod;
    return sortMethod;
}
int switchInstanceMenu()
{
    cout << "MENU"
         << "\n Escolha uma instancia de teste:"
         << "\n(1) Lista Aleatoria 1000 elementos"
         << "\n(2) Lista Aleatoria 10000 elementos"
         << "\n(3) Lista Aleatoria 100000 elementos"
         << "\n(4) Lista Quase Ordenada 1000 elementos"
         << "\n(5) Lista Quase Ordenada 10000 elementos"
         << "\n(6) Lista Quase Ordenada 100000 elementos"
         << "\n(7) Lista Inversamente Ordenada 1000 elementos"
         << "\n(8) Lista Inversamente Ordenada 10000 elementos"
         << "\n(9) Lista Inversamente Ordenada 100000 elementos"
         << "\n(10) Lista Ordenada 1000 elementos"
         << "\n(11) Lista Ordenada 10000 elementos"
         << "\n(12) Lista Ordenada 100000 elementos"
         << "\n\nSua opcao: ";
    int numInstance;
    cin >> numInstance;
    return numInstance;
}

void getDataFromConsole(vector<int> &arr)
{
    cout << "Digite o numero de elementos: ";
    int n;
    cin >> n;
    cout << "Digite " << n << " numeros: ";
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        arr.push_back(num);
    }
}
void printDetail(AlgorithmDetails detail)
{
    cout << "Tempo de execucao: " << detail.time.count() << "us" << endl;
    cout << "Numero de comparacoes: " << detail.numComparisons << endl;
    cout << "Numero de trocas: " << detail.numSwaps << endl;
    cout << "Numero de elementos: " << detail.sizeIntance << "\n\n";
}

int restartMenu()
{
    cout << "------------------------------------------------------\n\n";
    cout << "Deseja executar outra operacao? (1) Sim (2) Nao" << endl;
    int option;
    cin >> option;
    system("cls");
    return option;
}

int main()
{
    int option = 1;
    while (option == 1)
    {
        int mode = switchModeMenu();

        void (*print)(std::vector<int> arr) = NULL;
        vector<int> arr;

        if (mode == 3)
        {
            runAllResearch();
            tools::pause();
            option = restartMenu();
            continue;
        }
        if (mode == 0)
        {
            auto start = std::chrono::high_resolution_clock::now();
            runAll();
            auto end = std::chrono::high_resolution_clock::now();
            cout << "\nTempo de execucao TOTAL: " << std::chrono::duration_cast<std::chrono::seconds>(end - start).count() << "s" << endl;
            tools::pause();
            option = restartMenu();
            continue;
        }

        if (mode == 2)
        {
            print = tools::printArray;
            getDataFromConsole(arr);
        }
        if (mode == 1)
        {
            int numInstance = switchInstanceMenu();
            getDataFromInstance(
                PATH_GET_DATA,
                switchInstance(numInstance),
                arr);
        }
        int sortMethod = switchSortMenu();

        cout << "Sort: " << switchSortStr(sortMethod) << endl;
        cout << "Ordenando..." << endl;

        AlgorithmDetails detail = sort(arr, switchSort<int>(sortMethod), print);

        cout << "Ordenacao concluida!" << endl;
        printDetail(detail);
        tools::pause();
        option = restartMenu();
    }
    return 0;
}