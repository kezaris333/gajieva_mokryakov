//Номер 4. Снять (обнулить) k-ый бит числа a

#include <stdio.h>

int main() {
 unsigned int a;
 int k, value;

printf("введите число: ");
 scanf("%d", &a);

// цикл для ввода номера бита
do {
 printf("введите номер бита (от 0 до 7): ");
 scanf("%d", &k);
 if (k >= 8 || k < 0) {
    printf("неверное значение, введите число от 0 до 7\n");
 }
 } 
 while (k >= 8 || k < 0); // продолжать, пока введено неверное значение

 value = (a & ~ (1<<k)); // снятие k-го бита

 printf("%d\n", value); // вывод результата

 return 0;
}