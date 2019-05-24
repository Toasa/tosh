#include "ls.h"

char input[256];

int cmd_is(char *cmd) {
	return !strcmp(input, cmd);
}

int main (void) {	
	while(1) {
		printf(">> ");
		scanf("%s", input);
		if (cmd_is("exit")) {
			break;			
		} else if (cmd_is("ls")) {
			ls(".");
		} else {
			printf("%s: command not found\n", input);
		}
	}
}
