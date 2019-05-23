#include <stdio.h>
#include <string.h>

int main (void) {
	char *input;
	while(1) {
		printf(">> ");
		scanf("%s", input);
		if (strcmp(input, "exit") == 0) {
			break;			
		} else {
			printf("%s\n", input);
		}
	}
}