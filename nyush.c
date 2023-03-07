/* Melanie Zhang
 * Operating Systems Spring 2023
 * Lab 2: NYUSH
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <unistd.h>
#include <libgen.h>

#define MAX_COMMAND 1000
#define MAX_ARGS 100

void printPrompt(){
    char directory[1024];
    char * directory_base = NULL;
    getcwd(directory, sizeof(directory));
    // only get directory base name
    directory_base = basename(directory);
    printf("\n[nyush %s]$ ", directory_base);
    // flush STDOUT
    fflush(stdout);
}
//take input
char* getInput(){
    char *buffer;
    size_t size = 32;
    size_t user_input;
    buffer = (char *) malloc(size * sizeof(char));

    if (buffer == NULL){
        perror("Error: Could not allocate buffer.");
        exit(1);
    }

    user_input = getline(&buffer,&size,stdin);
    printf("%s", buffer);

    return buffer;
}
// int builtInCommands(char ** parsed){
//     int commandCount = 4;
// }
//execute system commands
void executeSys(char** parsed){
    pid_t pid = fork();

    if (pid < 0){
        perror("Error: Fork failed.");
        exit(1);
    } else if (pid == 0){
        if (execvp(parsed[0], parsed) == -1){
            perror("Error: invalid command");
        }
    } else {
        //waitpid(-1,)
    }
}

// separate args based on spaces
char** parseCommands(char * string){
    char ** parsed = malloc(1000);
    for (int i = 0; i < MAX_ARGS; i++){
        parsed[i] = strsep(&string, " ");
            if (parsed[i] == NULL){
                break;
            } else if (strlen(parsed[i]) == 0){
                i--;
            } else {
                printf("%s\n", parsed[i]);
            }
        }
    return parsed;
}



//execute pipe

//execute built in commands

//parse pipe

//parse command words

//parse all (calls previous parse functions)

int main()
{
    char *line;
    char **args;

    while (1){
        printPrompt();
        line = getInput();
        args = parseCommands(line);
    }

}
