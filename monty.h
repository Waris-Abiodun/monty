#ifndef MONTY_H
#define MONTY_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/** function that wil help us run the file (main.c) **/
void checkAndRunOpcode(stack_t **st, char * ReadFromTheFile, unsigned int Line_Count);
char **gettokens(char *ReadFromTheFile);

/** push functions (main.c and 1.functions.c) **/
void push(stack_t **st, unsigned int pushValue_n);
void CheckPush(stack_t **st, char **tokens, unsigned int Line_Count);
int _isdigit(int PushValue_n);

/** functions to execute the instruction from the users (0-functions.c)**/
void pall(stack_t **st, unsigned int LineCount);
void pint(stack_t **st, unsigned int LineCount);
void pop(stack_t **st, unsigned int LineCount);
void swap(stack_t **st, unsigned int LineCount);

/** functions to execute the instruction from the users (1-functions.c)**/
void add(stack_t **st, unsigned int LineCount);
void nop(stack_t **st, unsigned int LineCount);


/* a function that free all the stacks we used (freeStack.c)*/
void freeStack(stack_t **st);
#endif /** MONTY_H **/