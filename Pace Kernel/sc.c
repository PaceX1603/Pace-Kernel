#include "sc.h"
#include "pi.h"  

void syscall_handler(int syscall_id, const char* arg) {
    switch (syscall_id) {
        case SYSCALL_PRINT:
            print(arg);
            break;
        case SYSCALL_CLEAR:
            cls();
            break;
        case SYSCALL_INPUT:
            break;
        default:
            print("Unknown syscall\n");
            break;
    }
}
