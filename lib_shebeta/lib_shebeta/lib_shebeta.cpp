#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>

class ShebetaNI_String {
private:
    char* str = nullptr;  // Указатель на массив символов, который будет хранит строку
    size_t sz = 0;        // Переменная для отслеживания длины строки

public:
    // Конструкторы

    // 1. Конструктор по умолчанию
    ShebetaNI_String() : str(nullptr), sz(0) {}

    // 2. Конструктор с параметрами
    ShebetaNI_String(const char* string) {
        sz = strlen(string);
        str = new char[sz + 1]; // +1 для символа '\0
        strcpy_s(str, sz + 1, string);
    }

    // 3. Конструктор копирования
    ShebetaNI_String(const ShebetaNI_String& other) {
        sz = other.sz;
        str = new char[sz + 1]; // +1 для символа '\0'
        strcpy_s(str, sz + 1, other.str);
    }

    // 4. Деструктор
    ~ShebetaNI_String() {
        delete[] str;
    }

    // Методы класса ShebetaNI

    // 1. Возвращает длину строки
    size_t lenght() const {
        return sz;
    }

    // 2. Перегруженный оператор доступа к элементу строки по индексу
    char& operator[](size_t index) {
        return str[index];
    }

    // 3. Перегруженный оператор доступа к элементу строки 
    // по индексу для константных объектов.
    const char& operator[](size_t index) const {
        return str[index];
    }

    // 4. Добавляет содержимое переданной строки в конец текущей строки.
    void append(const ShebetaNI_String& string) {
        char* tmp = new char[sz + string.sz + 1];
        strcpy_s(tmp, sz + 1, str);
        strcpy_s(tmp + sz, string.sz + 1, string.str);

        delete[] str;
        str = tmp;
        sz += string.sz;
    }

    // 5 Возвращает подстроку, начиная с позиции start и содержащую count символов
    ShebetaNI_String substr(size_t start, size_t count) const {
        ShebetaNI_String result;
        if (start >= sz) {
            return str;
        }
        else {
            result.sz = std::min(count, sz - start);
            result.str = new char[result.sz + 1];
            strncpy_s(result.str, result.sz + 1,
                str + start, result.sz);
            return result;
        }
    }

    // Операторы
    // 1. Оператор присваивания (=)
    ShebetaNI_String& operator=(const ShebetaNI_String& other) {
        if (this != &other) {
            delete[] str;

            sz = other.sz;
            str = new char[sz + 1]; // +1 для символа '\0'
            strcpy_s(str, sz + 1, other.str);
        }
        return *this;
    }

    // 2. Оператор конкатенации (+)
    ShebetaNI_String operator+(const ShebetaNI_String& other) {
        ShebetaNI_String result = *this;
        result.append(other);
        return result;
    }

    // 3. Операторы сравнения
    bool operator==(const ShebetaNI_String& other) const {
        if (sz != other.sz) {
            return false;
        }
        return strcmp(str, other.str) == 0;
    }

    bool operator!=(const ShebetaNI_String& other) const {
        return !(*this == other);
    }

    bool operator<(const ShebetaNI_String& other) const {
        return strcmp(str, other.str) < 0;
    }

    bool operator>(const ShebetaNI_String& other) const {
        return strcmp(str, other.str) > 0;
    }

    bool operator<=(const ShebetaNI_String& other) const {
        return strcmp(str, other.str) <= 0;
    }

    bool operator>=(const ShebetaNI_String& other) const {
        return strcmp(str, other.str) >= 0;
    }

    // 4. Оператор ввода / вывода

    std::istream& operator >> (std::istream& is, ShebetaNI_String& string) {
        std::vector<char> buffer;
        char ch;
        while (is.get(ch) && !isspace(ch)) { // считываем символы пока не встретим пробел или конец файла
            buffer.push_back(ch);
        }
        buffer.push_back('\0'); // добавляем нулевой символ в конец строки

        int length = buffer.size();
        string.sz = length - 1;
        string.str = new char[length];
        strcpy(string.str, buffer.data());

        return is;
    }

    std::ostream& operator << (std::ostream& os, const ShebetaNI_String& string) {
        os << string.str;
        return os;
    }
};
