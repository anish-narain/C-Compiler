.globl f
f:
addi sp,sp,-16
sw s0,12(sp)
addi s0,sp,16
li t1,0
beq t1, zero , .L2
.L1:
li t0,11
beq  zero , zero , .L3
.L2:
li t1,10
.L3:
mv a0,t0
lw s0,12(sp)
addi sp,sp,16
jr ra
