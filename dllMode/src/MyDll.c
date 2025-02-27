#include "MyDll.h"
#include <stdio.h>

void my_function(void) {
    printf("Hello from DLL!\n");
}

int add(int a, int b) {
    return a + b;
}
