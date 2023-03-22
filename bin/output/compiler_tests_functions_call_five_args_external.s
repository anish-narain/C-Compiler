sw a0, -20(s0)
sw a1, -24(s0)
sw a2, -28(s0)
sw a3, -32(s0)
sw a4, -36(s0)
.globl f
f:
addi sp,sp,-16
sw ra,12(sp)
sw s0,12(sp)
addi s0,sp,16
li t0,1
li t0,2
li t0,3
li t0,4
li t0,5
call g
mv t0, a0
j .end1
.end1:
lw ra,12(sp)
mv a0,t0
lw s0,12(sp)
addi sp,sp,16
jr ra
