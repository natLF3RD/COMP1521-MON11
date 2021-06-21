#include <stdio.h>

int main(void) {
    int x;
    printf("Enter a number: ");
    scanf("%d", &x);

    char *message = "small/big\n";
if_q3:
    if (x > 100 && x < 1000) {
    # check first condition
    # x <= 100 then we want to jump
    li $t1, 100
    ble $t0, $t1, endif_q3
    # check second condition
    # x >= 1000
    li $t1, 1000
    bge $t0, $t1, endif_q3
    
    # ALT
    
    if (x > 100 || x < 1000) {
    # check first condition
    # x > 100 then we want to jump to inside if
    li $t1, 100
    bgt $t0, $t1, inner_if_q3
    # x  >= 1000 jump past if statement
    li $t1, 1000
    bge $t0, $t1, endif_q3 
    
    
inner_if_q3:
    
    
    
    # then check the second (sometimes)
        message = "medium";
    }
endif_q3:

    printf("%s", message);
}