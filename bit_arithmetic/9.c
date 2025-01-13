//Задание 9. Дано 2^р разрядное число. "Покросить" все биты этого числа друг с другом. Например 101110001 -> 1;   11100111 -> 0

#include <stdio.h> 

int main() { 
int a; 
printf("Enter value:"); 
scanf("%d", &a); 

int res = a; 
int bit1; 
int bit2; 
int resxor; 
while ((res != 0) && (res != 1)){ 
    bit1 = res & 1; 
    bit2 = (res >> 1) & 1; 
    resxor = bit1 ^ bit2; 
    res = res >> 2; 
    res = (res << 1) + resxor; 
} 
printf("%d", res); 

return 0; 
}
