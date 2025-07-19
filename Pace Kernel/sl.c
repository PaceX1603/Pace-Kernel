#include "sc.h"
#include "pi.h"
#include <string.h>  
void shell() {
    char buffer[128];
    print("Pace SHELL\n");
    print("Type 'help' for a list of commands.\n\n");
    while (1) {
        print("> ");
        gets(buffer, sizeof(buffer));
        if (strcmp(buffer, "help") == 0) {
            print("Available commands:\n");
            print(" - help\n");
            print(" - clear\n");
            print(" - out [text]\n");
            print(" - removal\n");
        } else if (strcmp(buffer, "clear") == 0) {
            syscall_handler(SYSCALL_CLEAR, 0);
        } else if (strncmp(buffer, "out ", 4) == 0) {
            syscall_handler(SYSCALL_PRINT, buffer + 4);
        } else if (strcmp(buffer, "removal") == 0) {
            print("System removal not available yet!\n");
        } else {
            print("Unknown command.\n");
        }
    }
}
