.globl g
g:
addi sp,sp,-16
sw s0,12(sp)
addi s0,sp,16
li t0,20
j .end1
.end1:
mv a0,t0
lw s0,12(sp)
addi sp,sp,16
jr ra
.globl f
f:
addi sp,sp,-16
sw ra,12(sp)
sw s0,8(sp)
addi s0,sp,16
call g
mv t1, a0
j .end2
.end2:
lw ra,12(sp)
mv a0,t1
lw s0,8(sp)
addi sp,sp,16
jr ra
