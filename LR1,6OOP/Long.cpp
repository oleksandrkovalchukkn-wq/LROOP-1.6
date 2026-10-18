#include "Long.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>

using namespace std;

// =========================================================
// РЕАЛІЗАЦІЯ МЕТОДІВ ВКЛАДЕНОГО КЛАСУ Long::Pair
// =========================================================

bool Long::Pair::setFirst(int value) {
    first = value;
    return true;
}

bool Long::Pair::setSecond(int value) {
    second = value;
    return true;
}

bool Long::Pair::Init(int a, int b) {
    return setFirst(a) && setSecond(b);
}

void Long::Pair::Read() {
    int a, b;
    do {
        cout << "  Введіть перше число (first): ";
        cin >> a;
        cout << "  Введіть друге число (second): ";
        cin >> b;
    } while (!Init(a, b));
}

string Long::Pair::toString() const {
    stringstream sout;
    sout << "(" << first << ", " << second << ")";
    return sout.str();
}

void Long::Pair::Display() const {
    cout << toString() << endl;
}

Long::Pair Long::Pair::add(const Pair& other) const {
    Pair result;
    result.Init(this->first + other.first, this->second + other.second);
    return result;
}

// =========================================================
// РЕАЛІЗАЦІЯ МЕТОДІВ ЗОВНІШНЬОГО КЛАСУ Long
// =========================================================

long long Long::toValue() const {
    long long sign = (pair.getFirst() < 0) ? -1 : 1;
    return static_cast<long long>(pair.getFirst()) * BASE + sign * pair.getSecond();
}

void Long::fromValue(long long val) {
    int high = static_cast<int>(val / BASE);
    int low = static_cast<int>(std::abs(val % BASE));
    pair.Init(high, low);
}

bool Long::setHigh(int high) {
    return pair.setFirst(high);
}

bool Long::setLow(int low) {
    if (low >= 0 && low < BASE) {
        return pair.setSecond(low);
    }
    return false;
}

bool Long::setPair(Long::Pair p) {
    return Init(p.getFirst(), p.getSecond());
}

bool Long::Init(int high, int low) {
    return setHigh(high) && setLow(low);
}

bool Long::Init(Long::Pair p) {
    return Init(p.getFirst(), p.getSecond());
}

void Long::Read() {
    int h, l;
    do {
        cout << "  Введіть старшу частину (тисячі): ";
        cin >> h;
        cout << "  Введіть молодшу частину (від 0 до 999): ";
        cin >> l;
        if (l < 0 || l >= BASE) {
            cout << "  [Помилка!] Молодша частина має бути від 0 до 999. Спробуйте ще раз.\n";
        }
    } while (!Init(h, l));
}

string Long::toString() const {
    stringstream sout;
    sout << toValue() << " [Старша: " << pair.getFirst()
        << ", Молодша: " << setw(3) << setfill('0') << pair.getSecond() << "]";
    return sout.str();
}

void Long::Display() const {
    cout << toString() << endl;
}

Long Long::add(const Long& other) const {
    Long result;
    if (this->getHigh() >= 0 && other.getHigh() >= 0) {
        Pair rawSum = this->pair.add(other.pair); // Делегування вкладеному класу
        int carry = rawSum.getSecond() / BASE;
        int newHigh = rawSum.getFirst() + carry;
        int newLow = rawSum.getSecond() % BASE;
        result.Init(newHigh, newLow);
    }
    else {
        result.fromValue(this->toValue() + other.toValue());
    }
    return result;
}

Long Long::sub(const Long& other) const {
    Long result;
    result.fromValue(this->toValue() - other.toValue());
    return result;
}

Long Long::mul(const Long& other) const {
    Long result;
    result.fromValue(this->toValue() * other.toValue());
    return result;
}