.globl f
f:
addi sp,sp,-16
sw ra,12(sp)
sw s0,12(sp)
addi s0,sp,16
call g
mv t0, a0
j .end1
.end1:
lw ra,12(sp)
mv a0,t0
lw s0,12(sp)
addi sp,sp,16
jr ra
