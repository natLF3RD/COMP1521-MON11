.text
main:
# int main() {
   # int i = 0;
    move $t0, $0

do:
   # do {
   #     i++;
    addi $t0, $t0, 1


  # printf("%d", i);
  li $v0, 1
  move $a0, $t0
  syscall

  # printf("\n");
  li $v0, 11
  li $a0, '\n'
  syscall

do_while:
    #} while (i<10);
    # -> if (i<10) goto do;
    blt $t0 10 do,
    # go here once we fail

main_epilogue:
    # return 0;
    li $v0, 0
    jr $ra
# }

.data 
