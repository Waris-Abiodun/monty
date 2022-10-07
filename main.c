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
       checkAndRunOpcode(&st, ReadFromTheFile, Line_Count);
      
       
   }

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
        {"push", NULL},
        {"pall", NULL},
        {NULL, NULL}
    };
    tokens = gettokens(ReadFromTheFile);
    printf("<<<%s\n", options[i].opcode);
    printf("%s<<<<<<<\n", tokens[0]);

    while (options[i].opcode != NULL)
    {
        if(strcmp(options[i].opcode, tokens[0] )== 0)
        {
            if(i = 0)
            {
                CheckPush(stack_t **st, char *tokens, unsigned int Line_Count);
            }
            else
            {
                printf("others");
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
    return (tokens);
}
void CheckPush(stack_t **st, char *tokens, unsigned int Line_Count)
{
    if(isdigit(tokens[1]) != 0)
    {
        printf("push an intger to the task");
    }
    else if
    {
        fprintf("L%d: usage: push integer\n", Line_Count);
        exit(EXIT_FAILURE);
    }
}