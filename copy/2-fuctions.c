#include "monty.h"

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

/**
 * pchar - a function that print the ascii value of the int at the top of stack
 * 
 * @st : stack we want to print from
 * @LineCount : line of our file we are executing
 */
void pchar(stack_t **st, unsigned int LineCount)
{
    if((*st) == NULL)
    {
        fprintf(stderr, "L%d: can't pchar, stack empty\n", LineCount);
        exit(EXIT_FAILURE);
    }
    else if ( (*st)->n >= 0  && (*st)->n <  128)
    {
        printf("%c\n", (*st)->n);
    }
    else
    {
        fprintf(stderr, "L%d: can't pchar, value out of range\n", LineCount);
        exit(EXIT_FAILURE);
    }
}

/**
 * pstr - a function that print the ascii value of the int at the top of stack
 * 
 * @st : stack we want to print from
 * @LineCount : line of our file we are executing
 */
void pstr(stack_t **st, unsigned int LineCount)
{
    stack_t *tmp = NULL;
    (void)LineCount;
    tmp = malloc(sizeof(stack_t));

    if (tmp == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    
    tmp = (*st);
    while (tmp != NULL)
    {
        if ( tmp->n > 0  && tmp->n <  128)
        {
            printf("%c", tmp->n);
            tmp = tmp->next;
        }
        else
        {
            break;
        }
    }
    printf("\n");
}