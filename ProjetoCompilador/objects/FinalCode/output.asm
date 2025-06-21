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
	.cfi_offset ra, -4
	sw	zero, 24(sp)
	lui	a0, 167772
	lui	a1, 262741
	addi	a0, a0, 656
	addi	a1, a1, -164
	sw	a0, 16(sp)
	sw	a1, 20(sp)
	lui	a0, 209715
	addi	a0, a0, 818
	sw	a0, 12(sp)
	lui	a0, %hi(str_literal)
	addi	a0, a0, %lo(str_literal)
	li	a1, 0
	call	printf
	fld	fa5, 16(sp)
	fsd	fa5, 0(sp)
	lw	a2, 0(sp)
	lw	a3, 4(sp)
	lui	a0, %hi(str_literal.1)
	addi	a0, a0, %lo(str_literal.1)
	call	printf
	lw	a1, 12(sp)
	lui	a0, %hi(str_literal.2)
	addi	a0, a0, %lo(str_literal.2)
	call	printf
	li	a0, 0
	lw	ra, 28(sp)                      # 4-byte Folded Reload
	.cfi_restore ra
	addi	sp, sp, 32
	.cfi_def_cfa_offset 0
	ret
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
                                        # -- End function
	.type	str_literal,@object             # @str_literal
	.data
	.globl	str_literal
str_literal:
	.asciz	"\"a = %d\\n\""
	.size	str_literal, 11

	.type	str_literal.1,@object           # @str_literal.1
	.globl	str_literal.1
str_literal.1:
	.asciz	"\"b = %f\\n\""
	.size	str_literal.1, 11

	.type	str_literal.2,@object           # @str_literal.2
	.globl	str_literal.2
str_literal.2:
	.asciz	"\"c = %d\\n\""
	.size	str_literal.2, 11

	.section	".note.GNU-stack","",@progbits
