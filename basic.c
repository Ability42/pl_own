# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>


typedef enum { false = 0, true = 1} boolean;

#define NOV_func 2
#define VOVV_func 5
#define VOV_func 1

// void func value
char * sbasic_n_o_v_tokens[NOV_func] = {"PRINTN", "PRINTS"};
// value func value value
char * sbasic_v_o_vv_tokens[VOVV_func] = {"+", "-", "*", "/", "%"};
// value func value
char * sbasic_v_o_v_tokens[VOV_func] = {"SQUARE"};


/*----------------------------------------------------------*/

FILE *openFile(const char * name);
void throwError(char * msg, int code);
//boolean isEmpty(FILE * fp);
void nextToken(FILE * fp,char * token, boolean * isEOF);
boolean isOperation(char * token);
void tokenToString(char * token, char * word);


/*----------------------------------------------------------*/
/*----------------------------------------------------------*/
int main(int argc, char const * argv[]) {

	FILE * fp = openFile(argv[1]);
	boolean isEOF = false;
	char token[100];

	while(!isEOF) {
		nextToken(fp, token, &isEOF);
		if(!isEOF) {
			if (isOperation(token)) {
				if (strcmp(token, "PRINTS") == 0) {
					nextToken(fp, token, &isEOF);
					char str[100];
					tokenToString(token, str);
					puts(str);
				} else if (strcmp(token, "PRINTN") == 0) {
					printf("%lf\n", parse_arithmetic(fp));
				}
			}
		}
	}

	return 0;
}
/*----------------------------------------------------------*/
/*----------------------------------------------------------*/

FILE * openFile(const char * name) {

	FILE * fp = fopen(name, "r");
	if (!fp) {
		throwError("Cannot open file\n", 101);
	} else {
		printf("Open Success\n");
	}
	return fp;
}

void throwError(char * msg, int code) {
	printf("ERROR %d : %s", code, msg);
	exit(code);
}

void nextToken(FILE * fp, char * token, boolean * isEOF) {
	int xs = fscanf(fp, "%s", token);
	if (xs == EOF) {
		*isEOF = true;
	} else {
		*isEOF = false;
	}
}

boolean isOperation(char * token) {
	for (int i = 0; i < NOV_func; ++i) {
		if (strcmp(token, sbasic_n_o_v_tokens[i]) == 0) {
			return true;
		}
	}
	
	for (int i = 0; i < VOV_func; ++i) {
		if (strcmp(token, sbasic_v_o_v_tokens[i]) == 0) {
			return true;
		}
	}
	
	for (int i = 0; i < VOVV_func; ++i) {
		if (strcmp(token, sbasic_v_o_vv_tokens[i]) == 0) {
			return true;
		}
	}
	
	return false;
}

void tokenToString(char * token, char * word) {
	substring(token, word, 2, (int)strlen(token) - 2)
}

void substring(char s[], char sub[], int p, int l) {
	int c = 0;

	while (c < l) {
		sub[c] = s[p+c-1];
		c++;
	}
	sub[c] = '\0'
}

double parse_arithmetic(FILE *fp) {
	boolean isEOF;
	char token[100];

	nextToken(fp,token,&isEOF);
}
/*boolean isEmpty(FILE * fp) {
	if (((int)strlen(fp)) == NULL) {
		return true;
	}
	else {
		return false;
	}
}*/