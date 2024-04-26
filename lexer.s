	.text
	.intel_syntax noprefix
	.file	"lexer.c"
	.globl	lexer_construct                 # -- Begin function lexer_construct
	.p2align	4, 0x90
	.type	lexer_construct,@function
lexer_construct:                        # @lexer_construct
	.cfi_startproc
# %bb.0:
	push	r14
	.cfi_def_cfa_offset 16
	push	rbx
	.cfi_def_cfa_offset 24
	push	rax
	.cfi_def_cfa_offset 32
	.cfi_offset rbx, -24
	.cfi_offset r14, -16
	mov	rbx, rsi
	mov	r14, rdi
	mov	edi, 1
	mov	esi, 40
	call	calloc@PLT
	mov	qword ptr [rax], r14
	mov	qword ptr [rax + 16], rbx
	add	rsp, 8
	.cfi_def_cfa_offset 24
	pop	rbx
	.cfi_def_cfa_offset 16
	pop	r14
	.cfi_def_cfa_offset 8
	ret
.Lfunc_end0:
	.size	lexer_construct, .Lfunc_end0-lexer_construct
	.cfi_endproc
                                        # -- End function
	.globl	lexer_destroy                   # -- Begin function lexer_destroy
	.p2align	4, 0x90
	.type	lexer_destroy,@function
lexer_destroy:                          # @lexer_destroy
	.cfi_startproc
# %bb.0:
	jmp	free@PLT                        # TAILCALL
.Lfunc_end1:
	.size	lexer_destroy, .Lfunc_end1-lexer_destroy
	.cfi_endproc
                                        # -- End function
	.globl	lexer_lex1                      # -- Begin function lexer_lex1
	.p2align	4, 0x90
	.type	lexer_lex1,@function
lexer_lex1:                             # @lexer_lex1
	.cfi_startproc
# %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	push	r15
	.cfi_def_cfa_offset 24
	push	r14
	.cfi_def_cfa_offset 32
	push	r13
	.cfi_def_cfa_offset 40
	push	r12
	.cfi_def_cfa_offset 48
	push	rbx
	.cfi_def_cfa_offset 56
	sub	rsp, 56
	.cfi_def_cfa_offset 112
	.cfi_offset rbx, -56
	.cfi_offset r12, -48
	.cfi_offset r13, -40
	.cfi_offset r14, -32
	.cfi_offset r15, -24
	.cfi_offset rbp, -16
	mov	r12, qword ptr [rdi + 8]
	mov	r13, qword ptr [rdi + 16]
	cmp	r12, r13
	jae	.LBB2_37
# %bb.1:
	mov	r15, rsi
	mov	rbx, rdi
	test	rsi, rsi
	je	.LBB2_2
# %bb.3:
	mov	rax, qword ptr [r15]
	mov	qword ptr [rsp + 8], rax        # 8-byte Spill
	test	rax, rax
	jne	.LBB2_5
# %bb.4:
	mov	edi, 1
	mov	esi, 24
	call	calloc@PLT
	mov	qword ptr [r15], rax
	mov	qword ptr [rsp + 8], rax        # 8-byte Spill
	test	rax, rax
	jne	.LBB2_5
# %bb.39:
	lea	rdi, [rip + .L.str]
	call	perror@PLT
	mov	edi, 1
	call	exit@PLT
.LBB2_2:
	lea	rax, [rsp + 32]
	mov	qword ptr [rsp + 8], rax        # 8-byte Spill
	.p2align	4, 0x90
.LBB2_5:                                # =>This Loop Header: Depth=1
                                        #     Child Loop BB2_22 Depth 2
	mov	qword ptr [rbx + 24], r12
	mov	r15, r12
	cmp	r12, r13
	jae	.LBB2_18
# %bb.6:                                #   in Loop: Header=BB2_5 Depth=1
	mov	rax, qword ptr [rbx]
	cmp	byte ptr [rax + r12], 40
	je	.LBB2_7
# %bb.9:                                #   in Loop: Header=BB2_5 Depth=1
	mov	rax, qword ptr [rbx]
	cmp	byte ptr [rax + r12], 41
	je	.LBB2_10
# %bb.11:                               #   in Loop: Header=BB2_5 Depth=1
	mov	r14, qword ptr [rbx]
	movsx	rbp, byte ptr [r14 + r12]
	call	__ctype_b_loc@PLT
	mov	rax, qword ptr [rax]
	test	byte ptr [rax + 2*rbp + 1], 8
	mov	r15, r12
	je	.LBB2_18
# %bb.12:                               #   in Loop: Header=BB2_5 Depth=1
	lea	r15, [r12 + 1]
	mov	qword ptr [rbx + 8], r15
	test	bpl, bpl
	jne	.LBB2_13
.LBB2_18:                               #   in Loop: Header=BB2_5 Depth=1
	cmp	r15, r13
	jae	.LBB2_19
# %bb.25:                               #   in Loop: Header=BB2_5 Depth=1
	mov	rax, qword ptr [rbx]
	mov	qword ptr [rsp + 24], rax       # 8-byte Spill
	movsx	r14, byte ptr [rax + r15]
	call	__ctype_b_loc@PLT
	mov	rax, qword ptr [rax]
	mov	qword ptr [rsp + 16], rax       # 8-byte Spill
	test	byte ptr [rax + 2*r14 + 1], 4
	jne	.LBB2_28
# %bb.26:                               #   in Loop: Header=BB2_5 Depth=1
	movsx	ebp, r14b
	mov	edi, ebp
	call	lexer_isop
	cmp	bpl, 95
	je	.LBB2_28
# %bb.27:                               #   in Loop: Header=BB2_5 Depth=1
	test	al, al
	je	.LBB2_19
	.p2align	4, 0x90
.LBB2_28:                               #   in Loop: Header=BB2_5 Depth=1
	inc	r15
	mov	qword ptr [rbx + 8], r15
	test	r14b, r14b
	jne	.LBB2_29
.LBB2_19:                               #   in Loop: Header=BB2_5 Depth=1
	mov	r12, r15
	cmp	r15, r13
	jae	.LBB2_35
# %bb.20:                               #   in Loop: Header=BB2_5 Depth=1
	mov	r14, qword ptr [rbx]
	movsx	r15, byte ptr [r14 + r12]
	call	__ctype_b_loc@PLT
	mov	rax, qword ptr [rax]
	test	byte ptr [rax + 2*r15 + 1], 32
	je	.LBB2_35
# %bb.21:                               #   in Loop: Header=BB2_5 Depth=1
	inc	r12
	mov	qword ptr [rbx + 8], r12
	test	r15b, r15b
	je	.LBB2_35
	.p2align	4, 0x90
.LBB2_22:                               #   Parent Loop BB2_5 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	cmp	r12, r13
	jae	.LBB2_5
# %bb.23:                               #   in Loop: Header=BB2_22 Depth=2
	movsx	rcx, byte ptr [r14 + r12]
	test	byte ptr [rax + 2*rcx + 1], 32
	je	.LBB2_5
# %bb.24:                               #   in Loop: Header=BB2_22 Depth=2
	inc	r12
	mov	qword ptr [rbx + 8], r12
	test	cl, cl
	jne	.LBB2_22
	jmp	.LBB2_5
.LBB2_35:
	xor	eax, eax
	cmp	r12, r13
	setae	al
	lea	eax, [rax + 4*rax]
	mov	rcx, qword ptr [rsp + 8]        # 8-byte Reload
	mov	dword ptr [rcx], eax
	jae	.LBB2_37
# %bb.36:
	inc	r12
	mov	qword ptr [rbx + 8], r12
.LBB2_37:
	xor	eax, eax
.LBB2_38:
                                        # kill: def $al killed $al killed $eax
	add	rsp, 56
	.cfi_def_cfa_offset 56
	pop	rbx
	.cfi_def_cfa_offset 48
	pop	r12
	.cfi_def_cfa_offset 40
	pop	r13
	.cfi_def_cfa_offset 32
	pop	r14
	.cfi_def_cfa_offset 24
	pop	r15
	.cfi_def_cfa_offset 16
	pop	rbp
	.cfi_def_cfa_offset 8
	ret
.LBB2_7:
	.cfi_def_cfa_offset 112
	mov	eax, 1
	jmp	.LBB2_8
.LBB2_10:
	mov	eax, 2
.LBB2_8:
	lea	r15, [r12 + 1]
	mov	qword ptr [rbx + 8], r15
	mov	rcx, qword ptr [rsp + 8]        # 8-byte Reload
	mov	dword ptr [rcx], eax
.LBB2_17:
	mov	qword ptr [rbx + 32], r15
	mov	rax, qword ptr [rsp + 8]        # 8-byte Reload
	mov	qword ptr [rax + 8], r12
	mov	qword ptr [rax + 16], r15
	mov	al, 1
	jmp	.LBB2_38
.LBB2_29:
	mov	rax, qword ptr [rsp + 8]        # 8-byte Reload
	mov	dword ptr [rax], 3
	jmp	.LBB2_30
	.p2align	4, 0x90
.LBB2_34:                               #   in Loop: Header=BB2_30 Depth=1
	inc	r15
	mov	qword ptr [rbx + 8], r15
	test	r14b, r14b
	je	.LBB2_17
.LBB2_30:                               # =>This Inner Loop Header: Depth=1
	cmp	r15, r13
	jae	.LBB2_17
# %bb.31:                               #   in Loop: Header=BB2_30 Depth=1
	mov	rax, qword ptr [rsp + 24]       # 8-byte Reload
	movsx	r14, byte ptr [rax + r15]
	mov	rax, qword ptr [rsp + 16]       # 8-byte Reload
	test	byte ptr [rax + 2*r14], 8
	jne	.LBB2_34
# %bb.32:                               #   in Loop: Header=BB2_30 Depth=1
	movsx	ebp, r14b
	mov	edi, ebp
	call	lexer_isop
	cmp	bpl, 95
	je	.LBB2_34
# %bb.33:                               #   in Loop: Header=BB2_30 Depth=1
	test	al, al
	jne	.LBB2_34
	jmp	.LBB2_17
.LBB2_13:
	mov	rcx, qword ptr [rsp + 8]        # 8-byte Reload
	mov	dword ptr [rcx], 4
	.p2align	4, 0x90
.LBB2_14:                               # =>This Inner Loop Header: Depth=1
	cmp	r15, r13
	jae	.LBB2_17
# %bb.15:                               #   in Loop: Header=BB2_14 Depth=1
	movsx	rcx, byte ptr [r14 + r15]
	test	byte ptr [rax + 2*rcx + 1], 8
	je	.LBB2_17
# %bb.16:                               #   in Loop: Header=BB2_14 Depth=1
	inc	r15
	mov	qword ptr [rbx + 8], r15
	test	cl, cl
	jne	.LBB2_14
	jmp	.LBB2_17
.Lfunc_end2:
	.size	lexer_lex1, .Lfunc_end2-lexer_lex1
	.cfi_endproc
                                        # -- End function
	.p2align	4, 0x90                         # -- Begin function lexer_isop
	.type	lexer_isop,@function
lexer_isop:                             # @lexer_isop
	.cfi_startproc
# %bb.0:
                                        # kill: def $edi killed $edi def $rdi
	add	edi, -36
	cmp	edi, 90
	ja	.LBB3_2
# %bb.1:
	mov	al, 1
	lea	rcx, [rip + .LJTI3_0]
	movsxd	rdx, dword ptr [rcx + 4*rdi]
	add	rdx, rcx
	jmp	rdx
.LBB3_3:
                                        # kill: def $al killed $al killed $eax
	ret
.LBB3_2:
	xor	eax, eax
                                        # kill: def $al killed $al killed $eax
	ret
.Lfunc_end3:
	.size	lexer_isop, .Lfunc_end3-lexer_isop
	.cfi_endproc
	.section	.rodata,"a",@progbits
	.p2align	2, 0x0
.LJTI3_0:
	.long	.LBB3_3-.LJTI3_0
	.long	.LBB3_3-.LJTI3_0
	.long	.LBB3_3-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_3-.LJTI3_0
	.long	.LBB3_3-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_3-.LJTI3_0
	.long	.LBB3_3-.LJTI3_0
	.long	.LBB3_3-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_3-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_3-.LJTI3_0
	.long	.LBB3_3-.LJTI3_0
	.long	.LBB3_3-.LJTI3_0
	.long	.LBB3_3-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_3-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_3-.LJTI3_0
	.long	.LBB3_2-.LJTI3_0
	.long	.LBB3_3-.LJTI3_0
                                        # -- End function
	.type	.L.str,@object                  # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"lexer_lex1"
	.size	.L.str, 11

	.ident	"clang version 17.0.6"
	.section	".note.GNU-stack","",@progbits
	.addrsig
