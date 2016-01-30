# include <stdio.h>
# include <stdlib.h>

char * open_file(); 
//void call(char * name); // makes a call to contact with `name`
int lex(char * file_contents);
/*-----------------------------------*/
int main() {

	char *p;
	p = open_file();
	lex(p);
	
	return 0;
}
/*-----------------------------------*/

// check syntax
int lex(char *file_contents) { 
	for (int i = 0; i < 32; i++) {
		printf("%c", file_contents[i]);
	}
	printf("\n");
	return 0;
} 

char * open_file(int argc, char *argv[1]) {
	FILE *fp = fopen(argv[1], "r");
	static char data[32];
	if (fp == 0) {
		printf("Can't open a file\n");
	} else {
		int x;
		int i = 0;
		while((x = fgetc(fp)) != EOF) {
			i++;
			data[i] = x;
		}
		fclose(fp);
	}
	printf("%s\n", argv[1]);
	
	return data;
		
}



