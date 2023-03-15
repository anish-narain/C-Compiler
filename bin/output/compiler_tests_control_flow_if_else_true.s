.globl f
f:
addi sp,sp,-16
sw s0,12(sp)
addi s0,sp,16
li t0,1
li t0,11
mv a0,t0
lw s0,12(sp)
addi sp,sp,16
jr ra
