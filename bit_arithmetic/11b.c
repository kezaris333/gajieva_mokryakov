//поолучить биты из целого числа длиной len битов, находящиеся меджу первыми i битами и последними  j битами 

#include <stdio.h>
unsigned int get_middle_bits(unsigned int num, int len, int i) {
    
    // Сдвигаем число, чтобы удалить первые i и последние i битов
    unsigned int middle_bits = (num >> i) & ~(((1U << (len - 2 * i)) - 1) | ((1U << i) - 1));
    
    return middle_bits;
}

int main() {
    unsigned int num;
    int len, i;

    printf("Введите число (в десятичном формате): ");
    scanf("%u", &num);
    
    printf("Введите длину числа в битах: ");
    scanf("%d", &len);
    
    printf("Введите количество битов (i): ");
    scanf("%d", &i);

    if (i > len / 2) {
        printf("Ошибка: i не может быть больше половины длины числа.\n");
        return 1;
    }

    unsigned int result = get_middle_bits(num, len, i);
    printf("Биты между первыми и последними i битами: %u\n", result);

    return 0;
}