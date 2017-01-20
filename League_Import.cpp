#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>

int home[128];
int away[128];

int main()
{
	return 0;
}

void leagueImport()
{
	FILE* fh = fopen("Teams/League_Schedule.csv", "r");
	if (!fh)
	{
		perror("Can't Open File: ");
		exit(-1);
	}
	char buffer[10];
	int tmp, i = 0;
	while (fgets(buffer , 10 , fh) != NULL)
	{
		sscanf(buffer ,"%d,%d,%d", &tmp, &home[i], &away[i]);
		i++;
	}
	fclose(fh);
}