#include <iostream>
#include <string>

class bad_length {};

int function(std::string str, int forbidden_length) {
    if (str.length() == forbidden_length) {
        throw bad_length();
    }
    return str.length();
}

int main()
{
    setlocale(LC_ALL, "Russian");   
    int forb_length;
    std::string str_input;

    std::cout << "Введите длину для запрета: ";
    std::cin >> forb_length;

    while (true) {
        std::cout << "Введите слово: ";
        std::cin >> str_input;
        try {
            function(str_input, forb_length);
            std::cout << "Длина слова \"" << str_input << "\" равна " << str_input.length() << std::endl;
        }
        catch (bad_length) {
            std::cout << "Вы ввели слово запретной длины! До свидания." << std::endl;
            break;
        }
    }
    return 0;
}
