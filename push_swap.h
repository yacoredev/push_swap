#ifndef PUSH_SWAP
# define PUSH_SWAP

#include <stdlib.h>

typedef struct s_stack
{
    int value;
    struct s_stack  *next;
}   t_stack;


#endif