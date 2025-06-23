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
	addi	sp, sp, -48
	.cfi_def_cfa_offset 48
	sw	ra, 44(sp)                      # 4-byte Folded Spill
	sw	s0, 40(sp)                      # 4-byte Folded Spill
	.cfi_offset ra, -4
	.cfi_offset s0, -8
	addi	s0, sp, 48
	.cfi_def_cfa s0, 0
	.cfi_remember_state
	li	a0, 2
	sw	a0, -12(s0)
	li	a0, 3
	sw	a0, -16(s0)
	li	a0, 0
	sw	a0, -20(s0)
	j	.LBB0_1
.LBB0_1:                                # %for.cond
                                        # =>This Inner Loop Header: Depth=1
	lw	a1, -20(s0)
	li	a0, 4
	blt	a0, a1, .LBB0_4
	j	.LBB0_2
.LBB0_2:                                # %for.body
                                        #   in Loop: Header=BB0_1 Depth=1
	lw	a0, -12(s0)
	lw	a1, -16(s0)
	add	a0, a0, a1
	sw	a0, -16(s0)
	j	.LBB0_3
.LBB0_3:                                # %for.inc
                                        #   in Loop: Header=BB0_1 Depth=1
	lw	a0, -20(s0)
	addi	a0, a0, 1
	sw	a0, -20(s0)
	j	.LBB0_1
.LBB0_4:                                # %for.end
	mv	a1, sp
	addi	a0, a1, -16
	sw	a0, -24(s0)                     # 4-byte Folded Spill
	mv	sp, a0
	li	a0, 10
	sw	a0, -16(a1)
	j	.LBB0_5
.LBB0_5:                                # %while.cond
                                        # =>This Inner Loop Header: Depth=1
	lw	a0, -24(s0)                     # 4-byte Folded Reload
	lw	a0, 0(a0)
	li	a1, 6
	blt	a0, a1, .LBB0_7
	j	.LBB0_6
.LBB0_6:                                # %while.body
                                        #   in Loop: Header=BB0_5 Depth=1
	lw	a1, -24(s0)                     # 4-byte Folded Reload
	lw	a0, 0(a1)
	addi	a0, a0, -1
	sw	a0, 0(a1)
	j	.LBB0_5
.LBB0_7:                                # %while.end
	lw	a1, -24(s0)                     # 4-byte Folded Reload
	li	a0, 5
	sw	a0, 0(a1)
	j	.LBB0_8
.LBB0_8:                                # %do.body
                                        # =>This Inner Loop Header: Depth=1
	lw	a0, -24(s0)                     # 4-byte Folded Reload
	lw	a1, 0(a0)
	lui	a0, %hi(str_literal)
	addi	a0, a0, %lo(str_literal)
	call	printf
	lw	a1, -24(s0)                     # 4-byte Folded Reload
	lw	a0, 0(a1)
	addi	a0, a0, -1
	sw	a0, 0(a1)
	j	.LBB0_9
.LBB0_9:                                # %do.cond
                                        #   in Loop: Header=BB0_8 Depth=1
	lw	a0, -24(s0)                     # 4-byte Folded Reload
	lw	a1, 0(a0)
	li	a0, 0
	blt	a0, a1, .LBB0_8
	j	.LBB0_10
.LBB0_10:                               # %do.end
	mv	a0, sp
	addi	a0, a0, -16
	mv	sp, a0
	li	a0, 0
	sw	a0, -20(s0)
	j	.LBB0_11
.LBB0_11:                               # %for.cond10
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB0_15 Depth 2
	lw	a1, -20(s0)
	li	a0, 2
	blt	a0, a1, .LBB0_14
	j	.LBB0_12
.LBB0_12:                               # %for.body11
                                        #   in Loop: Header=BB0_11 Depth=1
	mv	a1, sp
	addi	a0, a1, -16
	sw	a0, -28(s0)                     # 4-byte Folded Spill
	mv	sp, a0
	li	a0, 0
	sw	a0, -16(a1)
	j	.LBB0_15
.LBB0_13:                               # %for.inc12
                                        #   in Loop: Header=BB0_11 Depth=1
	lw	a0, -20(s0)
	addi	a0, a0, 1
	sw	a0, -20(s0)
	j	.LBB0_11
.LBB0_14:                               # %for.end13
	mv	a0, sp
	addi	a0, a0, -16
	mv	sp, a0
	li	a0, 0
	sw	a0, -20(s0)
	j	.LBB0_19
.LBB0_15:                               # %for.cond19
                                        #   Parent Loop BB0_11 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	lw	a0, -28(s0)                     # 4-byte Folded Reload
	lw	a1, 0(a0)
	li	a0, 1
	blt	a0, a1, .LBB0_18
	j	.LBB0_16
.LBB0_16:                               # %for.body20
                                        #   in Loop: Header=BB0_15 Depth=2
	lw	a0, -28(s0)                     # 4-byte Folded Reload
	lw	a1, -20(s0)
	lw	a2, 0(a0)
	lui	a0, %hi(str_literal.1)
	addi	a0, a0, %lo(str_literal.1)
	call	printf
	j	.LBB0_17
.LBB0_17:                               # %for.inc21
                                        #   in Loop: Header=BB0_15 Depth=2
	lw	a1, -28(s0)                     # 4-byte Folded Reload
	lw	a0, 0(a1)
	addi	a0, a0, 1
	sw	a0, 0(a1)
	j	.LBB0_15
.LBB0_18:                               # %for.end22
                                        #   in Loop: Header=BB0_11 Depth=1
	j	.LBB0_13
.LBB0_19:                               # %for.cond29
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB0_23 Depth 2
	lw	a1, -20(s0)
	li	a0, 2
	blt	a0, a1, .LBB0_22
	j	.LBB0_20
.LBB0_20:                               # %for.body30
                                        #   in Loop: Header=BB0_19 Depth=1
	lw	a0, -20(s0)
	mv	a1, sp
	addi	a2, a1, -16
	sw	a2, -32(s0)                     # 4-byte Folded Spill
	mv	sp, a2
	sw	a0, -16(a1)
	j	.LBB0_23
.LBB0_21:                               # %for.inc31
                                        #   in Loop: Header=BB0_19 Depth=1
	lw	a0, -20(s0)
	addi	a0, a0, 1
	sw	a0, -20(s0)
	j	.LBB0_19
.LBB0_22:                               # %for.end32
	mv	a1, sp
	addi	a0, a1, -16
	sw	a0, -36(s0)                     # 4-byte Folded Spill
	mv	sp, a0
	li	a0, 2
	sw	a0, -16(a1)
	j	.LBB0_26
.LBB0_23:                               # %while.cond39
                                        #   Parent Loop BB0_19 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	lw	a0, -32(s0)                     # 4-byte Folded Reload
	lw	a1, 0(a0)
	li	a0, 0
	bge	a0, a1, .LBB0_25
	j	.LBB0_24
.LBB0_24:                               # %while.body40
                                        #   in Loop: Header=BB0_23 Depth=2
	lw	a0, -32(s0)                     # 4-byte Folded Reload
	lw	a1, -20(s0)
	lw	a2, 0(a0)
	lui	a0, %hi(str_literal.2)
	addi	a0, a0, %lo(str_literal.2)
	call	printf
	lw	a1, -32(s0)                     # 4-byte Folded Reload
	lw	a0, 0(a1)
	addi	a0, a0, -1
	sw	a0, 0(a1)
	j	.LBB0_23
.LBB0_25:                               # %while.end41
                                        #   in Loop: Header=BB0_19 Depth=1
	j	.LBB0_21
.LBB0_26:                               # %while.cond48
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB0_29 Depth 2
	lw	a0, -36(s0)                     # 4-byte Folded Reload
	lw	a1, 0(a0)
	li	a0, 0
	bge	a0, a1, .LBB0_28
	j	.LBB0_27
.LBB0_27:                               # %while.body49
                                        #   in Loop: Header=BB0_26 Depth=1
	mv	a1, sp
	addi	a0, a1, -16
	sw	a0, -40(s0)                     # 4-byte Folded Spill
	mv	sp, a0
	li	a0, 0
	sw	a0, -16(a1)
	j	.LBB0_29
.LBB0_28:                               # %while.end50
	mv	a1, sp
	addi	a0, a1, -16
	sw	a0, -44(s0)                     # 4-byte Folded Spill
	mv	sp, a0
	li	a0, 4
	sw	a0, -16(a1)
	j	.LBB0_33
.LBB0_29:                               # %for.cond53
                                        #   Parent Loop BB0_26 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	lw	a0, -40(s0)                     # 4-byte Folded Reload
	lw	a1, 0(a0)
	li	a0, 2
	blt	a0, a1, .LBB0_32
	j	.LBB0_30
.LBB0_30:                               # %for.body54
                                        #   in Loop: Header=BB0_29 Depth=2
	lw	a0, -40(s0)                     # 4-byte Folded Reload
	lw	a1, -36(s0)                     # 4-byte Folded Reload
	lw	a1, 0(a1)
	lw	a2, 0(a0)
	lui	a0, %hi(str_literal.3)
	addi	a0, a0, %lo(str_literal.3)
	call	printf
	j	.LBB0_31
.LBB0_31:                               # %for.inc55
                                        #   in Loop: Header=BB0_29 Depth=2
	lw	a1, -40(s0)                     # 4-byte Folded Reload
	lw	a0, 0(a1)
	addi	a0, a0, 1
	sw	a0, 0(a1)
	j	.LBB0_29
.LBB0_32:                               # %for.end56
                                        #   in Loop: Header=BB0_26 Depth=1
	lw	a1, -36(s0)                     # 4-byte Folded Reload
	lw	a0, 0(a1)
	addi	a0, a0, -1
	sw	a0, 0(a1)
	j	.LBB0_26
.LBB0_33:                               # %do.body65
                                        # =>This Inner Loop Header: Depth=1
	lw	a0, -44(s0)                     # 4-byte Folded Reload
	lw	a0, 0(a0)
	srli	a1, a0, 31
	add	a0, a0, a1
	srai	a0, a0, 1
	beqz	a0, .LBB0_36
	j	.LBB0_37
.LBB0_34:                               # %do.cond66
                                        #   in Loop: Header=BB0_33 Depth=1
	lw	a0, -44(s0)                     # 4-byte Folded Reload
	lw	a1, 0(a0)
	li	a0, 0
	blt	a0, a1, .LBB0_33
	j	.LBB0_35
.LBB0_35:                               # %do.end67
	li	a0, 2
	sw	a0, -12(s0)
	j	.LBB0_40
.LBB0_36:                               # %if
                                        #   in Loop: Header=BB0_33 Depth=1
	lw	a0, -44(s0)                     # 4-byte Folded Reload
	lw	a1, 0(a0)
	lui	a0, %hi(str_literal.4)
	addi	a0, a0, %lo(str_literal.4)
	call	printf
	j	.LBB0_38
.LBB0_37:                               # %next_cond
                                        #   in Loop: Header=BB0_33 Depth=1
	lw	a0, -44(s0)                     # 4-byte Folded Reload
	lw	a1, 0(a0)
	lui	a0, %hi(str_literal.5)
	addi	a0, a0, %lo(str_literal.5)
	call	printf
	j	.LBB0_38
.LBB0_38:                               # %intermediary
                                        #   in Loop: Header=BB0_33 Depth=1
	j	.LBB0_39
.LBB0_39:                               # %endif
                                        #   in Loop: Header=BB0_33 Depth=1
	lw	a1, -44(s0)                     # 4-byte Folded Reload
	lw	a0, 0(a1)
	addi	a0, a0, -1
	sw	a0, 0(a1)
	j	.LBB0_34
.LBB0_40:                               # %do.body76
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB0_43 Depth 2
	li	a0, 1
	sw	a0, -16(s0)
	j	.LBB0_43
.LBB0_41:                               # %do.cond77
                                        #   in Loop: Header=BB0_40 Depth=1
	lw	a1, -12(s0)
	li	a0, 0
	blt	a0, a1, .LBB0_40
	j	.LBB0_42
.LBB0_42:                               # %do.end78
	lw	a1, -44(s0)                     # 4-byte Folded Reload
	mv	a0, sp
	addi	a0, a0, -16
	mv	sp, a0
	li	a0, 2
	sw	a0, 0(a1)
	li	a0, 0
	addi	sp, s0, -48
	.cfi_def_cfa sp, 48
	lw	ra, 44(sp)                      # 4-byte Folded Reload
	lw	s0, 40(sp)                      # 4-byte Folded Reload
	.cfi_restore ra
	.cfi_restore s0
	addi	sp, sp, 48
	.cfi_def_cfa_offset 0
	ret
.LBB0_43:                               # %do.body79
                                        #   Parent Loop BB0_40 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	.cfi_restore_state
	lw	a1, -12(s0)
	lw	a2, -16(s0)
	lui	a0, %hi(str_literal.6)
	addi	a0, a0, %lo(str_literal.6)
	call	printf
	lw	a0, -16(s0)
	addi	a0, a0, 1
	sw	a0, -16(s0)
	j	.LBB0_44
.LBB0_44:                               # %do.cond80
                                        #   in Loop: Header=BB0_43 Depth=2
	lw	a0, -16(s0)
	li	a1, 3
	blt	a0, a1, .LBB0_43
	j	.LBB0_45
.LBB0_45:                               # %do.end81
                                        #   in Loop: Header=BB0_40 Depth=1
	lw	a0, -12(s0)
	addi	a0, a0, -1
	sw	a0, -12(s0)
	j	.LBB0_41
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
                                        # -- End function
	.globl	_start                          # -- Begin function _start
	.p2align	2
	.type	_start,@function
_start:                                 # @_start
	.cfi_startproc
# %bb.0:                                # %entry
	addi	sp, sp, -16
	.cfi_def_cfa_offset 16
	sw	ra, 12(sp)                      # 4-byte Folded Spill
	.cfi_offset ra, -4
	call	main
	li	a0, 0
	call	exit
.Lfunc_end1:
	.size	_start, .Lfunc_end1-_start
	.cfi_endproc
                                        # -- End function
	.type	str_literal,@object             # @str_literal
	.data
	.globl	str_literal
str_literal:
	.asciz	"\"%d\\n\""
	.size	str_literal, 7

	.type	str_literal.1,@object           # @str_literal.1
	.globl	str_literal.1
	.p2align	4, 0x0
str_literal.1:
	.asciz	"\"i = %d, j = %d\\n\""
	.size	str_literal.1, 19

	.type	str_literal.2,@object           # @str_literal.2
	.globl	str_literal.2
	.p2align	4, 0x0
str_literal.2:
	.asciz	"\"i = %d, x = %d\\n\""
	.size	str_literal.2, 19

	.type	str_literal.3,@object           # @str_literal.3
	.globl	str_literal.3
	.p2align	4, 0x0
str_literal.3:
	.asciz	"\"k = %d, m = %d\\n\""
	.size	str_literal.3, 19

	.type	str_literal.4,@object           # @str_literal.4
	.globl	str_literal.4
str_literal.4:
	.asciz	"\"%d \303\251 par\\n\""
	.size	str_literal.4, 14

	.type	str_literal.5,@object           # @str_literal.5
	.globl	str_literal.5
	.p2align	4, 0x0
str_literal.5:
	.asciz	"\"%d \303\251 \303\255mpar\\n\""
	.size	str_literal.5, 17

	.type	str_literal.6,@object           # @str_literal.6
	.globl	str_literal.6
	.p2align	4, 0x0
str_literal.6:
	.asciz	"\"a = %d, b = %d\\n\""
	.size	str_literal.6, 19

	.section	".note.GNU-stack","",@progbits
