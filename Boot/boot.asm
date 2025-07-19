[org 0x7C00]
bits 16
start:
mov ah,0x0E
mov al,'B'
int 0x10
mov al,'O'
int 0x10
mov al,'O'
int 0x10
mov al,'T'
int 0x10
mov al,'I'
int 0x10
mov al,'N'
int 0x10
mov al,'G'
int 0x10
mov al,'.'
int 0x10
mov al,'.'
int 0x10
mov al,'.'
int 0x10
jmp$ 0x05201
times 510 - ( $$ - $ ) db 0