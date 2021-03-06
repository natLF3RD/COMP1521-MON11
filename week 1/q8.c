#include <stdio.h>

int main(void) {
    int n[4] = { 42, 23, 11, 7 }; // 42 now 43
    int *p;

    p = &n[0]; //  n[0]gets the value at n's address offset by 0 
    printf("%p\n", p); // prints 0x7fff00000000
    printf("%lu\n", sizeof (int)); // prints 4

    // what do these statements print ?
    n[0]++;
    printf("%d\n", *p);
    p++;
    printf("%p\n", p);
    printf("%d\n", *p);

    return 0;
}


// Assuming sizeof (int) == 4, what does the above print? //