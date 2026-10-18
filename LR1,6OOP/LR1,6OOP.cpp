#include <iostream>
#include <Windows.h>
#include "Long.h"

using namespace std;

void printMenu() {
    cout << "\n======================================================\n";
    cout << "      ЛАБОРАТОРНА 1.6: ВКЛАДЕНІ КЛАСИ (Long::Pair)    \n";
    cout << "======================================================\n";
    cout << "1. Показати поточне число Long А\n";
    cout << "2. Ввести нове число Long А з клавіатури\n";
    cout << "3. ДОДАТИ два числа (Long A + Long B) vs Long::Pair::add\n";
    cout << "4. ВІДНЯТИ два числа (Long A - Long B)\n";
    cout << "5. ПОМНОЖИТИ два числа (Long A * Long B)\n";
    cout << "6. Продемонструвати роботу з масивом об'єктів\n";
    cout << "0. Вихід\n";
    cout << "======================================================\n";
    cout << "Оберіть дію: ";
}

int main() {
    // Якщо в консолі ієрогліфи, зміни 1251 на 65001
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Long numA;
    numA.Init(2, 650); // Стартове число: 2650

    int choice;
    do {
        printMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\n---> Число А: ";
            numA.Display();
            break;

        case 2:
            cout << "\n---> Введення числа А:\n";
            numA.Read();
            cout << "Оновлено!\n";
            break;

        case 3: {
            Long numB;
            cout << "\n---> Введіть друге число В для додавання:\n";
            numB.Read();

            // Виклик методу вкладеного класу Long::Pair
            Long::Pair simplePairSum = numA.getPair().add(numB.getPair());
            Long longSum = numA.add(numB);

            cout << "\nДодавання через вкладений Long::Pair::add: " << simplePairSum.toString() << endl;
            cout << "Перевизначене додавання Long::add:         " << longSum.toString() << endl;
            break;
        }

        case 4: {
            Long numB;
            cout << "\n---> Введіть друге число В для віднімання:\n";
            numB.Read();
            Long diff = numA.sub(numB);
            cout << "\nРезультат (А - В): ";
            diff.Display();
            break;
        }

        case 5: {
            Long numB;
            cout << "\n---> Введіть друге число В для множення:\n";
            numB.Read();
            Long prod = numA.mul(numB);
            cout << "\nРезультат (А * В): ";
            prod.Display();
            break;
        }

        case 6: {
            cout << "\n---> Масив об'єктів класу Long:\n";
            Long arr[3];
            arr[0].Init(1, 500);
            arr[1].Init(3, 250);
            arr[2] = arr[0].add(arr[1]);

            for (int i = 0; i < 3; ++i) {
                cout << "Елемент [" << i << "]: " << arr[i].toString() << endl;
            }
            break;
        }

        case 0:
            cout << "Вихід...\n";
            break;

        default:
            cout << "Невірний вибір!\n";
        }
    } while (choice != 0);

    return 0;
}