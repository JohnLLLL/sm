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

void __symbol_name_char(char c)
{
    switch(state) {
        case SYMBOL_STATE_S0:
            state = SYMBOL_STATE_S1;
        case SYMBOL_STATE_S1:
            /* Do the action */
            printf("%c", c);
            break;
        case SYMBOL_STATE_ERROR:
            printf("%c", c);
            break;
        default:
            assert(0);
            break;
    }
}

void __symbol_name_space(char c)
{
    switch(state) {
        case SYMBOL_STATE_S0:
            break;
        case SYMBOL_STATE_S1:
            /* Do the action */
            printf(" is a valid symbol\n");
            state = SYMBOL_STATE_S0;
            break;
        case SYMBOL_STATE_ERROR:
            printf(" is not a valid symbol\n");
            state = SYMBOL_STATE_S0;
            break;
        default:
            assert(0);
            break;
    }
}

void __symbol_name_number(char c)
{
    switch(state) {
        case SYMBOL_STATE_S0:
            printf("%c", c);
            state = SYMBOL_STATE_ERROR;
            break;
        case SYMBOL_STATE_S1:
            /* Do the action */
            printf("%c", c);
            break;
        case SYMBOL_STATE_ERROR:
            printf("%c", c);
            break;
        default:
            assert(0);
            break;
    }
}

void __symbol_name_underscore(char c)
{

}

void __symbol_name_invalid(char c)
{

}

void __symbol_name_eof(char c)
{
    switch(state) {
        case SYMBOL_STATE_S0:
            break;
        case SYMBOL_STATE_S1:
            /* Do the action */
            printf(" is a valid symbol\n");
            break;
        case SYMBOL_STATE_ERROR:
            printf(" is not a valid symbol\n");
            break;
        default:
            assert(0);
            break;
    }
}

void symbol_name_check(char c)
{
    if (c == ' ')
    {
        __symbol_name_space(c);
    }
    else if ((c >= 'a' && c <= 'z') || \
                     (c >= 'A' && c <= 'Z'))
    {
        __symbol_name_char(c);
    }
    else if ((c >= '0' && c <= '9'))
    {
        __symbol_name_number(c);
    }
    else if (c == '\0')
    {
        __symbol_name_eof(c);
    }
    else /* Invalid character */
    {
        __symbol_name_invalid(c);
    }
}