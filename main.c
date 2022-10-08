#include "monty.h"
/**
 * main - a function that read a file from CLI and execute the commands
 * 
 * @argc : it check the number of argument which has to be 2
 * @argv : the file path
 * Return : 0 on succcess, exit on failure 
 */

int main(int argc, char **argv)
{
	FILE *fd = NULL;
	char *ReadFromTheFile = NULL;
	size_t n;
	unsigned int Line_Count = 0;
    char *token;
    int chs;
    stack_t *st = NULL;
   if (argc != 2)
   {
       fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
   }

   fd = fopen(argv[1], "r");
   if (!fd)
   {
       fprintf(stderr, "Cant open file %s\n", argv[1]);
       exit(EXIT_FAILURE);
   }
   while(getline(&ReadFromTheFile, &n, fd) != -1)
   {
       Line_Count++;
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>");
       checkAndRunOpcode(&st, ReadFromTheFile, Line_Count);
      
       
   }
   fclose(fd);

   return (1);

}

/**
 * checkAndRunOpcode - this is the beginning of execute the command inside the
 * file, the instruction that is read from the file will be tokenized/ split 
 * into words, then we will read the first word, if the command is found
 * we will execute the commamnd if it is not found we will print an error
 * message , and stop the program 
 * 
 * @st : if command found we will use this as our stack/queue 
 * @ReadFromTheFile : line by line instruction to be executed
 * @Line_Count : this help us keep track of the line we are executing so 
 * if error is found we can return the line number
 */
void checkAndRunOpcode(stack_t **st, char * ReadFromTheFile, unsigned int Line_Count)
{
    char **tokens;
    int i = 0;
    int NotFound= 1;

    instruction_t options[] = {
        {"push", push},
        {"pall", pall},
        {"pint", pint},
        {"pop", pop},
        {"swap", swap},
        {"add", add},
        {"nop", nop},
        {NULL, NULL}
    };
    tokens = gettokens(ReadFromTheFile);

    while (options[i].opcode != NULL)
    {
        if(strcmp(options[i].opcode, tokens[0] )== 0)
        {
            NotFound = 0;
            if(i == 0)
            {
                
                CheckPush(st, tokens, Line_Count);
            }
            else
            {
               options[i].f(st, Line_Count);
            }
           
            break;
        }
        i++;
    }

    if (NotFound == 1)
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", Line_Count, tokens[0]);
        free(tokens);
        exit(EXIT_FAILURE);
    }
    free(tokens);
    
}
/**
 * gettokens - function that will split line/sentence into words
 * 
 * @ReadFromTheFile: line to read from
 * Return: the first two words,
 */

char **gettokens(char *ReadFromTheFile)
{
    char *token;
    char **tokens;
    int i = 0;
    tokens = malloc((sizeof(char *) * 3));
    if (tokens == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    token = strtok(ReadFromTheFile, " \n\t");

    while(token != NULL & i < 2)
    {
        tokens[i] = token;
        i++;
        token = strtok(NULL, " \n\t");
    }
    tokens[i] = NULL;
    free(token);
    return (tokens);
}
/**
 * CheckPush - a function that check if the second argument is an integer 
 * before passing it to push function
 * @st : we will add the value of the integer we checked to this stack
 * @tokens: the first two tokens/ words, one is "push" the other is an "int"
 * @Line_Count : number of line of our file we are executing
 */
void CheckPush(stack_t **st, char **tokens, unsigned int Line_Count)
{
    char *PushValue;
    int i = 0;

    PushValue = tokens[1];
    /** pushValue is a string of character, so we will check each character **/
    if (PushValue == NULL)
    {
        fprintf(stderr, "L%d: usage: push integer\n", Line_Count);
        exit(EXIT_FAILURE);
    }
    while(PushValue[i] != '\0')
    {
        if(PushValue[0] == '-' && i == 0);
        else if(_isdigit(PushValue[i]) != 0)
        {
            fprintf(stderr, "L%d: usage: push integer\n", Line_Count);
            exit(EXIT_FAILURE);
        }
        i++;
    }
    push(st, atoi(PushValue));
    
    free(tokens);
 
}

/**
 * _isdigit - a function to test if the value passed is an integer or not
 * 
 * @PushValue: the value received from Checkpush will be test 
 * Return: 0 if it is an integer , 1 if it is not
 */
int _isdigit(int PushValue)
{
	if (PushValue >= 48 && PushValue <= 57)
	{
		return (0);
	}
	return (1);
}
