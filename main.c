#include "ls.h"

int main (void) {
	char input[256];
	while(1) {
		printf(">> ");
		scanf("%s", input);
		if (strcmp(input, "exit") == 0) {
			break;			
		} else if (strcmp(input, "ls") == 0) {
			ls(".");
		} else {
			printf("%s: command not found\n", input);
		}
	}
}