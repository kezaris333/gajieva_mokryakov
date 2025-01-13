//Номер 2. Вывести на экран k-ый бит числа а

#include <stdio.h>

int main() {
 int a, k, c;

 printf("Введите число: ");
 scanf("%d", &a);

 printf("Введите номер бита: ");
 scanf("%d", &k);

 c = (a >> k) & 1;
 printf("%d\n", c);

 return 0;
}