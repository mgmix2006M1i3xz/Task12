Домашнее задание к работе номер 12

Условие задачи:
Напишите программу, которая вычисляет размер основных типов данных в байтах без использования оператора sizeof и без констант из библиотек limits.h и float.h.

Необходимо определить размер следующих типов:

1.char
2.short int
3.unsigned short int
4.int
5.unsigned char
6.wchar_t
7.long long int
8.size_t
9.float
10.double
11.signed int

Указание: Для вычисления размера используйте арифметику указателей. Например, разность адресов (char*)((type*)0 + 1) - (char*)((type*)0) даст точный размер типа в байтах.

1. Алгоритм и блок-схема

Алгоритм:

Начало.
Создать макрос MY_SIZE(type), использующий арифметику указателей: (char*)((type*)0 + 1) - (char*)((type*)0).
Вывести с помощью макроса размеры типов: char, short int, unsigned short int, int, unsigned char, wchar_t, long long int, size_t, float, double, signed int.
Конец.

Блок-схема:

<img width="286" height="608" alt="image" src="https://github.com/user-attachments/assets/90243162-8b5c-42ed-b133-528b938726e4" />

2. Реализация программы

#include <stdio.h>

// Макрос для вычисления размера типа без sizeof()
// Берем указатель на 0, прибавляем 1 (сдвиг на размер типа),
// приводим к char* и вычитаем начальный адрес.
#define MY_SIZE(type) ((size_t)((char*)((type*)0 + 1) - (char*)((type*)0)))

int main() {
    printf("Размеры типов данных (без sizeof):\n");
    printf("1) char:               %lu\n", MY_SIZE(char));
    printf("2) short int:          %lu\n", MY_SIZE(short int));
    printf("3) unsigned short int: %lu\n", MY_SIZE(unsigned short int));
    printf("4) int:                %lu\n", MY_SIZE(int));
    printf("5) unsigned char:      %lu\n", MY_SIZE(unsigned char));
    printf("6) wchar_t:            %lu\n", MY_SIZE(wchar_t));
    printf("7) long long int:      %lu\n", MY_SIZE(long long int));
    printf("8) size_t:             %lu\n", MY_SIZE(size_t));
    printf("9) float:              %lu\n", MY_SIZE(float));
    printf("10) double:            %lu\n", MY_SIZE(double));
    printf("11) signed int:        %lu\n", MY_SIZE(signed int));

    return 0;
}

3. Результаты работы программы

text
Размеры типов данных (без sizeof):
1) char:               1
2) short int:          2
3) unsigned short int: 2
4) int:                4
5) unsigned char:      1
6) wchar_t:            4
7) long long int:      8
8) size_t:             8
9) float:              4
10) double:            8
11) signed int:        4

4. Информация о разработчике
Митин Михаил Александрович, бТИИ-261
