	.attribute	4, 16
	.attribute	5, "rv32i2p1_m2p0_a2p1_f2p2_d2p2_zicsr2p0_zmmul1p0_zaamo1p0_zalrsc1p0"
	.file	"parser"
	.text
	.globl	main                            # -- Begin function main
	.p2align	2
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:                                # %entry
	addi	sp, sp, -32
	.cfi_def_cfa_offset 32
	sw	ra, 28(sp)                      # 4-byte Folded Spill
	sw	s0, 24(sp)                      # 4-byte Folded Spill
	.cfi_offset ra, -4
	.cfi_offset s0, -8
	addi	s0, sp, 32
	.cfi_def_cfa s0, 0
	li	a0, 2
	sw	a0, -12(s0)
	li	a0, 3
	sw	zero, -20(s0)
	sw	a0, -16(s0)
	li	a0, 4
.LBB0_1:                                # %for.cond
                                        # =>This Inner Loop Header: Depth=1
	lw	a1, -20(s0)
	addi	a2, a1, 1
	sw	a2, -20(s0)
	blt	a0, a1, .LBB0_3
# %bb.2:                                # %for.body
                                        #   in Loop: Header=BB0_1 Depth=1
	lw	a1, -12(s0)
	lw	a2, -16(s0)
	add	a1, a1, a2
	sw	a1, -16(s0)
	j	.LBB0_1
.LBB0_3:                                # %for.end
	mv	a1, sp
	addi	a0, a1, -16
	mv	sp, a0
	li	a2, 10
	sw	a2, -16(a1)
	li	a1, 6
	lw	a2, 0(a0)
	blt	a2, a1, .LBB0_5
.LBB0_4:                                # %while.body
                                        # =>This Inner Loop Header: Depth=1
	lw	a2, 0(a0)
	addi	a2, a2, -1
	sw	a2, 0(a0)
	lw	a2, 0(a0)
	bge	a2, a1, .LBB0_4
.LBB0_5:                                # %while.end
	mv	a0, sp
	addi	sp, a0, -16
	li	a1, 2
	sw	a1, -16(a0)
	li	a0, 0
	addi	sp, s0, -32
	.cfi_def_cfa sp, 32
	lw	ra, 28(sp)                      # 4-byte Folded Reload
	lw	s0, 24(sp)                      # 4-byte Folded Reload
	.cfi_restore ra
	.cfi_restore s0
	addi	sp, sp, 32
	.cfi_def_cfa_offset 0
	ret
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
                                        # -- End function
	.section	".note.GNU-stack","",@progbits
