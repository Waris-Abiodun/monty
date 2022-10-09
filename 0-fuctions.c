#include "monty.h"

/**
 * push - a function that will be use to push value on to the stack, queue
 * 
 * @st : the stack we are pushing to
 * 
 * @pusValue_n : an integer value we are adding to the stack
 */
void push(stack_t **st, unsigned int pushValue_n)
{
    stack_t *stack = malloc(sizeof(stack_t));

    if(stack == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        freeStack(st);
        exit(EXIT_FAILURE);
    }
    if((*st) == NULL)
    {
        stack->n = pushValue_n;
        stack->prev = NULL;
        stack->next = NULL;
     
    }
    else
    {
        stack->n = pushValue_n;
        stack->next = *st;
        (*st)->prev = stack;
    }
    (*st) = stack;
    
}

/**
 * pall - a function that print all the element on stack
 * 
 * @st : stack we want to print from
 * @LineCount : the line number of our file
 */
void pall(stack_t **st, unsigned int LineCount)
{
    stack_t *tmp = NULL;
    void(LineCount);

    tmp = malloc(sizeof(stack_t));
    if (tmp == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    
    tmp = (*st);
    while (tmp != NULL)
    {
        printf("%d\n", tmp->n);
        tmp = tmp->next;
    }
    free(tmp);
}

/**
void printlastelement(stack_t **st, unsigned int LineCount)
{
    unsigned int i = 1;
    stack_t *tmp = NULL;

    tmp = malloc(sizeof(stack_t));
    if (tmp = NULL)
    {
        fprintf(stderr, "Error: malloc failed");
        exit(EXIT_FAILURE);
    }
    
    tmp = (*st);
    while (tmp != NULL)
    {
        if(i == LineCount)
        {
            printf("%d\n", tmp->n);
        }
        tmp = tmp->next;
    }
}
**/

/**
 * pint - a function that print the last element on stack
 * 
 * @st : stack we want to print from
 * @LineCount : the line number of our file
 */
void pint(stack_t **st, unsigned int LineCount)
{
    if((*st) == NULL)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", LineCount);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", (*st)->n);
}

/**
 * pop - a function that remove the topmost elemt in our stack
 * 
 * @st : stack we want to print from
 * @LineCount : line of our file we are executing
 */
void pop(stack_t **st, unsigned int LineCount)
{
    if((*st) == NULL)
    {
        fprintf(stderr, "L%d: can't pop, stack empty\n", LineCount);
        exit(EXIT_FAILURE);
    }
    else if((*st)->next == NULL)
    {
        (*st) = NULL;
        free(*st);
        free(st);
    }
    else
    {
        (*st) = (*st)->next;
        (*st)->prev = NULL;
    }
}

/**
 * swap -  a function that swap the last two element of a stack, if stack less
 * than 2 , prinnt an error message and exit
 * 
 * @st : stack we want to print from
 * @LineCount : line of our file we are executing
 */
void swap(stack_t **st, unsigned int LineCount)
{
    if ((*st) == NULL || ((*st)->next == NULL))
    {
        fprintf(stderr,"L%d: can't swap, stack too short\n", LineCount);
        exit(EXIT_FAILURE);
    }
    (*st)->prev = (*st)->next;
    (*st)->next = (*st)->next->next;
    (*st)->next->prev =  (*st);
   
    (*st)->prev->next = (*st);
    (*st)->prev->prev = NULL;
   (*st) = (*st)->prev;
}
