#include <iostream>
#include <cctype>

void uppercase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        std:: cout <<  static_cast<char>(toupper(static_cast<unsigned char>(str[i]))) ;
    }
}

int main(int argc, char **argv)
{
    if (argc == 1)
        std:: cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    for (int i = 1; i < argc; i++)
    {
        uppercase(argv[i]);
        if (argc > 2 && i != argc -1)
            std:: cout << ' ' ;
    }
    std:: cout << '\n';
}