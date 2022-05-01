	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14	sdk_version 10, 14
	.globl	_routine                ## -- Begin function routine
	.p2align	4, 0x90
_routine:                               ## @routine
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	leaq	L_.str(%rip), %rdi
	movb	$0, %al
	callq	_printf
	xorl	%ecx, %ecx
	movl	%ecx, %edi
	movl	%eax, -4(%rbp)          ## 4-byte Spill
	movq	%rdi, %rax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	xorl	%eax, %eax
	movl	%eax, %ecx
	leaq	_routine(%rip), %rdx
	movl	$0, -4(%rbp)
	movl	%edi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	leaq	-24(%rbp), %rdi
	movq	%rcx, %rsi
	callq	_pthread_create
	cmpl	$0, %eax
	je	LBB1_2
## %bb.1:
	leaq	L_.str.1(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	%eax, -36(%rbp)         ## 4-byte Spill
LBB1_2:
	xorl	%eax, %eax
	movl	%eax, %ecx
	leaq	_routine(%rip), %rdx
	leaq	-32(%rbp), %rdi
	movq	%rcx, %rsi
	callq	_pthread_create
	cmpl	$0, %eax
	je	LBB1_4
## %bb.3:
	leaq	L_.str.1(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	%eax, -40(%rbp)         ## 4-byte Spill
LBB1_4:
	xorl	%eax, %eax
	movl	%eax, %esi
	movq	-24(%rbp), %rdi
	callq	_pthread_join
	cmpl	$0, %eax
	je	LBB1_6
## %bb.5:
	leaq	L_.str.1(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	%eax, -44(%rbp)         ## 4-byte Spill
LBB1_6:
	xorl	%eax, %eax
	movl	%eax, %esi
	movq	-32(%rbp), %rdi
	callq	_pthread_join
	cmpl	$0, %eax
	je	LBB1_8
## %bb.7:
	leaq	L_.str.1(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	%eax, -48(%rbp)         ## 4-byte Spill
LBB1_8:
	xorl	%eax, %eax
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"Test from the Tread\n"

L_.str.1:                               ## @.str.1
	.asciz	"Error"


.subsections_via_symbols
