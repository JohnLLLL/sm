//
// Created by A30611 on 7/11/2019.
//

#include "sm.h"
#include <stdio.h>
#include <assert.h>

typedef enum {
    /*SYMBOL_STATE_INIT*/
    SYMBOL_STATE_S0,
    SYMBOL_STATE_S1,
    SYMBOL_STATE_ERROR,
} SYMBOL_STATE_ENUM;

SYMBOL_STATE_ENUM state = SYMBOL_STATE_S0;

void symbol_name_check(char c)
{

    switch(state) {
        case SYMBOL_STATE_S0:
            if (c == ' ')
            {
                /* Do the action */
                state = SYMBOL_STATE_S0;
            }
            else if ((c >= 'a' && c <= 'z') || \
                     (c >= 'A' && c <= 'Z'))
            {
                /* Do the action */
                printf("%c", c);
                state = SYMBOL_STATE_S1;
            }
            else /* Error case */
            {
                state = SYMBOL_STATE_ERROR;
            }
            break;
        case SYMBOL_STATE_S1:
            if (c == ' ')
            {
                /* Do the action */
                printf(" is a valid symbol\n");
                state = SYMBOL_STATE_S0;
            }
            else if ((c >= 'a' && c <= 'z') || \
                     (c >= 'A' && c <= 'Z'))
            {
                /* Do the action */
                printf("%c", c);
                state = SYMBOL_STATE_S1;
            }
            else if ((c >= '0' && c <= '9'))
            {
                /* Do the action */
                printf("%c", c);
                state = SYMBOL_STATE_S1;
            }
            else /* Error case */
            {
                state = SYMBOL_STATE_ERROR;
            }
            break;
        case SYMBOL_STATE_ERROR:
            printf("error");
            break;
        default:
            assert(0);
            break;
    }
}