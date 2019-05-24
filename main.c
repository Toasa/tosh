#include "ls.h"
#define BUF_SIZE 256
// コマンドのオプション数の上限
#define OPT_SIZE 32

char cmd[OPT_SIZE][BUF_SIZE];

int cmd_is(char *s) {
	return !strcmp(cmd[0], s);
}

int str_eq(char *s1, char *s2) {
	return !strcmp(s1, s2);
}

void buf_clear(char *buf) {
	for (int i = 0; i < BUF_SIZE; i++) {
		buf[i] = '\0';
	}
}

void split(char *input) {
	// コマンドのオプション数
	int n = 0;
	int head = 0;
	char buf[BUF_SIZE];

	for (int i = 0; i <= strlen(input); i++) {
		if (input[i] == ' ' || input[i] == '\0') {
			strncpy(buf, input + head, i - head);
			strcpy(cmd[n], buf);

			buf_clear(buf);
			head = i + 1;			
			n++;
		}		
	}
	
	strcpy(cmd[n], "\0");
}

void disp() {
	for (int i = 0; !str_eq(cmd[i], "\0"); i++) {
		printf("%s\n", cmd[i]);
	}
}

int main (void) {
	char input[256];

	while(1) {
		printf(">> ");
		scanf("%[^\n]%*c", input);

		split(input);

		if (cmd_is("exit")) {
			break;			
		} else if (cmd_is("ls")) {			
			ls(cmd[1]);
		} else {
			printf("%s: command not found\n", input);
		}
	}
}
