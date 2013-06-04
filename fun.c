#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

#define MAX 10

int main()
{
	int i, j, count = 0;
	unsigned char string[MAX+1], str[16][MAX * 8];
	unsigned long offset;
	
	printf("Enter the word (Less than %02d):\n", MAX);
	scanf(" %s", string);

	FILE *HZK;
	char *mat = (char *)malloc(16);
	memset(mat,0,16);
	if((HZK = fopen("english.fnt","rb"))==NULL) {
		printf("Can't    Open    english.fnt\n");
		exit(0);
	}

	for (i = 0; string[i] != 0 && i < MAX; i++) {
		offset = toupper(string[i]) * 16;
		fseek(HZK,offset,SEEK_SET);
		fread(mat,16,1,HZK);
		for(j = 0; j < 16; j++) {
			if((mat[j] & 0x80) != 0) { str[j][i * 8 + 0] = string[i]; } else { str[j][i * 8 + 0] = ' '; }
			if((mat[j] & 0x40) != 0) { str[j][i * 8 + 1] = string[i]; } else { str[j][i * 8 + 1] = ' '; }
			if((mat[j] & 0x20) != 0) { str[j][i * 8 + 2] = string[i]; } else { str[j][i * 8 + 2] = ' '; }
			if((mat[j] & 0x10) != 0) { str[j][i * 8 + 3] = string[i]; } else { str[j][i * 8 + 3] = ' '; }
			if((mat[j] & 0x08) != 0) { str[j][i * 8 + 4] = string[i]; } else { str[j][i * 8 + 4] = ' '; }
			if((mat[j] & 0x04) != 0) { str[j][i * 8 + 5] = string[i]; } else { str[j][i * 8 + 5] = ' '; }
			if((mat[j] & 0x02) != 0) { str[j][i * 8 + 6] = string[i]; } else { str[j][i * 8 + 6] = ' '; }
			if((mat[j] & 0x01) != 0) { str[j][i * 8 + 7] = string[i]; } else { str[j][i * 8 + 7] = ' '; }
		}
	}
	fclose(HZK);
	count = i;
	for (j = 0; j < 16; j++) {
		for (i = 0; i < count * 8; i++) {
			putchar(str[j][i]);
		}
		putchar('\n');
	}
	return 0;
}
