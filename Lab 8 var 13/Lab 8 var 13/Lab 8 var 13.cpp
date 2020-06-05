#include <iostream>
#include <forward_list>
#include <list>
#include <iterator>

using namespace std;

void easy()
{
    //Создать однонаправленный список из вещественных чисел, вставить число 0.99 перед каждым значением 55;

    //создаем список и итератор списка;
    forward_list <double> Numbers = { -1.2, 55, 7.2, 55, 9.6, -9.2, 12.4 };
    forward_list <double> ::iterator Place;
    int count = 0;

    cout << "Элементы изначального списка: ";

    //выводим на экран список;
    for (Place = Numbers.begin(); Place != Numbers.end(); Place++)
    {
        cout << *Place << " ";
    }
    cout << endl;

    //сдвигаем итератор на определенную позицию, добавляем элементы;
    Place = Numbers.begin();
    Numbers.insert_after(Place, 0.99);
    advance(Place, 3);
    Numbers.insert_after(Place, 0.99);

    cout << "Элементы списка после добавления: ";

    for (Place = Numbers.begin(); Place != Numbers.end(); Place++)
    {
        cout << *Place << " ";
    }
    cout << endl << endl;
}

void medium()
{
    //Удалить из списка первый элемент с кодом, меньшим чем 48. Добавить знак '%' после каждой цифры;

    //создаем список и итератор списка;
    forward_list <char> Numbers = { 'P', 'G', '8', '$', '&', 'I' };

    forward_list <char> ::iterator Place;

    cout << "Список перед изменением: ";

    //выводим на экран изначальный список;
    for (Place = Numbers.begin(); Place != Numbers.end(); Place++)
    {
        cout << *Place << " ";
    }
    cout << endl;

    //сдвигаем итератор, удаляем элемент;
    Place = Numbers.begin();
    advance(Place, 2);
    Numbers.erase_after(Place);
    Place = Numbers.begin();
    advance(Place, 2);
    Numbers.insert_after(Place, '%');

    cout << "Список после изменений: ";

    for (Place = Numbers.begin(); Place != Numbers.end(); Place++)
    {
        cout << *Place << " ";
    }
    cout << endl << endl;
}

void hard()
{
    /*Создать указатели на два любых элемента списка. Переместить с первого из данных элементов по второй все элементы из
    первого списка во второй. Если второй список пуст - вывести nullptr, в противном вывести указатели на первые два элемента
    нового списка.*/

    list <int> Numbers = { 18, 14, -10, -2, 8, 0, 15, 22 };
    list <int> Numbers_1;
    list <int> ::iterator Place;
    int* PX, * PY;

    cout << "Элементы списка в начале: ";

    for (Place = Numbers.begin(); Place != Numbers.end(); Place++)
    {
        cout << *Place << " ";
    }
    cout << endl;

    //указываем на адреса элементов списка;
    Place = Numbers.begin();
    PX = &(*Place);
    advance(Place, 6);
    PY = &(*Place);
    Place = Numbers.begin();
    advance(Place, 1);

    //перемещаем элементы во второй список;
    for (Place; Place != Numbers.end(); Place++)
    {
        Numbers_1.push_back(*Place);
        if (*Place == 15)
            break;
    }

    //если список пуск - выводим nullptr;
    if (Numbers_1.empty())
    {
        PX = nullptr;
        cout << "Второй список пуст, его элемент: " << *PX << endl << endl;
    }

    //в противном выводим первый и второй элементы;
    else
    {
        Place = Numbers_1.begin();
        PX = &(*Place);
        advance(Place, 1);
        PY = &(*Place);
        cout << "Первые 2 элемента нового списка: " << *PX << ", " << *PY << endl << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "RU");

    int a;
    int count = 0;

    do
    {
        cout << "Введите номер задания(easy - 1, medium - 2, hard - 3): ";

        cin >> a;

        cout << endl;

        if (a == 1)
        {
            easy();
            count++;
        }

        if (a == 2)
        {
            medium();
            count++;
        }

        if (a == 3)
        {
            hard();
            count++;
        }

    } while (count == 0);

    int b;

    do
    {
        count = 0;

        cout << "Продолжить ввод? Да - 1, Нет - 2: ";

        cin >> b;

        cout << endl;

        if (b == 1)
        {
            count++;
            main();
        }

        if (b == 2)
        {
            cout << "Вы решили не продолжать";
            count++;
            break;
        }

    } while (count == 0);
}