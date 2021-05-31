#include <stdlib.h>

int main () {
    int  x;  // a variable located at address 1000 with initial value 0
    int *p;  // a variable located at address 2000 with initial value 0
    

    p = &x;         // a

    x = 5;          // b

    *p = 3;         // c

    x = (int)p;     // d

    x = (int)&p;    // e

    p = NULL;       // f

    *p = 1;         // g

}