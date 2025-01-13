//заменa местами байтов в заданном 32-разрядном целом числе

#include <stdio.h>

unsigned int swap_bytes(unsigned int num, int order[4]) {
    unsigned int result = 0;
    for (int i = 0; i < 4; i++) {
        result |= ((num >> (order[i] * 8)) & 0xFF) << (i * 8);
    }
    return result;
}

int main() {
    unsigned int num;
    int order[4];

    printf("Введите 32-разрядное целое число (в десятичной системе): ");
    scanf("%u", &num);

    printf("Введите порядок перестановки байтов (4 числа от 0 до 3): ");
    for (int i = 0; i < 4; i++) {
        scanf("%d", &order[i]);
    }

    unsigned int swapped_num = swap_bytes(num, order);
    printf("Переставленное число: %u\n", swapped_num);

    return 0;
}