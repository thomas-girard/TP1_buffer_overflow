# TP1_buffer_overflow

1.

* rax is the 64-bit, "long" size register. It was added in 2003 during the transition to 64-bit processors. eax is the 32-bit
* gcc -m32 charge.c -z execstack -o charge


2.

* le shellcode est en 64 bits
* gcc -g -m32 -z execstack -fno-stack-protector vulnerable.c -o vulnerable


