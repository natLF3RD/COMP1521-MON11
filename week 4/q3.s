# include <stdio.h>

.text
main:
# int main(void) {
    #int x, y;
    # x->t0, y->t0
    #printf("Enter a number: ");
    li  $v0, 4
    la  $a0, prompt
    syscall
    
    #scanf("%d", &x);
    li $v0, 5
    syscall
    # where is our result?  $v0
    move $t0, $v0 # x=result

if_q2:
    
    # if (x > 46340) {
    # opposite: (x <= 4630)
    li $t3, 46340
    ble $t0, $t3, else_q2
    #    printf("square too big for 32 bits\n");
    li  $v0, 4
    la  $a0, error
    syscall
    
    j endif_q2
    

else_q2:
    # } else {
        #
    #     y = x * x;
    mul $t1, $t0, $t0
    
#     printf("%d", y);
    li $v0, 1
    move $a0, $t1
    syscall
#     printf("\n");
    li $v0, 11
    li $a0, '\n'
    syscall
    # }
endif_q2:

    # return 0;
    li  $v0, 0
    jr  $ra
# }

.data
prompt:
    .asciiz  "Enter a number: "
error: 
    .asciiz "square too big for 32 bits\n"