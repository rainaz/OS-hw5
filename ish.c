#include "ish.h"
int main(int argc, char** argv){
	char command[MAXLEN];
	char **arguments;
	char *temp;
	int parse;
	const char *home = getenv("HOME");
	char PROMPT[50];
	strcpy(PROMPT, "5431040021 > ");
	setenv("PROMPT",PROMPT,1);
	for(;;){
		fprintf(stdout, "%s",getenv("PROMPT"));
		fgets(command, MAXLEN, stdin);
		if(strcmp(command,EXIT)==0){
			fprintf(stdout,"Exit Now\n");
			return (0);
		}
		if (parse = tokenize(command, DELIMITERS, &arguments) < 0) {
			fprintf(stderr, "Failed to parse command");
		}
		if (strcmp("cd",arguments[0])== 0){
			if(chdir(arguments[1]))
				if(chdir(home))fprintf(stdout,"Error\n");
		}
		else if(strcmp("getenv",arguments[0])==0){
			if(arguments[1] == NULL)showenv();
			else{
				temp = getenv(arguments[1]);
				if(temp)printf("%s\n",temp);		
				else printf("\n");
			}
		}
			
		else{
			pid_t child=fork();
			wait(0);
			if((long)child==0){
				execvp(arguments[0], arguments);
				perror("Failed to execute command");
				exit(0);
			}
		}
	}
	return (0);
}
