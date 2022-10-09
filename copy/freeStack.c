#include "monty.h" 

void freeStack(stack_t **st)
{
	while ((*st) != NULL)
	{
		(*st) = (*st)->next;
		free(*st);
	}
}