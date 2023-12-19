#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "..\lib_shebeta\Header.h"

using namespace std;


void operation() {
    cout << "1. ---------" << endl;
    cout << "2. задание 2" << endl;
    cout << "3. задание 3" << endl;
    cout << "4. задание 4" << endl;
    cout << endl;
}

void problem2() {
    /*  Задание 2, вариант 9
        Текстовый файл состоит из символов. Текст разбит на строки различной длины.
        Вывести в файл все слова, предварительно преобразовав каждое из них по
        следующему правилу: из каждого слова нечетной длины удалить его среднюю букву.
    */
    ifstream cinFile("inputProblem2.txt");
    ofstream coutFile("outputProblem2.txt");

    ShebetaNI_String word, tmp;
    while (cinFile.is_open()) {
        cinFile >> tmp;

        cout << tmp.lenght() << endl;
        if (tmp.lenght() % 2 != 0) {
            word = tmp.substr(23, 2);

            cout << word << " ";
            coutFile << word << " ";
        }
        else {
            cout << tmp << " ";
            coutFile << tmp << " ";
        }
        if (cinFile.eof()) {
            break;
        }
    }

    cinFile.close();
    coutFile.close();
    cout << endl;
    cout << endl;
}

void problem3() {
    /*  Задание 3, вариант 10

    */
}

void problem4() {
    ShebetaNI_String word = "asda";
    cout << word;
    cout << endl;
    cout << word.lenght();
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    bool flag = true;
    int problem;
    while (flag) {
        operation();

        cin >> problem;
        cout << endl;

        switch (problem)
        {
        case(2):
            problem2();
            break;
        case(3):
            problem3();
            break;
        case(4):
            problem4();
            break;
        }
    }

    return 0;
}