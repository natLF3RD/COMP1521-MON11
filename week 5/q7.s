.text
main:

    li $t0, 0

while:
    bge $t0, 10, endwhile
    
    li $v0, 5
    syscall
    # now, v0 contains loaded value

    mul $t1, $t0, 4
    sw $v0, numbers($t1) # %address of index%

    addi $t0, $t0, 1
    j while

endwhile:

main_epilogue:
    li $v0, 0
    jr $ra

.data

# we are initialising this time, so dont want to use .space
numbers: .word 0, 0, 0, 0, 0, 0, 0, 0, 0, 0

# eg for q8
# numbers: .word 0, 1, 2, 3, 4, 5, 6, 7, 8, 9

