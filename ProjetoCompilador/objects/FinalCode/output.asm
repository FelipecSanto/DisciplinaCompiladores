	.attribute	4, 16
	.attribute	5, "rv32i2p1_m2p0_a2p1_f2p2_d2p2_zicsr2p0_zmmul1p0_zaamo1p0_zalrsc1p0"
	.file	"parser"
	.section	.rodata.cst8,"aM",@progbits,8
	.p2align	3, 0x0                          # -- Begin function main
.LCPI0_0:
	.quad	0x3ff0000000000000              # double 1
.LCPI0_1:
	.quad	0x401e1eb851eb851f              # double 7.5300000000000002
.LCPI0_2:
	.quad	0xbfe8000000000000              # double -0.75
.LCPI0_3:
	.quad	0x3fe0000000000000              # double 0.5
	.text
	.globl	main
	.p2align	2
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:                                # %entry
	addi	sp, sp, -32
	.cfi_def_cfa_offset 32
	li	a0, 5
	sw	a0, 28(sp)
	lui	a0, 262208
	sw	a0, 20(sp)
	li	a0, 0
	sw	a0, 16(sp)
	li	a1, 10
	sw	a1, 12(sp)
	lw	a1, 28(sp)
	addi	a1, a1, 1
	sw	a1, 28(sp)
	lw	a1, 12(sp)
	addi	a1, a1, -1
	sw	a1, 12(sp)
	lw	a1, 28(sp)
	addi	a1, a1, 3
	sw	a1, 28(sp)
	lw	a1, 28(sp)
	addi	a1, a1, -8
	sw	a1, 28(sp)
	lw	a1, 28(sp)
	slli	a1, a1, 1
	sw	a1, 28(sp)
	lw	a1, 28(sp)
	lui	a2, 699051
	addi	a2, a2, -1365
	mulhu	a1, a1, a2
	srli	a1, a1, 1
	sw	a1, 28(sp)
	fld	fa5, 16(sp)
	lui	a1, %hi(.LCPI0_0)
	fld	fa4, %lo(.LCPI0_0)(a1)
	fadd.d	fa5, fa5, fa4
	fsd	fa5, 16(sp)
	fld	fa5, 16(sp)
	lui	a1, %hi(.LCPI0_1)
	fld	fa4, %lo(.LCPI0_1)(a1)
	fadd.d	fa5, fa5, fa4
	fsd	fa5, 16(sp)
	fld	fa5, 16(sp)
	fadd.d	fa5, fa5, fa5
	fsd	fa5, 16(sp)
	fld	fa5, 16(sp)
	lui	a1, %hi(.LCPI0_2)
	fld	fa4, %lo(.LCPI0_2)(a1)
	fadd.d	fa5, fa5, fa4
	fsd	fa5, 16(sp)
	fld	fa5, 16(sp)
	lui	a1, %hi(.LCPI0_3)
	fld	fa4, %lo(.LCPI0_3)(a1)
	fmul.d	fa5, fa5, fa4
	fsd	fa5, 16(sp)
	lw	a2, 28(sp)
	lw	a1, 12(sp)
	add	a1, a1, a2
	sw	a1, 12(sp)
	fld	fa5, 16(sp)
	lw	a1, 12(sp)
	fcvt.w.d	a2, fa5, rtz
	sub	a1, a1, a2
	sw	a1, 12(sp)
	lw	a1, 12(sp)
	slli	a1, a1, 1
	sw	a1, 12(sp)
	lw	a1, 12(sp)
	lui	a2, 838861
	addi	a2, a2, -819
	mulhu	a1, a1, a2
	srli	a1, a1, 2
	sw	a1, 12(sp)
	addi	sp, sp, 32
	.cfi_def_cfa_offset 0
	ret
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
	.section	".note.GNU-stack","",@progbits
