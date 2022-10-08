#include "monty.h"

/**
 * add - a function that remove the topmost elemt in our stack and
 * add it to the next elemt in the stack, if stack less than 2 print error message
 * 
 * @st : stack we want to print from
 * @LineCount : line of our file we are executing
 */
void add(stack_t **st, unsigned int LineCount)
{
    if ((*st) == NULL || ((*st)->next == NULL))
    {
        fprintf(stderr,"L%d: can't add, stack too short\n", LineCount);
        exit(EXIT_FAILURE);
    }
    int c = (*st)->n;
    (*st) = (*st)->next;
    (*st)->n += c;
    (*st)->prev = NULL;
}

/**
 * nop - a function  that doesnt do anything
 * 
 * @st : stack we want to print from
 * @LineCount : line of our file we are executing
 */
void nop(stack_t **st, unsigned int LineCount)
{
    LineCount = LineCount;
    (*st) = (*st);
}