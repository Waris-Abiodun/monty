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
    int c;
    if ((*st) == NULL || ((*st)->next == NULL))
    {
        fprintf(stderr,"L%d: can't add, stack too short\n", LineCount);
        exit(EXIT_FAILURE);
    }
    c = (*st)->n;
    (*st) = (*st)->next;
    (*st)->n += c;
    (*st)->prev = NULL;
}
/**
 * sub - a function that remove the topmost elemt in our stack and
 * subtract it from the next elemt in the stack, if stack less than 2 print error message
 * 
 * @st : stack we want to print from
 * @LineCount : line of our file we are executing
 */
void sub(stack_t **st, unsigned int LineCount)
{
    int c;
    if ((*st) == NULL || ((*st)->next == NULL))
    {
        fprintf(stderr,"L%d: can't sub, stack too short\n", LineCount);
        exit(EXIT_FAILURE);
    }
    c = (*st)->n;
    (*st) = (*st)->next;
    (*st)->n -= c;
    (*st)->prev = NULL;
}

/**
 * mul - a function that remove the topmost elemt in our stack and
 * multiply it to the next elemt in the stack, if stack less than 2 print error message
 * 
 * @st : stack we want to print from
 * @LineCount : line of our file we are executing
 */
void mul(stack_t **st, unsigned int LineCount)
{
    int c;
    if ((*st) == NULL || ((*st)->next == NULL))
    {
        fprintf(stderr,"L%d: can't mul, stack too short\n", LineCount);
        exit(EXIT_FAILURE);
    }
    c = (*st)->n;
    (*st) = (*st)->next;
    (*st)->n *= c;
    (*st)->prev = NULL;
}

/**
 * div - a function that remove the topmost elemt in our stack and
 * divide it with elemt in the stack, if stack less than 2 print error message
 * 
 * @st : stack we want to print from
 * @LineCount : line of our file we are executing
 */
void Div(stack_t **st, unsigned int LineCount)
{
    int c;
    if ((*st) == NULL || ((*st)->next == NULL))
    {
        fprintf(stderr,"L%d: can't div, stack too short\n", LineCount);
        exit(EXIT_FAILURE);
    }
    
    c = (*st)->n;
    if (c == 0)
    {
        
        fprintf(stderr,"L%d: division by zero\n", LineCount);
        exit(EXIT_FAILURE);
    }
    (*st) = (*st)->next;
    (*st)->n /= c;
    (*st)->prev = NULL;
}

/**
 * mod - a function that remove the topmost elemt in our stack and
 * find the modulos from the next elemt in the stack, if stack less than 2 print error message
 * 
 * @st : stack we want to print from
 * @LineCount : line of our file we are executing
 */
void mod(stack_t **st, unsigned int LineCount)
{
    int c;
    if ((*st) == NULL || ((*st)->next == NULL))
    {
        fprintf(stderr,"L%d: can't mul, stack too short\n", LineCount);
        exit(EXIT_FAILURE);
    }
    c = (*st)->n;
    if (c == 0)
    {
        
        fprintf(stderr,"L%d: division by zero\n", LineCount);
        exit(EXIT_FAILURE);
    }
    
    (*st) = (*st)->next;
    (*st)->n %= c;
    (*st)->prev = NULL;
}
