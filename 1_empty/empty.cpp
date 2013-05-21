#define INC(x) ++(x);
int main(int argc, char *argv[])
{
    unsigned char uchar = -1;
      int i = -1;
    return INC(i);
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


//[3] to see asm and c++$ g++ -g -c -Wa,-alh empty.cpp
//  vagrant@ubuntu-oneiric:~/sandbox/cppnotes/empty$ g++ -g -c -Wa,-alh empty.cpp
//  GAS LISTING /tmp/ccEg2XkW.s 			page 1
//  
//  
//     1              		.file	"empty.cpp"
//     2              		.text
//     3              	.Ltext0:
//     4              		.globl	main
//     5              		.type	main, @function
//     6              	main:
//     7              	.LFB0:
//     8              		.file 1 "empty.cpp"
//     1:empty.cpp     **** int main(int argc, char *argv[])
//     2:empty.cpp     **** {
//     9              		.loc 1 2 0
//    10              		.cfi_startproc
//    11 0000 55       		pushq	%rbp
//    12              	.LCFI0:
//    13              		.cfi_def_cfa_offset 16
//    14              		.cfi_offset 6, -16
//    15 0001 4889E5   		movq	%rsp, %rbp
//    16              	.LCFI1:
//    17              		.cfi_def_cfa_register 6
//    18 0004 897DFC   		movl	%edi, -4(%rbp)
//    19 0007 488975F0 		movq	%rsi, -16(%rbp)
//     3:empty.cpp     ****     return 0;
//    20              		.loc 1 3 0
//    21 000b B8000000 		movl	$0, %eax
//    21      00
//     4:empty.cpp     **** }
//    22              		.loc 1 4 0
//    23 0010 5D       		popq	%rbp
//    24              	.LCFI2:
//    25              		.cfi_def_cfa 7, 8
//    26 0011 C3       		ret
//    27              		.cfi_endproc
//    28              	.LFE0:
//    29              		.size	main, .-main
//    30              	.Letext0:
//    31              		.section	.debug_info,"",@progbits
//    32              	.Ldebug_info0:
//    33 0000 85000000 		.long	0x85
//    34 0004 0200     		.value	0x2
//    35 0006 00000000 		.long	.Ldebug_abbrev0
//    36 000a 08       		.byte	0x8
//    37 000b 01       		.uleb128 0x1
//    38 000c 00000000 		.long	.LASF3
//    39 0010 04       		.byte	0x4
//    40 0011 00000000 		.long	.LASF4
//    41 0015 00000000 		.long	.LASF5
//    42 0019 00000000 		.quad	.Ltext0
//    42      00000000
//    43 0021 00000000 		.quad	.Letext0
//    43      00000000
//    44 0029 00000000 		.long	.Ldebug_line0
//    45 002d 02       		.uleb128 0x2
//    46 002e 01       		.byte	0x1
//    47 002f 00000000 		.long	.LASF6
//    48 0033 01       		.byte	0x1
//    49 0034 01       		.byte	0x1
//    50 0035 6E000000 		.long	0x6e
//  
//  GAS LISTING /tmp/ccEg2XkW.s 			page 2
//  
//  
//    51 0039 00000000 		.quad	.LFB0
//    51      00000000
//    52 0041 00000000 		.quad	.LFE0
//    52      00000000
//    53 0049 00000000 		.long	.LLST0
//    54 004d 6E000000 		.long	0x6e
//    55 0051 03       		.uleb128 0x3
//    56 0052 00000000 		.long	.LASF0
//    57 0056 01       		.byte	0x1
//    58 0057 01       		.byte	0x1
//    59 0058 6E000000 		.long	0x6e
//    60 005c 02       		.byte	0x2
//    61 005d 91       		.byte	0x91
//    62 005e 6C       		.sleb128 -20
//    63 005f 03       		.uleb128 0x3
//    64 0060 00000000 		.long	.LASF1
//    65 0064 01       		.byte	0x1
//    66 0065 01       		.byte	0x1
//    67 0066 75000000 		.long	0x75
//    68 006a 02       		.byte	0x2
//    69 006b 91       		.byte	0x91
//    70 006c 60       		.sleb128 -32
//    71 006d 00       		.byte	0
//    72 006e 04       		.uleb128 0x4
//    73 006f 04       		.byte	0x4
//    74 0070 05       		.byte	0x5
//    75 0071 696E7400 		.string	"int"
//    76 0075 05       		.uleb128 0x5
//    77 0076 08       		.byte	0x8
//    78 0077 7B000000 		.long	0x7b
//    79 007b 05       		.uleb128 0x5
//    80 007c 08       		.byte	0x8
//    81 007d 81000000 		.long	0x81
//    82 0081 06       		.uleb128 0x6
//    83 0082 01       		.byte	0x1
//    84 0083 06       		.byte	0x6
//    85 0084 00000000 		.long	.LASF2
//    86 0088 00       		.byte	0
//    87              		.section	.debug_abbrev,"",@progbits
//    88              	.Ldebug_abbrev0:
//    89 0000 01       		.uleb128 0x1
//    90 0001 11       		.uleb128 0x11
//    91 0002 01       		.byte	0x1
//    92 0003 25       		.uleb128 0x25
//    93 0004 0E       		.uleb128 0xe
//    94 0005 13       		.uleb128 0x13
//    95 0006 0B       		.uleb128 0xb
//    96 0007 03       		.uleb128 0x3
//    97 0008 0E       		.uleb128 0xe
//    98 0009 1B       		.uleb128 0x1b
//    99 000a 0E       		.uleb128 0xe
//   100 000b 11       		.uleb128 0x11
//   101 000c 01       		.uleb128 0x1
//   102 000d 12       		.uleb128 0x12
//   103 000e 01       		.uleb128 0x1
//   104 000f 10       		.uleb128 0x10
//   105 0010 06       		.uleb128 0x6
//  
//  GAS LISTING /tmp/ccEg2XkW.s 			page 3
//  
//  
//   106 0011 00       		.byte	0
//   107 0012 00       		.byte	0
//   108 0013 02       		.uleb128 0x2
//   109 0014 2E       		.uleb128 0x2e
//   110 0015 01       		.byte	0x1
//   111 0016 3F       		.uleb128 0x3f
//   112 0017 0C       		.uleb128 0xc
//   113 0018 03       		.uleb128 0x3
//   114 0019 0E       		.uleb128 0xe
//   115 001a 3A       		.uleb128 0x3a
//   116 001b 0B       		.uleb128 0xb
//   117 001c 3B       		.uleb128 0x3b
//   118 001d 0B       		.uleb128 0xb
//   119 001e 49       		.uleb128 0x49
//   120 001f 13       		.uleb128 0x13
//   121 0020 11       		.uleb128 0x11
//   122 0021 01       		.uleb128 0x1
//   123 0022 12       		.uleb128 0x12
//   124 0023 01       		.uleb128 0x1
//   125 0024 40       		.uleb128 0x40
//   126 0025 06       		.uleb128 0x6
//   127 0026 01       		.uleb128 0x1
//   128 0027 13       		.uleb128 0x13
//   129 0028 00       		.byte	0
//   130 0029 00       		.byte	0
//   131 002a 03       		.uleb128 0x3
//   132 002b 05       		.uleb128 0x5
//   133 002c 00       		.byte	0
//   134 002d 03       		.uleb128 0x3
//   135 002e 0E       		.uleb128 0xe
//   136 002f 3A       		.uleb128 0x3a
//   137 0030 0B       		.uleb128 0xb
//   138 0031 3B       		.uleb128 0x3b
//   139 0032 0B       		.uleb128 0xb
//   140 0033 49       		.uleb128 0x49
//   141 0034 13       		.uleb128 0x13
//   142 0035 02       		.uleb128 0x2
//   143 0036 0A       		.uleb128 0xa
//   144 0037 00       		.byte	0
//   145 0038 00       		.byte	0
//   146 0039 04       		.uleb128 0x4
//   147 003a 24       		.uleb128 0x24
//   148 003b 00       		.byte	0
//   149 003c 0B       		.uleb128 0xb
//   150 003d 0B       		.uleb128 0xb
//   151 003e 3E       		.uleb128 0x3e
//   152 003f 0B       		.uleb128 0xb
//   153 0040 03       		.uleb128 0x3
//   154 0041 08       		.uleb128 0x8
//   155 0042 00       		.byte	0
//   156 0043 00       		.byte	0
//   157 0044 05       		.uleb128 0x5
//   158 0045 0F       		.uleb128 0xf
//   159 0046 00       		.byte	0
//   160 0047 0B       		.uleb128 0xb
//   161 0048 0B       		.uleb128 0xb
//   162 0049 49       		.uleb128 0x49
//  
//  GAS LISTING /tmp/ccEg2XkW.s 			page 4
//  
//  
//   163 004a 13       		.uleb128 0x13
//   164 004b 00       		.byte	0
//   165 004c 00       		.byte	0
//   166 004d 06       		.uleb128 0x6
//   167 004e 24       		.uleb128 0x24
//   168 004f 00       		.byte	0
//   169 0050 0B       		.uleb128 0xb
//   170 0051 0B       		.uleb128 0xb
//   171 0052 3E       		.uleb128 0x3e
//   172 0053 0B       		.uleb128 0xb
//   173 0054 03       		.uleb128 0x3
//   174 0055 0E       		.uleb128 0xe
//   175 0056 00       		.byte	0
//   176 0057 00       		.byte	0
//   177 0058 00       		.byte	0
//   178              		.section	.debug_loc,"",@progbits
//   179              	.Ldebug_loc0:
//   180              	.LLST0:
//   181 0000 00000000 		.quad	.LFB0-.Ltext0
//   181      00000000
//   182 0008 01000000 		.quad	.LCFI0-.Ltext0
//   182      00000000
//   183 0010 0200     		.value	0x2
//   184 0012 77       		.byte	0x77
//   185 0013 08       		.sleb128 8
//   186 0014 01000000 		.quad	.LCFI0-.Ltext0
//   186      00000000
//   187 001c 04000000 		.quad	.LCFI1-.Ltext0
//   187      00000000
//   188 0024 0200     		.value	0x2
//   189 0026 77       		.byte	0x77
//   190 0027 10       		.sleb128 16
//   191 0028 04000000 		.quad	.LCFI1-.Ltext0
//   191      00000000
//   192 0030 11000000 		.quad	.LCFI2-.Ltext0
//   192      00000000
//   193 0038 0200     		.value	0x2
//   194 003a 76       		.byte	0x76
//   195 003b 10       		.sleb128 16
//   196 003c 11000000 		.quad	.LCFI2-.Ltext0
//   196      00000000
//   197 0044 12000000 		.quad	.LFE0-.Ltext0
//   197      00000000
//   198 004c 0200     		.value	0x2
//   199 004e 77       		.byte	0x77
//   200 004f 08       		.sleb128 8
//   201 0050 00000000 		.quad	0
//   201      00000000
//   202 0058 00000000 		.quad	0
//   202      00000000
//   203              		.section	.debug_aranges,"",@progbits
//   204 0000 2C000000 		.long	0x2c
//   205 0004 0200     		.value	0x2
//   206 0006 00000000 		.long	.Ldebug_info0
//   207 000a 08       		.byte	0x8
//   208 000b 00       		.byte	0
//   209 000c 0000     		.value	0
//  
//  GAS LISTING /tmp/ccEg2XkW.s 			page 5
//  
//  
//   210 000e 0000     		.value	0
//   211 0010 00000000 		.quad	.Ltext0
//   211      00000000
//   212 0018 12000000 		.quad	.Letext0-.Ltext0
//   212      00000000
//   213 0020 00000000 		.quad	0
//   213      00000000
//   214 0028 00000000 		.quad	0
//   214      00000000
//   215              		.section	.debug_line,"",@progbits
//   216              	.Ldebug_line0:
//   217 0000 39000000 		.section	.debug_str,"MS",@progbits,1
//   217      02002000
//   217      00000101
//   217      FB0E0D00
//   217      01010101
//   218              	.LASF1:
//   219 0000 61726776 		.string	"argv"
//   219      00
//   220              	.LASF5:
//   221 0005 2F686F6D 		.string	"/home/vagrant/sandbox/cppnotes/empty"
//   221      652F7661
//   221      6772616E
//   221      742F7361
//   221      6E64626F
//   222              	.LASF3:
//   223 002a 474E5520 		.string	"GNU C++ 4.6.1"
//   223      432B2B20
//   223      342E362E
//   223      3100
//   224              	.LASF0:
//   225 0038 61726763 		.string	"argc"
//   225      00
//   226              	.LASF4:
//   227 003d 656D7074 		.string	"empty.cpp"
//   227      792E6370
//   227      7000
//   228              	.LASF6:
//   229 0047 6D61696E 		.string	"main"
//   229      00
//   230              	.LASF2:
//   231 004c 63686172 		.string	"char"
//   231      00
//   232              		.ident	"GCC: (Ubuntu/Linaro 4.6.1-9ubuntu3) 4.6.1"
//   233              		.section	.note.GNU-stack,"",@progbits
//  
//   vagrant@ubuntu-oneiric:~/sandbox/cppnotes/empty$
