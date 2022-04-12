	.text
format: .asciz  "%d %d %d\n"   
	.globl  print_fib

print_fib:
        pushl   %ebp
        movl    %esp, %ebp
        pushl   %ebx
        movl    A, %ebx
        addl    B, %ebx
        movl    %ebx, %edx
        addl    B, %edx
        movl    %ebx, %eax
        addl    %edx, %eax
        pushl   %eax
        pushl   %edx
        pushl   %ebx
        pushl   $format
        call    printf
        addl    $16, %esp
        popl    %ebx
        movl    %ebp, %esp
        popl    %ebp
	ret
