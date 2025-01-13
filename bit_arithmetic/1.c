//Вывести на экран младший бит числа а

#include <stdio.h>

int main () {
 int a, k;

 printf ("dведите число для выявления младшего бита:\n");
 scanf("%d", &a);

 k = a & 1;
 printf("%d\n", k); 

 return 0;
}