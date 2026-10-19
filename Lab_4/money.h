#pragma once

/*Створити клас Money для роботи із грошовими сумами. Число повинне бути презентовано двома полями: типу long для гривень і типу unsigned char - для копійок. Дробова частина (копійки) при виводі на екран повинна бути відділена від цілої частини коми. Реалізувати додавання, віднімання, ділення сум, ділення суми на дробове число, множення на дробове число й операції порівняння. Перевантажити 3-4 операції.*/

#include <string>

class money
{
private:
    long grn;   // Гривні
    unsigned char kop;   // Копійки

public:

    money();   // за замовчуванням
    money(long startGrn, unsigned char startKop);   // з параметрами
    money(const money& other);   // копіювання
    ~money();   // деструктор

    void Init(long startGrn, unsigned char startKop);
    void Read();
    std::string toString() const;
    void Display() const;
    // Перевантажені операції
    money operator+(const money& other) const;
    money operator-(const money& other) const;
    bool operator==(const money& other) const;
    bool operator>(const money& other) const;

    double Divide(const money& other) const;
    money DivideByNumber(double number) const;
    money MultiplyByNumber(double number) const;
};