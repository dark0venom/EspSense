	.text
	.file	"crt1.c"
                                        # Start of file scope inline assembly
	.ident	"$FreeBSD$"
	.ident	"$FreeBSD$"
	.ident	"$FreeBSD$"

                                        # End of file scope inline assembly
	.globl	_start                  # -- Begin function _start
	.p2align	4, 0x90
	.type	_start,@function
_start:                                 # @_start
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%rbx
	pushq	%rax
	.cfi_offset %rbx, -40
	.cfi_offset %r14, -32
	.cfi_offset %r15, -24
	movq	%rdi, %rbx
	movq	(%rbx), %r14
	movslq	%r14d, %rax
	leaq	(%rbx,%rax,8), %r15
	addq	$16, %r15
	movq	environ@GOTPCREL(%rip), %rax
	cmpq	$0, (%rax)
	jne	.LBB0_2
# %bb.1:
	movq	%r15, (%rax)
.LBB0_2:
	addq	$8, %rbx
	testl	%r14d, %r14d
	jle	.LBB0_10
# %bb.3:
	movq	(%rbx), %rax
	testq	%rax, %rax
	je	.LBB0_10
# %bb.4:
	movq	__progname@GOTPCREL(%rip), %rcx
	jmp	.LBB0_5
	.p2align	4, 0x90
.LBB0_9:                                #   in Loop: Header=BB0_5 Depth=1
	addq	$1, %rax
.LBB0_5:                                # =>This Loop Header: Depth=1
                                        #     Child Loop BB0_6 Depth 2
	movq	%rax, (%rcx)
	jmp	.LBB0_6
	.p2align	4, 0x90
.LBB0_8:                                #   in Loop: Header=BB0_6 Depth=2
	addq	$1, %rax
.LBB0_6:                                #   Parent Loop BB0_5 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movzbl	(%rax), %edx
	cmpb	$47, %dl
	je	.LBB0_9
# %bb.7:                                #   in Loop: Header=BB0_6 Depth=2
	testb	%dl, %dl
	jne	.LBB0_8
.LBB0_10:
	cmpq	$0, _DYNAMIC@GOTPCREL(%rip)
	je	.LBB0_12
# %bb.11:
	movq	%rsi, %rdi
	callq	atexit@PLT
	jmp	.LBB0_13
.LBB0_12:
	callq	_init_tls@PLT
.LBB0_13:
	movl	%r14d, %edi
	movq	%rbx, %rsi
	movq	%r15, %rdx
	callq	handle_static_init
	movl	%r14d, %edi
	movq	%rbx, %rsi
	movq	%r15, %rdx
	callq	main@PLT
	movl	%eax, %edi
	callq	exit@PLT
.Lfunc_end0:
	.size	_start, .Lfunc_end0-_start
	.cfi_endproc
                                        # -- End function
	.p2align	4, 0x90         # -- Begin function handle_static_init
	.type	handle_static_init,@function
handle_static_init:                     # @handle_static_init
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	pushq	%rax
	.cfi_offset %rbx, -56
	.cfi_offset %r12, -48
	.cfi_offset %r13, -40
	.cfi_offset %r14, -32
	.cfi_offset %r15, -24
	movq	%rdx, -48(%rbp)         # 8-byte Spill
	movq	%rsi, %r15
	movl	%edi, %r12d
	cmpq	$0, _DYNAMIC@GOTPCREL(%rip)
	jne	.LBB1_11
# %bb.1:
	leaq	finalizer(%rip), %rdi
	callq	atexit@PLT
	leaq	__preinit_array_start(%rip), %rbx
	leaq	__preinit_array_end(%rip), %rax
	subq	%rbx, %rax
	movq	%rax, %r13
	sarq	$63, %r13
	shrq	$61, %r13
	addq	%rax, %r13
	sarq	$3, %r13
	je	.LBB1_6
# %bb.2:
	xorl	%r14d, %r14d
	.p2align	4, 0x90
.LBB1_3:                                # =>This Inner Loop Header: Depth=1
	movq	(%rbx), %rax
	cmpq	$2, %rax
	jb	.LBB1_5
# %bb.4:                                #   in Loop: Header=BB1_3 Depth=1
	movl	%r12d, %edi
	movq	%r15, %rsi
	movq	-48(%rbp), %rdx         # 8-byte Reload
	callq	*%rax
.LBB1_5:                                #   in Loop: Header=BB1_3 Depth=1
	addq	$1, %r14
	addq	$8, %rbx
	cmpq	%r13, %r14
	jb	.LBB1_3
.LBB1_6:
	callq	_init
	leaq	__init_array_start(%rip), %r14
	leaq	__init_array_end(%rip), %rax
	subq	%r14, %rax
	movq	%rax, %r13
	sarq	$63, %r13
	shrq	$61, %r13
	addq	%rax, %r13
	sarq	$3, %r13
	je	.LBB1_11
# %bb.7:
	xorl	%ebx, %ebx
	.p2align	4, 0x90
.LBB1_8:                                # =>This Inner Loop Header: Depth=1
	movq	(%r14), %rax
	cmpq	$2, %rax
	jb	.LBB1_10
# %bb.9:                                #   in Loop: Header=BB1_8 Depth=1
	movl	%r12d, %edi
	movq	%r15, %rsi
	movq	-48(%rbp), %rdx         # 8-byte Reload
	callq	*%rax
.LBB1_10:                               #   in Loop: Header=BB1_8 Depth=1
	addq	$1, %rbx
	addq	$8, %r14
	cmpq	%r13, %rbx
	jb	.LBB1_8
.LBB1_11:
	addq	$8, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end1:
	.size	handle_static_init, .Lfunc_end1-handle_static_init
	.cfi_endproc
                                        # -- End function
	.p2align	4, 0x90         # -- Begin function finalizer
	.type	finalizer,@function
finalizer:                              # @finalizer
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	pushq	%r14
	pushq	%rbx
	.cfi_offset %rbx, -32
	.cfi_offset %r14, -24
	leaq	__fini_array_start(%rip), %r14
	leaq	__fini_array_end(%rip), %rax
	subq	%r14, %rax
	movq	%rax, %rbx
	sarq	$63, %rbx
	shrq	$61, %rbx
	addq	%rax, %rbx
	sarq	$3, %rbx
	je	.LBB2_4
	.p2align	4, 0x90
.LBB2_1:                                # =>This Inner Loop Header: Depth=1
	movq	-8(%r14,%rbx,8), %rax
	addq	$-1, %rbx
	cmpq	$2, %rax
	jb	.LBB2_3
# %bb.2:                                #   in Loop: Header=BB2_1 Depth=1
	callq	*%rax
.LBB2_3:                                #   in Loop: Header=BB2_1 Depth=1
	testq	%rbx, %rbx
	jne	.LBB2_1
.LBB2_4:
	popq	%rbx
	popq	%r14
	popq	%rbp
	jmp	_fini                   # TAILCALL
.Lfunc_end2:
	.size	finalizer, .Lfunc_end2-finalizer
	.cfi_endproc
                                        # -- End function
	.type	abitag,@object          # @abitag
	.section	.note.tag,"a",@note
	.p2align	2
abitag:
	.long	8                       # 0x8
	.long	4                       # 0x4
	.long	1                       # 0x1
	.asciz	"FreeBSD"
	.long	1102000                 # 0x10d0b0
	.size	abitag, 24

	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.zero	1
	.size	.L.str, 1

	.type	__progname,@object      # @__progname
	.data
	.globl	__progname
	.p2align	3
__progname:
	.quad	.L.str
	.size	__progname, 8

	.type	crt_noinit_tag,@object  # @crt_noinit_tag
	.section	.note.tag,"a",@note
	.p2align	2
crt_noinit_tag:
	.long	8                       # 0x8
	.long	4                       # 0x4
	.long	2                       # 0x2
	.asciz	"FreeBSD"
	.long	0                       # 0x0
	.size	crt_noinit_tag, 24

	.type	environ,@object         # @environ
	.comm	environ,8,8
	.hidden	__preinit_array_end
	.hidden	__preinit_array_start
	.hidden	__init_array_end
	.hidden	__init_array_start
	.hidden	__fini_array_end
	.hidden	__fini_array_start
	.hidden	_init
	.hidden	_fini
	.weak	_DYNAMIC

	.ident	"FreeBSD clang version 6.0.0 (tags/RELEASE_600/final 326565) (based on LLVM 6.0.0)"
	.section	".note.GNU-stack","",@progbits
