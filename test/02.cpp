#include <iostream>
using namespace std;

int returnZero(int anyNumber) {
    if(anyNumber == 0)
        return 0;
    else  {
        anyNumber--;
        return returnZero(anyNumber);
    }
}
int main()
{
    int anyNumber;
    cin >> anyNumber;
    int zero = returnZero(anyNumber);
    cout << zero << endl;
}