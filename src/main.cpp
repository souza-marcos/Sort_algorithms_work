#include <iostream>
#include "sortAlgorithms.cpp"

using namespace std;

int main()
{
    cout << "Trabalho Pratico 1 - AEDII"
         << "\nMENU"
         << "\nEscolha um metodo de ordenacao:"
         << "\n(1) Bubble Sort"
         << "\n(2) Insertion Sort"
         << "\n(3) Selection Sort"
         << "\n(4) Shell Sort"
         << "\n\nSua opcao: " ;
    int option;
    cin >> option;

    switch (option)
    {
    case 1:
        cout << "Bubble Sort" << endl;
        break;
    case 2:
        cout << "Insertion Sort" << endl;
        break;
    case 3:
        cout << "Selection Sort" << endl;
        break;
    case 4:
        cout << "Shell Sort" << endl;
        break;
    default:
        cout << "Opcao invalida" << endl;
        break;
    }
    return 0;
}