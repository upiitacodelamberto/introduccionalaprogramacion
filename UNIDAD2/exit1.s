.code32
.section .data
.byte bufmsg

.section .text
.globl exit
exit:
movl $1,%eax
movl $0xff,%ebx
int $0x80

