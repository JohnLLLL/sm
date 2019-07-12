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

        if(!input[loop])
        {
            break;
        }

        loop++;
    }

    printf("end\n");
    free((void*)input);

    return 0;
}