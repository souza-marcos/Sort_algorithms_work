#include <vector>
namespace tools
{
    template <typename T>
    void printArray(std::vector<T> arr)
    {
        for (auto i : arr)
        {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    void pause()
    {
        std::cout << "\nPressione qualquer tecla para continuar...";
        std::cin.ignore();
        std::cin.get();
    }

}