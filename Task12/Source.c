#include <stdio.h>
#include <locale.h>
#define MY_SIZE(type) ((size_t)((char*)((type*)0 + 1) - (char*)((type*)0)))

int mainz1() {
    // Объявляем указатели на разные типы
    char* pc;
    int* pi;
    double* pd;

    printf("Размер указателя на char:   %lu байт\n", sizeof(pc));
    printf("Размер указателя на int:    %lu байт\n", sizeof(pi));
    printf("Размер указателя на double: %lu байт\n", sizeof(pd));

    // Проверка размера самих типов данных
    printf("\nРазмер типа char:   %lu байт\n", sizeof(char));
    printf("Размер типа int:    %lu байт\n", sizeof(int));
    printf("Размер типа double: %lu байт\n", sizeof(double));

    return 0;
}
int mainz2() {
    float PI = 3.14159, * p1, * p2;
    p1 = p2 = &PI;
    printf("По адресу p1=%p хранится *p1=%g\n", p1, *p1);
    printf("По адресу p2=%p хранится *p2=%g\n", p2, *p2);
}

int mainz3() {
    // 1. Исследование int
    int x = 5;
    int* pa = &x;
    printf("--- int (размер %lu байт) ---\n", sizeof(int));
    printf("До инкремента: адрес = %p\n", (void*)pa);
    pa++;
    printf("После ++:      адрес = %p (смещение: %lu байт)\n", (void*)pa, sizeof(int));

    // 2. Исследование double
    double d = 3.14;
    double* pd = &d;
    printf("\n--- double (размер %lu байт) ---\n", sizeof(double));
    printf("До инкремента: адрес = %p\n", (void*)pd);
    pd++;
    printf("После ++:      адрес = %p (смещение: %lu байт)\n", (void*)pd, sizeof(double));

    // 3. Исследование char
    char c = 'A';
    char* pc = &c;
    printf("\n--- char (размер %lu байт) ---\n", sizeof(char));
    printf("До инкремента: адрес = %p\n", (void*)pc);
    pc++;
    printf("После ++:      адрес = %p (смещение: %lu байт)\n", (void*)pc, sizeof(char));

    return 0;
}

int mainz4() {
    float array[10] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.0 };
    float* ptr_a;

    // 4.1 Имя массива - это адрес его первого элемента
    printf("4.1 Проверка адресов:\n");
    printf("array     = %p\n", (void*)array);
    printf("&array[0] = %p\n", (void*)&array[0]);
    printf("&array    = %p\n", (void*)&array); // Адрес всего массива (совпадает по значению, но имеет другой тип)

    // 4.2 Установка указателя на начало и операции
    printf("\n4.2 Операции с указателем:\n");
    ptr_a = array; // Указывает на array[0]
    printf("Исходный: ptr_a = %p, *ptr_a = %.1f\n", (void*)ptr_a, *ptr_a);

    ptr_a++;
    printf("ptr_a++:  ptr_a = %p, *ptr_a = %.1f\n", (void*)ptr_a, *ptr_a); // Сдвиг на array[1]

    printf("ptr_a+4:  адрес  = %p\n", (void*)(ptr_a + 4)); // Сдвиг на 4 элемента от текущего
    printf("ptr_a-2:  адрес  = %p\n", (void*)(ptr_a - 2)); // Сдвиг назад на 2 элемента

    // 4.3 Проход по массиву с шагом 2
    printf("\n4.3 Проход с шагом 2:\n");
    for (ptr_a = array; ptr_a < array + 10; ptr_a += 2) {
        printf("%.1f ", *ptr_a);
    }
    printf("\n");

    // 4.4 Проход в обратном порядке
    printf("\n4.4 Обратный проход:\n");
    // Устанавливаем указатель на последний элемент (array[9])
    ptr_a = array + 9;
    for (int i = 0; i < 10; i++) {
        printf("%.1f ", *ptr_a);
        ptr_a--; // Декремент
    }
    printf("\n");

    return 0;
}

void print_bytes(void* ptr, size_t size) {
    // Приводим указатель к указателю на байт
    unsigned char* byte_ptr = (unsigned char*)ptr;

    // Выводим байты в порядке их физического расположения в памяти
    for (size_t i = 0; i < size; i++) {
        printf("%02x ", byte_ptr[i]);
    }
    printf("\n");
}

int mainz5() {
    printf("=== 5.1 Определение порядка байтов (Endianness) ===\n");
    int x = 0x12345678; // Переменная из примера на фото
    unsigned char* a = (unsigned char*)&x;

    printf("Число int: 0x12345678\n");
    printf("Байты в памяти: %02x %02x %02x %02x\n", a[0], a[1], a[2], a[3]);

    if (a[0] == 0x78) {
        printf("Вывод: Система использует Little-endian (младший байт в начале).\n");
    }
    else {
        printf("Вывод: Система использует Big-endian.\n");
    }

    printf("\n=== 5.2 Универсальный побайтовый вывод ===\n");
    float f = 3.14f;
    double d = 3.14;

    printf("int 5:        "); print_bytes(&x, sizeof(x));
    printf("float 3.14:   "); print_bytes(&f, sizeof(f));
    printf("double 3.14:  "); print_bytes(&d, sizeof(d));

    printf("\n=== 5.3 Сравнение кода числа 12345.0 ===\n");
    int int_val = 12345;
    float float_val = 12345.0f;
    double double_val = 12345.0;

    printf("int 12345:    "); print_bytes(&int_val, sizeof(int_val));
    printf("float 12345:  "); print_bytes(&float_val, sizeof(float_val));
    printf("double 12345: "); print_bytes(&double_val, sizeof(double_val));

    return 0;
}

int mainz6() {
    printf("Размеры типов данных (без sizeof):\n");
    printf("1) char:              %lu\n", MY_SIZE(char));
    printf("2) short int:         %lu\n", MY_SIZE(short int));
    printf("3) unsigned short int:%lu\n", MY_SIZE(unsigned short int));
    printf("4) int:               %lu\n", MY_SIZE(int));
    printf("5) unsigned char:     %lu\n", MY_SIZE(unsigned char));
    printf("6) wchar_t:           %lu\n", MY_SIZE(wchar_t));
    printf("7) long long int:     %lu\n", MY_SIZE(long long int));
    printf("8) size_t:            %lu\n", MY_SIZE(size_t));
    printf("9) float:             %lu\n", MY_SIZE(float));
    printf("10) double:           %lu\n", MY_SIZE(double));
    printf("11) signed int:       %lu\n", MY_SIZE(signed int));

    return 0;
}

int main() {
    setlocale(LC_ALL, "RUS");
    mainz1();
    mainz2();
    mainz3();
    mainz5();
    mainz6();

    return 0;
}