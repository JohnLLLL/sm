#include <stdio.h>
#include <malloc.h>
#include "sm.h"
#include "input.h"

int main() {
    int loop;
    const char* input;
    printf("Hello, World!\n");

    input = read_input();

    printf("%s\n", input);

    loop = 0;
    while(1)
    {
        if(input[loop])
        {
            loop++;
        }
        else
        {
            break;
        }
    }

    free((void*)input);

    return 0;
}