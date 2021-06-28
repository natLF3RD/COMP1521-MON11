.text
main:

    li $t0, 0

while:
    bge $t0, 10, endwhile
    
    li $v0, 1
    # something in a0?
    mul $t1, $t0, 4
    lw $a0, numbers($t1) # %address of index%
    syscall

    li $v0, 11
    li $a0, '\n'
    syscall

    addi $t0, $t0, 1
    j while

endwhile:

main_epilogue:
    li $v0, 0
    jr $ra

.data
numbers: .word 0, 1, 2, 3, 4, 5, 6, 7, 8, 9

