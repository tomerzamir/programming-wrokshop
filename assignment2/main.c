//Name: Tomer Zamir		id: 316123181
//
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<assert.h>
#include<ctype.h>
//
void Ex1();
void Ex2();
void Ex3();
//
char* hexadecimal_base(char*);
FILE* fileGen(char** mat, int n, char* fileName);
void fileRead(char* fileName);
void createFile(char* str);
char commonestLetter(char* filename);
//
int main()
{
	int select = 0, i, all_Ex_in_loop = 0;
	printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");
	if (scanf("%d", &all_Ex_in_loop) == 1)
		do
		{
			printf("Ex1--->1\n");
			printf("Ex2--->2\n");
			printf("Ex3--->3\n");
			printf("EXIT-->0\n");
			do {
				select = 0;
				printf("please select 0-3 : ");
				scanf("%d", &select);
				getchar();
			} while ((select < 0) || (select > 3));
			switch (select)
			{
			case 1: Ex1(); break;
			case 2: Ex2(); break;
			case 3: Ex3(); break;
			}
		} while (all_Ex_in_loop && select);
		return 0;
}
//
void Ex1()
{
	char string[200];
	char* newString;
	printf("enter a string:\n");
	fgets(string, 200, stdin);
	newString = hexadecimal_base(string);
	puts(newString);
	free(newString);
}

char* hexadecimal_base(char* str)
{
	int i, j;
	int size = 1;
	for (i = 0; str[i] != '\0'; i++)
	{
		if ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'f')
			|| (str[i] >= 'A' && str[i] <= 'F'))
			size++;
	}
	char* new_str = (char*)calloc(size, sizeof(char));
	assert(new_str);
	for (i = 0, j = 0; str[i] != '\0'; i++)
	{
		if ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'f')
			|| (str[i] >= 'A' && str[i] <= 'F'))
		{
			new_str[j] = str[i];
			j++;
		}
	}
	return new_str;
}
//
void Ex2()
{
	//char* fileName = ("input");
	printf("enter file name:\n");
	char fileName[200];
	gets(fileName);
	int r, i, j;
	printf("enter the number of strings:\n");
	scanf("%d", &r);
	getchar();
	char** mat = malloc(r * sizeof(char*));
	assert(mat);
	for (i = 0; i < r; i++)
	{
		mat[i] = (char*)malloc(200 * sizeof(char));
		assert(mat[i]);
		printf("enter string:\n");
		fgets(mat[i], 200, stdin);
	}
	FILE* a = fileGen(mat, r, fileName);
	for (i = 0; i < r; i++)
	{
		free(mat[i]);
	}
	free(mat);
}

FILE* fileGen(char** mat, int n, char* fileName)
{
	int i;
	FILE* x = fopen(fileName, "w");
	if (!x)
	{
		printf("File not found\n");
		return;
	}
	for (i = 0; i < n; i++)
	{
		fprintf(x, "%d. %s", i + 1,mat[i]);
	}
	fclose(x);
	return x;
}
//
void Ex3()
{
	char* str = ("input");
	createFile(str);

	char ch;
	ch = commonestLetter("input");
	if (ch)
		printf("The commonest letter is %c\n", ch);
	else
		printf("No letters in the file");
}
void createFile(char* str)
{
	FILE* x = fopen(str, "w");
	if (!x)
	{
		printf("File not found\n");
		return;
	}
	char c;
	printf("enter chars, press enter to stop:\n");
	while (1)
	{
		c = getchar();
		if (c == 10)
		{
			fclose(x);
			return;
		}
		fputc(c, x);
	}
}

char commonestLetter(char* filename)
{
	FILE* x = fopen(filename, "r");
	int i, max = 0;
	int count[26] = { 0 };
	char c = fgetc(x);
	while (!feof(x))
	{
		if (isupper(c))
			count[c - 'A']++;
		else count[c - 'a']++;
		c = fgetc(x);
	}
	fclose(x);
	for (i = 0; i < 26; i++)
	{
		if (count[i] >= count[max])
			max = i;
	}
	if (count[max] == 0)
		return '\0';
	else return ('A' + max);
}
