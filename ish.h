#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define MAXLEN 256

#define DELIMITERS " \t\n"

#define EXIT "exit\n"

void showenv();
int tokenize(char *, char *, char ***);
