.globl f
f:
addi sp,sp,-16
sw s0,12(sp)
addi s0,sp,16
li t1,1
beq t1, zero , .L1
li t0,11
j .end1
beq  zero , zero , .L2
.L1:
li t0,10
j .end1
.L2:
.end1:
mv a0,t0
lw s0,12(sp)
addi sp,sp,16
jr ra
