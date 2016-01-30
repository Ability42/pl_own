# include <stdio.h>
# include <stdlib.h>
# include <string.h>

char * open_file(); 
//void call(char * name); // makes a call to contact with `name`
int lex(char *file_contents);
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
	char * tok;
	char to_srch[6] = "PRINT";

	int srch_pos = 0;
	int text_pos = 0;
	int len_srch = 5;
	int len_text = 32;
	for (int i = 0; i < 32; i++) 
		tok[i] = file_contents[i];

	for(text_pos = 0; text_pos < len_text - len_srch; ++text_pos) {
		if(tok[text_pos] == to_srch[srch_pos]){
			++srch_pos;
			if(srch_pos == len_srch) {
				//match
				printf("match from %d to %d\n", text_pos - len_srch, text_pos);
			}
		} else {
			text_pos -= srch_pos;
			srch_pos = 0;
		}
	}
	//no match
	printf("no match\n");
	/*if (strstr(tok, needle) != NULL)
		printf("Found a PRINT!\n");
	printf("lol\n");*/
	return 0;
} 

int search() {
	

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



