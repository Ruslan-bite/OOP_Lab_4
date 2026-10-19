#include <iostream>
#include <windows.h>
#include "money.h"
using namespace std;

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    cout << " Створення об'єктів трьома конструкторами " << endl;
    money a;   // конструктор за замовчуванням
    money b(125, 50);   // конструктор з параметрами
    money c(b);   // конструктор копіювання
    cout << "a = "; a.Display();
    cout << "b = "; b.Display();
    cout << "c = "; c.Display();

    cout << "\n Введення першої суми " << endl;
    a.Read();

    cout << "\nПерша сума (a): ";
    a.Display();
    cout << "Друга сума (b): ";
    b.Display();
    cout << "Копія другої суми (c): ";
    c.Display();

    cout << "\n Арифметичні операції " << endl;
    cout << "\nРезультат додавання:" << endl;
    money sum = a + b;
    sum.Display();

    cout << "\nРезультат віднімання:" << endl;
    money difference = a - b;
    difference.Display();

    cout << "\nРезультат ділення сум:" << endl << a.Divide(b) << endl;

    cout << "\nРезультат ділення першої суми на 2.5:" << endl;
    money quotient = a.DivideByNumber(2.5);
    quotient.Display();

    cout << "\nРезультат множення першої суми на 2.5:" << endl;
    money product = a.MultiplyByNumber(2.5);
    product.Display();

    cout << "\n Порівняння " << endl;
    if (a == b) cout << "Суми рівні" << endl;
    if (!(a == b)) cout << "Суми не рівні" << endl;
    if (a > b) cout << "Перша сума більша" << endl;
    if (b > a) cout << "Перша сума менша" << endl;

    return 0;
}