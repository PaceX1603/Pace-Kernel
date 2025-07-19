#include "pi.h"
#include "syscall.h"
#include "sl.h" 
void kernel_main() {
    cls();                       
    print("Booting...\n");
    print("Wait A Moment...\n");
    shell();                  
}