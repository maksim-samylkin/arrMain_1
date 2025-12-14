#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <string>
#include <ctime> 

inline void Getline(std::string& str)
{
    std::getline(std::cin, str);
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
}

int const carriage = 18;
int const seat = 36;

void ArrWagon(int Arr[carriage][seat])
{
    std::string choose;

    std::cout << "1 - рандом\n 2 - все пусто: ";
    Getline(choose);

    if (choose == "1")
    {
        std::cout << "Рандом\n";
        for (size_t i = 0; i < carriage; i++)
        {
            for (size_t t = 0; t < seat; t++)
            {
                Arr[i][t] = rand() % 2;
            }
        }
    }
    else if (choose == "2")
    {
        std::cout << "Пусто\n";
        for (size_t i = 0; i < carriage; i++)
        {
            for (size_t t = 0; t < seat; t++)
            {
                Arr[i][t] = 0;
            }
        }
    }
    else
    {
        std::cout << "Ошибка\n";
    }
}

void PrintArr(const int Arr[carriage][seat])
{
    for (size_t i = 0; i < carriage  ; i++)
    {
        std::cout << "Вагон " << i + 1  << "  \n";
        for (size_t t = 0; t < seat; t++)
        {
            if (Arr[i][t] == 1)
            {
                std::cout << "Занято: " << t + 1 << "\n";
            }
            else
            {
                std::cout << "Свободно: " << t + 1 << "\n";
            }
        }
        std::cout << "\n";
    }
}

bool IsNumber(const std::string& str)
{
    if (str.empty())
    {
        return false;
    }

    for (std::size_t i = 0; i < str.size(); i++)
    {
        if (!std::isdigit(str[i]))
        {
            return false;
        }
    }
    return true;
}

void controlArr(int Arr[carriage][seat])
{
    std::string choose;
    int wagon, place;
    while (true)
    {


        std::cout << "Введите номер вагона (от 1 до 18): ";
        Getline(choose);

        if (!IsNumber(choose))
        {
            std::cout << "Ошибка\n";
            return;
        }

        wagon = std::stoi(choose) - 1;
        if (wagon >= 0 && wagon <= 17)
        {
            std::cout << "Введите номер места (от 1 до 36): ";
            Getline(choose);

            if (!IsNumber(choose))
            {
                std::cout << "Ошибка\n";
                return;
            }



            place = std::stoi(choose) - 1;
            if (place >= 0  && place <= 35)
            {
                std::cout << "1 - забронировать\n 2 - освободить: ";
                Getline(choose);

                if (choose == "1")
                {
                    if (Arr[wagon][place] == 0)
                    {
                        Arr[wagon][place] = 1;
                        std::cout << "Забронировано\n";
                        break;
                    }
                    else
                    {
                        std::cout << "Уже занято\n";
                        break;
                    }
                }
                else if (choose == "2")
                {
                    if (Arr[wagon][place] == 1)
                    {
                        Arr[wagon][place] = 0;
                        std::cout << "Освобождено\n";
                        break;
                    }
                    else
                    {
                        std::cout << "Уже свободно\n";
                        break;
                    }
                }
                else
                {
                    std::cout << "Ошибка\n";
                }
            }
            else
            {
                std::cout << "Ошибка\n";
            }
         }

          
        else
        {
            std::cout << "Ошибка\n";
        }
    }

       
  
}

int main()
{
    srand(time(NULL));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    system("cls");

    int Arr[carriage][seat];
    std::string choose;

    while (true)
    {
        std::cout << "1 - Заполнить\n2 - Показать\n3 - Управлять\n0 - Выход\n";
        std::cout << "Выбор: ";
        Getline(choose);

        if (choose == "1")
        {
            ArrWagon(Arr);
        }
        else if (choose == "2")
        {
            PrintArr(Arr);
        }
        else if (choose == "3")
        {
            controlArr(Arr);
        }
        else if (choose == "0")
        {
            break;
        }
        else
        {
            std::cout << "Ошибка\n";
        }

        std::cout << "\n";
    }

    return 0;
}