#include<stdio.h>
#include<string.h>

#define MAXLINE 1000

int getline(char *line, int max);

int main(int argc, char *argv[])
{
	char line[MAXLINE];
	long lineno = 0;
	int c, except = 0, number = 0, found = 0;

	while(--argc > 0 && (*++argv)[0] == '-')
		while(c = *++argv[0])
			switch(c)
			{
			case 'x':
				except = 1;
				break;
			case 'n':
				number = 1;
				break;
			default:
				printf("grep: illegal option %c\n", c);
				argc = 0;
				found = -1;
				break;
			}
	if(argc != 1)
		printf("Usage: grep -x -n pattern\n");
	else
		while(getline(line, MAXLINE) > 0)
		{
			lineno++;
			if((strstr(line, *argv) != NULL) != except)
			{
				if(number)
					printf("%ld:", lineno);
				printf("%s\n", line);
				found++;
			}
		}
	return found;

/*	if(argc != 2)
		printf("Usage: find pattren\n");
	else
		while(getline(line, MAXLINE) != 0)
			if(strstr(line, argv[1]) != NULL)
			{
				printf("%s\n", line);
				++found;
			}
	return found;	*/
}	

int getline(char line[], int n)
/* getline function: put the input to the line[], and return the long of line.*/
{
	int c;
	int i;

	for(i = 0; n > 1 && (c = getchar()) != EOF && c != '\n'; --n)
	{
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}
