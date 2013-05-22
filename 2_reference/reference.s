	.file	"reference.cpp"
	.intel_syntax noprefix
# GNU C++ (Ubuntu/Linaro 4.6.1-9ubuntu3) version 4.6.1 (x86_64-linux-gnu)
#	compiled by GNU C version 4.6.1, GMP version 5.0.1, MPFR version 3.0.1-p3, MPC version 0.9
# GGC heuristics: --param ggc-min-expand=53 --param ggc-min-heapsize=43807
# options passed:  -fpreprocessed reference.ii -masm=intel -mtune=generic
# -march=x86-64 -fverbose-asm -fstack-protector
# options enabled:  -fasynchronous-unwind-tables -fauto-inc-dec
# -fbranch-count-reg -fcommon -fdelete-null-pointer-checks -fdwarf2-cfi-asm
# -fearly-inlining -feliminate-unused-debug-types -fexceptions
# -ffunction-cse -fgcse-lm -fident -finline-functions-called-once
# -fira-share-save-slots -fira-share-spill-slots -fivopts
# -fkeep-static-consts -fleading-underscore -fmath-errno
# -fmerge-debug-strings -fmove-loop-invariants -fpeephole
# -fprefetch-loop-arrays -freg-struct-return
# -fsched-critical-path-heuristic -fsched-dep-count-heuristic
# -fsched-group-heuristic -fsched-interblock -fsched-last-insn-heuristic
# -fsched-rank-heuristic -fsched-spec -fsched-spec-insn-heuristic
# -fsched-stalled-insns-dep -fshow-column -fsigned-zeros
# -fsplit-ivs-in-unroller -fstack-protector -fstrict-volatile-bitfields
# -ftrapping-math -ftree-cselim -ftree-forwprop -ftree-loop-if-convert
# -ftree-loop-im -ftree-loop-ivcanon -ftree-loop-optimize
# -ftree-parallelize-loops= -ftree-phiprop -ftree-pta -ftree-reassoc
# -ftree-scev-cprop -ftree-slp-vectorize -ftree-vect-loop-version
# -funit-at-a-time -funwind-tables -fvect-cost-model -fverbose-asm
# -fzero-initialized-in-bss -m128bit-long-double -m64 -m80387
# -maccumulate-outgoing-args -malign-stringops -mfancy-math-387
# -mfp-ret-in-387 -mglibc -mieee-fp -mmmx -mno-sse4 -mpush-args -mred-zone
# -msse -msse2 -mtls-direct-seg-refs

# Compiler executable checksum: 63a745aba0054d1605090177d8e4bbb4

	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	push	rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp	#,
	.cfi_def_cfa_register 6
	mov	DWORD PTR [rbp-20], edi	# argc, argc
	mov	QWORD PTR [rbp-32], rsi	# argv, argv
	mov	DWORD PTR [rbp-4], 3	# iv,
	lea	rax, [rbp-4]	# tmp61,
	mov	QWORD PTR [rbp-16], rax	# riv, tmp61
	mov	rax, QWORD PTR [rbp-16]	# tmp62, riv
	mov	DWORD PTR [rax], 4	# *riv_1,
	mov	eax, 0	# D.2071,
	pop	rbp	#
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 4.6.1-9ubuntu3) 4.6.1"
	.section	.note.GNU-stack,"",@progbits
