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
	movl	16(%ebp), %edi
	movl	12(%ebp), %esi
	leal	4(%edi,%esi,4), %ebx
	cmpl	$0, environ
	jne	.LBB0_2
# %bb.1:
	movl	%ebx, environ
.LBB0_2:
	testl	%esi, %esi
	jle	.LBB0_9
# %bb.3:
	movl	(%edi), %eax
	testl	%eax, %eax
	jne	.LBB0_4
	jmp	.LBB0_9
	.p2align	4, 0x90
.LBB0_8:                                #   in Loop: Header=BB0_4 Depth=1
	incl	%eax
.LBB0_4:                                # =>This Loop Header: Depth=1
                                        #     Child Loop BB0_5 Depth 2
	movl	%eax, __progname
	jmp	.LBB0_5
	.p2align	4, 0x90
.LBB0_7:                                #   in Loop: Header=BB0_5 Depth=2
	incl	%eax
.LBB0_5:                                #   Parent Loop BB0_4 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movzbl	(%eax), %ecx
	cmpb	$47, %cl
	je	.LBB0_8
# %bb.6:                                #   in Loop: Header=BB0_5 Depth=2
	testb	%cl, %cl
	jne	.LBB0_7
.LBB0_9:
	movl	$_DYNAMIC, %eax
	testl	%eax, %eax
	je	.LBB0_11
# %bb.10:
	pushl	8(%ebp)
	calll	atexit
	addl	$4, %esp
	jmp	.LBB0_12
.LBB0_11:
	calll	_init_tls
.LBB0_12:
	movl	%esi, %ecx
	movl	%edi, %edx
	pushl	%ebx
	calll	handle_static_init
	addl	$4, %esp
	pushl	%ebx
	pushl	%edi
	pushl	%esi
	calll	main
	addl	$12, %esp
	pushl	%eax
	calll	exit
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
	pushl	%eax
	movl	%edx, -16(%ebp)         # 4-byte Spill
	movl	%ecx, %edi
	movl	$_DYNAMIC, %eax
	testl	%eax, %eax
	jne	.LBB1_11
# %bb.1:
	pushl	$finalizer
	calll	atexit
	addl	$4, %esp
	movl	$__preinit_array_start, %eax
	movl	$__preinit_array_end, %ecx
	subl	%eax, %ecx
	movl	%ecx, %ebx
	sarl	$31, %ebx
	shrl	$30, %ebx
	addl	%ecx, %ebx
	sarl	$2, %ebx
	je	.LBB1_6
# %bb.2:
	xorl	%esi, %esi
	.p2align	4, 0x90
.LBB1_3:                                # =>This Inner Loop Header: Depth=1
	movl	__preinit_array_start(,%esi,4), %eax
	cmpl	$2, %eax
	jb	.LBB1_5
# %bb.4:                                #   in Loop: Header=BB1_3 Depth=1
	pushl	8(%ebp)
	pushl	-16(%ebp)               # 4-byte Folded Reload
	pushl	%edi
	calll	*%eax
	addl	$12, %esp
.LBB1_5:                                #   in Loop: Header=BB1_3 Depth=1
	incl	%esi
	cmpl	%ebx, %esi
	jb	.LBB1_3
.LBB1_6:
	calll	_init
	movl	$__init_array_start, %eax
	movl	$__init_array_end, %ecx
	subl	%eax, %ecx
	movl	%ecx, %ebx
	sarl	$31, %ebx
	shrl	$30, %ebx
	addl	%ecx, %ebx
	sarl	$2, %ebx
	je	.LBB1_11
# %bb.7:
	xorl	%esi, %esi
	.p2align	4, 0x90
.LBB1_8:                                # =>This Inner Loop Header: Depth=1
	movl	__init_array_start(,%esi,4), %eax
	cmpl	$2, %eax
	jb	.LBB1_10
# %bb.9:                                #   in Loop: Header=BB1_8 Depth=1
	pushl	8(%ebp)
	pushl	-16(%ebp)               # 4-byte Folded Reload
	pushl	%edi
	calll	*%eax
	addl	$12, %esp
.LBB1_10:                               #   in Loop: Header=BB1_8 Depth=1
	incl	%esi
	cmpl	%ebx, %esi
	jb	.LBB1_8
.LBB1_11:
	addl	$4, %esp
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
	pushl	%esi
	movl	$__fini_array_start, %eax
	movl	$__fini_array_end, %ecx
	subl	%eax, %ecx
	movl	%ecx, %esi
	sarl	$31, %esi
	shrl	$30, %esi
	addl	%ecx, %esi
	sarl	$2, %esi
	je	.LBB2_4
	.p2align	4, 0x90
.LBB2_1:                                # =>This Inner Loop Header: Depth=1
	movl	__fini_array_start-4(,%esi,4), %eax
	decl	%esi
	cmpl	$2, %eax
	jb	.LBB2_3
# %bb.2:                                #   in Loop: Header=BB2_1 Depth=1
	calll	*%eax
.LBB2_3:                                #   in Loop: Header=BB2_1 Depth=1
	testl	%esi, %esi
	jne	.LBB2_1
.LBB2_4:
	popl	%esi
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
