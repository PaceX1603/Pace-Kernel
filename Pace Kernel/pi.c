void print(const char * habibi){ 
    char* inra = (char*) 0xB8000; 
    for(int i=0;habibi[i] !='\0';i++){ 
        inra[ i * 2 ] = habibi[i]; 
        inra[ i * 2 +1 ] = 0x07;
    }
}
void cls() {
    char* video = (char*) 0xB8000;
    for (int i = 0; i < 80 * 25 * 2; i += 2) {
        video[i] = ' ';
        video[i + 1] = 0x07;
    }
}
void print_at(int x, int y, const char* str) {
    char* video = (char*) 0xB8000 + (y * 80 + x) * 2;
    for (int i = 0; str[i] != '\0'; i++) {
        video[i * 2] = str[i];
        video[i * 2 + 1] = 0x07;
    }
}
int x = 0;
int y = 0;
void putchar(char c) {
    char* video = (char*) 0xB8000;
    if (c == '\n') {
        x = 0;
        y++;
    } else {
        int offset = (y * 80 + x) * 2;
        video[offset] = c;
        video[offset + 1] = 0x07;
        x++;
        if (x >= 80) {
            x = 0;
            y++;
        }
    }
}
void printh(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        putchar(str[i]);
    }
}
void printf(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        putchar(str[i]);
    }
}
void printk(const char * habibi){ 
    char* inra = (char*) 0xB8000; 
    for(int i=0;habibi[i] !='\0';i++){ 
        inra[ i * 2 ] = habibi[i]; 
        inra[ i * 2 +1 ] = 0x07;
    }
}
void cls() {
    char* video = (char*) 0xB8000;
    for (int i = 0; i < 80 * 25 * 2; i += 2) {
        video[i] = ' ';
        video[i + 1] = 0x07;
    }
}
void print_at(int x, int y, const char* str) {
    char* video = (char*) 0xB8000 + (y * 80 + x) * 2;
    for (int i = 0; str[i] != '\0'; i++) {
        video[i * 2] = str[i];
        video[i * 2 + 1] = 0x07;
    }
}
int x = 0;
int y = 0;
void putchar(char c) {
    char* video = (char*) 0xB8000;
    if (c == '\n') {
        x = 0;
        y++;
    } else {
        int offset = (y * 80 + x) * 2;
        video[offset] = c;
        video[offset + 1] = 0x07;
        x++;
        if (x >= 80) {
            x = 0;
            y++;
        }
    }
}
unsigned char inb(unsigned short port) {
    unsigned char result;
    __asm__ volatile ("inb %1, %0" : "=a"(result) : "Nd"(port));
    return result;
}

char scancode_to_char(unsigned char scancode) {
    switch (scancode) {
        case 0x1E: return 'a';
        case 0x30: return 'b';
        case 0x2E: return 'c';
        case 0x20: return 'd';
        case 0x12: return 'e';
        case 0x21: return 'f';
        case 0x22: return 'g';
        case 0x23: return 'h';
        case 0x17: return 'i';
        case 0x24: return 'j';
        case 0x25: return 'k';
        case 0x26: return 'l';
        case 0x32: return 'm';
        case 0x31: return 'n';
        case 0x18: return 'o';
        case 0x19: return 'p';
        case 0x10: return 'q';
        case 0x13: return 'r';
        case 0x1F: return 's';
        case 0x14: return 't';
        case 0x16: return 'u';
        case 0x2F: return 'v';
        case 0x11: return 'w';
        case 0x2D: return 'x';
        case 0x15: return 'y';
        case 0x2C: return 'z';
        case 0x39: return ' ';
        case 0x1C: return '\n';
        default: return 0;
    }
}

char getchar() {
    unsigned char scancode = inb(0x60);
    char key = scancode_to_char(scancode);
    while (key == 0) {
        scancode = inb(0x60);
        key = scancode_to_char(scancode);
    }
    return key;
}
void gets(char* buffer, int maxlen) {
    int i = 0;
    while (i < maxlen - 1) {
        char c = getchar();
        if (c == '\n') {
            putchar('\n');
            break;
        }
        buffer[i++] = c;
        putchar(c); 
    }
    buffer[i] = '\0'; 
    }
