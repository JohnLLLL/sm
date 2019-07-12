#include <stdio.h>
#include <malloc.h>
#include "sm.h"
#include "input.h"

int main() {
    int loop;
    const char* input;
    printf("State Machine Coding!\n");

    input = read_input();

    printf("input: %s\n", input);

    loop = 0;
    while(1)
    {
        symbol_name_check(input[loop]);
        loop++;

        if(!input[loop])
        {
            break;
        }
    }

    printf("end\n");
    free((void*)input);

    return 0;
}