// gcc ./example_00.c -o example_00 -no-pie

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *buffer1;
    char *buffer2;

    buffer1 = malloc(100);
    printf("Buffer1[%p]\t\t: %s\n", buffer1, buffer1);
    memset(buffer1, 'A', 99);
    printf("Init. Buffer1[%p]\t: %s\n", buffer1, buffer1);
    free(buffer1);

    puts("");

    printf("Freed Buffer1[%p]\t: %s\n", buffer1+8, buffer1+8);

    buffer2 = malloc(100);
    printf("Buffer2[%p]\t\t: %s\n", buffer2, buffer2);
    printf("Freed Buffer1[%p]\t: %s\n", buffer1+8, buffer1+8);
    
    puts("");

    memset(buffer2, 'B', 99);
    printf("Init. Buffer2[%p]\t: %s\n", buffer2, buffer2);
    printf("Freed Buffer1[%p]\t: %s\n", buffer1+8, buffer1+8);
    
    return 0;
}