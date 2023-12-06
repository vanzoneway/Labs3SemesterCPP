#define LSIZE 110
#include <numeric>
#include "textnote.h"


int main() {
    setlocale(LC_ALL, "");

    TextNote myFile("something.txt");

    int width {};

    while (true)
    {
        std::cout << "Input a width of line in txt file\n>";
        std::cin >> width;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        if (width <= 0)
            continue;
        break;
    }
    myFile.RewriteFile(width);
    std::cout << myFile << std::endl;
    std::cout << "Done";
    std::cin.get();
    std::cin.get();

    return 0;
}
