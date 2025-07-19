#ifndef SYSCALL_H
#define SYSCALL_H
#define SYSCALL_PRINT 0
#define SYSCALL_CLEAR 1
#define SYSCALL_INPUT 2
void syscall_handler(int syscall_id, const char* arg);
#endif
