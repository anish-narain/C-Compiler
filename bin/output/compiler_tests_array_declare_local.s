.globl f
f:
addi    sp,sp,-16
sw      s0,12(sp)
addi    s0,sp,16
mv      a0,a5
lw      s0,12(sp)
addi    sp,sp,16
jr      ra
