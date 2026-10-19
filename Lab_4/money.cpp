#include "money.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
using namespace std;
// Конструктор за замовчуванням
money::money()
{
    this->grn = 0;
    this->kop = 0;
}
// Конструктор з параметрами
money::money(long startGrn, unsigned char startKop)
{
    this->grn = startGrn;
    this->kop = startKop;
    if (this->kop >= 100) {   // нормалізація копійок
        this->grn += this->kop / 100;
        this->kop = this->kop % 100;
    }
}
// Конструктор копіювання
money::money(const money& other)
{
    this->grn = other.grn;
    this->kop = other.kop;
}
// Деструктор
money::~money()
{
}

void money::Init(long startGrn, unsigned char startKop)
{
    grn = startGrn;
    kop = startKop;
}

void money::Read()
{
    long tempGrn;
    int tempKop;

    cout << "Введіть гривні: ";
    cin >> tempGrn;

    cout << "Введіть копійки: ";
    cin >> tempKop;

    grn = tempGrn;
    kop = (unsigned char)(abs(tempKop) % 100);
}

string money::toString() const
{
    stringstream ss;

    if (grn < 0) {
        ss << "-" << -grn << "," << setw(2) << setfill('0') << (int)kop << " грн";
    }
    else {
        ss << grn << "," << setw(2) << setfill('0') << (int)kop << " грн";
    }

    return ss.str();
}

void money::Display() const
{
    cout << toString() << endl;
}
// Перевантаження оператора + (додавання сум)
money money::operator+(const money& other) const
{
    long k1 = grn * 100 + (grn >= 0 ? kop : -kop);
    long k2 = other.grn * 100 + (other.grn >= 0 ? other.kop : -other.kop);
    long sumKop = k1 + k2;

    long resGrn = sumKop / 100;
    int resKop = sumKop % 100;
    if (resKop < 0) resKop = -resKop;

    return money(resGrn, (unsigned char)resKop);
}
// Перевантаження оператора - (віднімання сум)
money money::operator-(const money& other) const
{
    long k1 = grn * 100 + (grn >= 0 ? kop : -kop);
    long k2 = other.grn * 100 + (other.grn >= 0 ? other.kop : -other.kop);
    long diffKop = k1 - k2;

    long resGrn = diffKop / 100;
    int resKop = diffKop % 100;
    if (resKop < 0) resKop = -resKop;

    return money(resGrn, (unsigned char)resKop);
}
// Ділення суми на суму
double money::Divide(const money& other) const
{
    double first = grn + (grn >= 0 ? (double)kop / 100.0 : -(double)kop / 100.0);
    double second = other.grn + (other.grn >= 0 ? (double)other.kop / 100.0 : -(double)other.kop / 100.0);

    if (second == 0.0) return 0.0;
    return first / second;
}
// Ділення суми на число
money money::DivideByNumber(double number) const
{
    if (number == 0.0) return money(0, 0);

    double current = grn + (grn >= 0 ? (double)kop / 100.0 : -(double)kop / 100.0);
    double value = current / number;
    long totalKop = (long)(value * 100.0 + (value >= 0 ? 0.5 : -0.5));

    long resGrn = totalKop / 100;
    int resKop = totalKop % 100;
    if (resKop < 0) resKop = -resKop;

    return money(resGrn, (unsigned char)resKop);
}
// Множення суми на число
money money::MultiplyByNumber(double number) const
{
    double current = grn + (grn >= 0 ? (double)kop / 100.0 : -(double)kop / 100.0);
    double value = current * number;
    long totalKop = (long)(value * 100.0 + (value >= 0 ? 0.5 : -0.5));

    long resGrn = totalKop / 100;
    int resKop = totalKop % 100;
    if (resKop < 0) resKop = -resKop;

    return money(resGrn, (unsigned char)resKop);
}
// Перевантаження оператора == (порівняння на рівність)
bool money::operator==(const money& other) const
{
    long k1 = grn * 100 + (grn >= 0 ? kop : -kop);
    long k2 = other.grn * 100 + (other.grn >= 0 ? other.kop : -other.kop);
    return k1 == k2;
}
// Перевантаження оператора > (перша сума більша за другу)
bool money::operator>(const money& other) const
{
    long k1 = grn * 100 + (grn >= 0 ? kop : -kop);
    long k2 = other.grn * 100 + (other.grn >= 0 ? other.kop : -other.kop);
    return k1 > k2;
}