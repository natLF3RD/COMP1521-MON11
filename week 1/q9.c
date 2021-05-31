#include <stdlib.h>

int main () {
    int  x;  // a variable located at address 1000 with initial value 0
    int *p;  // a variable located at address 2000 with initial value 0
    

    p = &x;         // a
    // x = 0
    // p = 1000

    x = 5;          // b
    // x = 5 
    // p = 1000
    // *p = 5

    *p = 3;         // c
    // x = 3
    // p = 1000

    x = (int)p;     // d
    // x = 1000
    // p = 1000

    x = (int)&p;    // e
    // x = 2000

    p = NULL;       // f
    // x unchanged
    // p == NULL;

    *p = 1;         // g
    // error !

}