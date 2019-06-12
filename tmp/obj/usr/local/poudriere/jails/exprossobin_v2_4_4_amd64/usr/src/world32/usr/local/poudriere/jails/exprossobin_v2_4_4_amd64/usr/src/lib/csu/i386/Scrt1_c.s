	.text
	.file	"crt1_c.c"
                                        # Start of file scope inline assembly
	.ident	"$FreeBSD$"
	.ident	"$FreeBSD$"
	.ident	"$FreeBSD$"
	.hidden	_start1

                                        # End of file scope inline assembly
	.globl	_start1                 # -- Begin function _start1
	.p2align	4, 0x90
	.type	_start1,@function
_start1:                                # @_start1
# %bb.0:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	pushl	%edi
	pushl	%esi
	pushl	%eax
	calll	.L0$pb
.L0$pb:
	popl	%ebx
.Ltmp0:
	addl	$_GLOBAL_OFFSET_TABLE_+(.Ltmp0-.L0$pb), %ebx
	movl	16(%ebp), %eax
	movl	12(%ebp), %ecx
	movl	%eax, %esi
	leal	4(%eax,%ecx,4), %edx
	movl	environ@GOT(%ebx), %eax
	cmpl	$0, (%eax)
	jne	.LBB0_2
# %bb.1:
	movl	%edx, (%eax)
.LBB0_2:
	movl	%edx, -16(%ebp)         # 4-byte Spill
	movl	%ecx, %edi
	testl	%ecx, %ecx
	jle	.LBB0_10
# %bb.3:
	movl	(%esi), %eax
	testl	%eax, %eax
	je	.LBB0_10
# %bb.4:
	movl	__progname@GOT(%ebx), %ecx
	jmp	.LBB0_5
	.p2align	4, 0x90
.LBB0_9:                                #   in Loop: Header=BB0_5 Depth=1
	incl	%eax
.LBB0_5:                                # =>This Loop Header: Depth=1
                                        #     Child Loop BB0_6 Depth 2
	movl	%eax, (%ecx)
	jmp	.LBB0_6
	.p2align	4, 0x90
.LBB0_8:                                #   in Loop: Header=BB0_6 Depth=2
	incl	%eax
.LBB0_6:                                #   Parent Loop BB0_5 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movzbl	(%eax), %edx
	cmpb	$47, %dl
	je	.LBB0_9
# %bb.7:                                #   in Loop: Header=BB0_6 Depth=2
	testb	%dl, %dl
	jne	.LBB0_8
.LBB0_10:
	cmpl	$0, _DYNAMIC@GOT(%ebx)
	je	.LBB0_12
# %bb.11:
	pushl	8(%ebp)
	calll	atexit@PLT
	addl	$4, %esp
	jmp	.LBB0_13
.LBB0_12:
	calll	_init_tls@PLT
.LBB0_13:
	movl	%edi, %ecx
	movl	%esi, %edx
	movl	-16(%ebp), %esi         # 4-byte Reload
	pushl	%esi
	calll	handle_static_init
	addl	$4, %esp
	pushl	%esi
	pushl	16(%ebp)
	pushl	%edi
	calll	main@PLT
	addl	$12, %esp
	pushl	%eax
	calll	exit@PLT
.Lfunc_end0:
	.size	_start1, .Lfunc_end0-_start1
                                        # -- End function
	.p2align	4, 0x90         # -- Begin function handle_static_init
	.type	handle_static_init,@function
handle_static_init:                     # @handle_static_init
# %bb.0:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	pushl	%edi
	pushl	%esi
	subl	$12, %esp
	movl	%edx, -24(%ebp)         # 4-byte Spill
	movl	%ecx, -20(%ebp)         # 4-byte Spill
	calll	.L1$pb
.L1$pb:
	popl	%ebx
.Ltmp1:
	addl	$_GLOBAL_OFFSET_TABLE_+(.Ltmp1-.L1$pb), %ebx
	cmpl	$0, _DYNAMIC@GOT(%ebx)
	jne	.LBB1_11
# %bb.1:
	leal	finalizer@GOTOFF(%ebx), %eax
	pushl	%eax
	calll	atexit@PLT
	addl	$4, %esp
	leal	__preinit_array_start@GOTOFF(%ebx), %esi
	leal	__preinit_array_end@GOTOFF(%ebx), %eax
	subl	%esi, %eax
	movl	%eax, %ecx
	sarl	$31, %ecx
	shrl	$30, %ecx
	addl	%eax, %ecx
	sarl	$2, %ecx
	je	.LBB1_6
# %bb.2:
	xorl	%edi, %edi
	movl	%ecx, -16(%ebp)         # 4-byte Spill
	.p2align	4, 0x90
.LBB1_3:                                # =>This Inner Loop Header: Depth=1
	movl	(%esi), %eax
	cmpl	$2, %eax
	jb	.LBB1_5
# %bb.4:                                #   in Loop: Header=BB1_3 Depth=1
	pushl	8(%ebp)
	pushl	-24(%ebp)               # 4-byte Folded Reload
	pushl	-20(%ebp)               # 4-byte Folded Reload
	calll	*%eax
	movl	-16(%ebp), %ecx         # 4-byte Reload
	addl	$12, %esp
.LBB1_5:                                #   in Loop: Header=BB1_3 Depth=1
	incl	%edi
	addl	$4, %esi
	cmpl	%ecx, %edi
	jb	.LBB1_3
.LBB1_6:
	calll	_init
	leal	__init_array_start@GOTOFF(%ebx), %esi
	leal	__init_array_end@GOTOFF(%ebx), %eax
	subl	%esi, %eax
	movl	%eax, %ecx
	sarl	$31, %ecx
	shrl	$30, %ecx
	addl	%eax, %ecx
	sarl	$2, %ecx
	je	.LBB1_11
# %bb.7:
	xorl	%edi, %edi
	movl	%ecx, -16(%ebp)         # 4-byte Spill
	.p2align	4, 0x90
.LBB1_8:                                # =>This Inner Loop Header: Depth=1
	movl	(%esi), %eax
	cmpl	$2, %eax
	jb	.LBB1_10
# %bb.9:                                #   in Loop: Header=BB1_8 Depth=1
	pushl	8(%ebp)
	pushl	-24(%ebp)               # 4-byte Folded Reload
	pushl	-20(%ebp)               # 4-byte Folded Reload
	calll	*%eax
	movl	-16(%ebp), %ecx         # 4-byte Reload
	addl	$12, %esp
.LBB1_10:                               #   in Loop: Header=BB1_8 Depth=1
	incl	%edi
	addl	$4, %esi
	cmpl	%ecx, %edi
	jb	.LBB1_8
.LBB1_11:
	addl	$12, %esp
	popl	%esi
	popl	%edi
	popl	%ebx
	popl	%ebp
	retl
.Lfunc_end1:
	.size	handle_static_init, .Lfunc_end1-handle_static_init
                                        # -- End function
	.p2align	4, 0x90         # -- Begin function finalizer
	.type	finalizer,@function
finalizer:                              # @finalizer
# %bb.0:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	pushl	%edi
	pushl	%esi
	calll	.L2$pb
.L2$pb:
	popl	%ebx
.Ltmp2:
	addl	$_GLOBAL_OFFSET_TABLE_+(.Ltmp2-.L2$pb), %ebx
	leal	__fini_array_start@GOTOFF(%ebx), %eax
	leal	__fini_array_end@GOTOFF(%ebx), %ecx
	subl	%eax, %ecx
	movl	%ecx, %eax
	sarl	$31, %eax
	shrl	$30, %eax
	addl	%ecx, %eax
	movl	%eax, %esi
	sarl	$2, %esi
	je	.LBB2_5
# %bb.1:
	andl	$-4, %eax
	leal	__fini_array_start@GOTOFF-4(%ebx,%eax), %edi
	.p2align	4, 0x90
.LBB2_2:                                # =>This Inner Loop Header: Depth=1
	decl	%esi
	movl	(%edi), %eax
	cmpl	$2, %eax
	jb	.LBB2_4
# %bb.3:                                #   in Loop: Header=BB2_2 Depth=1
	calll	*%eax
.LBB2_4:                                #   in Loop: Header=BB2_2 Depth=1
	addl	$-4, %edi
	testl	%esi, %esi
	jne	.LBB2_2
.LBB2_5:
	popl	%esi
	popl	%edi
	popl	%ebx
	popl	%ebp
	jmp	_fini                   # TAILCALL
.Lfunc_end2:
	.size	finalizer, .Lfunc_end2-finalizer
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
	.p2align	2
__progname:
	.long	.L.str
	.size	__progname, 4

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
	.comm	environ,4,4
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
