int main(int argc, char *argv[])
{
	int iv = 3;
	int &riv = iv;
	riv = 4;

	// mov	DWORD PTR [rbp-20], edi	# argc, argc
	// mov	QWORD PTR [rbp-32], rsi	# argv, argv
	// mov	DWORD PTR [rbp-4], 3	# iv,
	// lea	rax, [rbp-4]	# tmp61,
	// mov	QWORD PTR [rbp-16], rax	# riv, tmp61
	// mov	rax, QWORD PTR [rbp-16]	# tmp62, riv
	// mov	DWORD PTR [rax], 4	# *riv_1,
	// mov	eax, 0	# D.2071,
	// pop	rbp	#
	
    return 0;
}

//[1] to see temp files during compile$ g++ -save-temps -fverbose-asm -masm=intel empty.cpp 
//  empty.ii :macro expanded version
//  empty.s  :asm version

//[2]  vagrant@ubuntu-oneiric:~/sandbox/cppnotes/empty$ objdump -d empty.o
//  
//  empty.o:     file format elf64-x86-64
//  
//  
//  Disassembly of section .text:
//  
//  0000000000000000 <main>:
//     0:	55                   	push   %rbp
//     1:	48 89 e5             	mov    %rsp,%rbp
//     4:	89 7d fc             	mov    %edi,-0x4(%rbp)
//     7:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
//     b:	b8 00 00 00 00       	mov    $0x0,%eax
//    10:	5d                   	pop    %rbp
//    11:	c3                   	retq
//  vagrant@ubuntu-oneiric:~/sandbox/cppnotes/empty$

