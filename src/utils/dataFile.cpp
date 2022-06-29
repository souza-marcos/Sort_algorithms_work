#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void getDataFromInstance(string path, string fileName, vector<int> &data)
{
    ifstream ist;
    ist.open(path + fileName);

    if (!ist.is_open() || ist.fail())
    {
        cout << "\n\nERRO AO ABRIR O ARQUIVO\n\n";
        return;
    }

    int value;
    data.clear();
    while (!ist.eof())
    {
        ist >> value;
        data.push_back(value);
    }
    ist.close();
    data.pop_back(); // Because the file end with a new empty line
}

void saveData(string path, string fileName, string data)
{
    ofstream ost;
    ost.open(path + fileName, ofstream::out | ofstream::trunc);

    if (!ost.is_open() || ost.fail())
    {
        cout << "\n\nERRO AO SALVAR OS DADOS\n\n";
        return;
    }

    ost << data;
    ost.close();
}
