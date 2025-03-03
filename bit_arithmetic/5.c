//Номер 5. Поменять i и j биты местами в числе а

#include <stdio.h>

int main() {
    int a, i, j, bit_i, bit_j;

    printf("введите число: ");
    scanf("%d", &a);

    printf("введите номер бита 1 (от 0 до 7): ");
    scanf("%d", &i);

    printf("введите номер бита 2 (от 0 до 7): ");
    scanf("%d", &j);

    bit_i = (a >> i) & 1;
    bit_j = (a >> j) & 1;

    if (bit_i != bit_j) {
        if (bit_i == 1) {
            a &= ~(1 << i); // сброс бита i
        } else {
            a |= (1 << i); // установка бита i
        }

        if (bit_j == 1) {
            a &= ~(1 << j); // сброс бита j
        } else {
            a |= (1 << j); // установка бита j
        }
        printf("биты не равны, %d\n", a);
    } else {
        printf("биты равны, %d\n", a);
    }
    return 0;
}
