
// задание 10. написать макросы циклического сдвига в 2^p разрядном целом числе на n  бит вправо и влево

#include <stdio.h>

#define RIGHT (x, len, n); \
    int y = x >> n; \
    int z = x << (len - n); \
    int mask = (1 << (len+1))- 1; \
    z = mask & z; \
    int result_right = y | z; \
    printf ("%d", result_right);
    
// спросить по поводу  && ||
    
#define LEFT (x, len, n); \
    y = (x << n); \
    z = (x >> (len - n)); \
    mask = ((1 << (len))- 1); \
    y = (mask & y); \
    int result_left = (y | z); \
    printf ("%d", result_left);
    
int main (){ 
    int x, len, n;
    char direction;
    
    printf ("\nВведите число:\n");
    scanf ("%d", &x);
    
    printf ("\nВведите длину двоичного числа:\n");
    scanf ("%d", &len);
    
    printf ("\nВведите количество сдвигов числа:\n");
    scanf ("%d", &n);
    
    printf ("\nСдвинуть вправо или влево? Введите r (right) или l (left):\n");
    scanf (" %c", &direction);
    
// cпросить почему перед %с пробел
    
    switch (direction) {
        case 'r':
        RIGHT (x, len, n);
        break;
        
        case 'l':
        LEFT (x,len, n);
        break;
        
        default:
        printf ("Error!!!>:(");
        break;
    }
    return 0;
}