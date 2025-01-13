//Задача 11А. Склеить первые i  и последние j битов числа num


#include <stdio.h>
unsigned int combine_bits(unsigned int num, int len, int i) {
    // Получаем первые i битов
    unsigned int first_i_bits = (num >> (len - i));
    
    // Получаем последние i битов
    unsigned int last_i_bits = num & ((1U << i) - 1);
    
    // Склеиваем их
    return (first_i_bits << i) | last_i_bits;
}

int main() {
    unsigned int num;
    int len, i;

    printf("Введите число (в десятичном формате): ");
    scanf("%u", &num);
    
    printf("Введите длину числа в битах: ");
    scanf("%d", &len);
    
    printf("Введите количество битов для склеивания (i): ");
    scanf("%d", &i);

    if (i > len) {
        printf("Ошибка: i не может быть больше длины числа.\n");
        return 1;
    }

    unsigned int result = combine_bits(num, len, i);
    printf("Результат склеивания: %u\n", result);

    return 0;
}