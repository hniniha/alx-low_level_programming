#include <stdio.h>
#include <stdlib.h>

void print_opcodes(int num_bytes) {
    __asm__(
        "mov $1, %%rax\n\t"
        "mov $0, %%rdi\n\t"
        "syscall"
        :
        : "r"(num_bytes)
        : "rax", "rdi"
    );
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Error\n");
        return 1;
    }

    int num_bytes = atoi(argv[1]);

    if (num_bytes < 0) {
        printf("Error\n");
        return 2;
    }

    print_opcodes(num_bytes);

    return 0;
}

