#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

typedef struct Player
{
	char *name;
	int age;
	int number;

	int skill;
	int form;
	int fitness;

	char original_post;
	char post;
} Player;

typedef struct Team
{
	char *name;

	int defence;
	int mid;
	int attack;
	int form;

	Player players[35];
} Team;

Team Teams[16];

int main()
{
	return 0;
}


void Import_team(char* team_name)
{
	char path[100];
 	strcpy(path, "Teams/");
 	strcat(strcat(path, team_name), ".csv");
  	FILE* fh = fopen(path, "r");
	int j;
	if (strcmp(team_name, "Esteghlal") == 0)
	{
		j = 0;
	}
	else if (strcmp(team_name, "EsteghlalKhuzestan") == 0)
	{
		j = 1;
	}
	else if (strcmp(team_name, "FooladKhuzestan") == 0)
	{
		j = 2;
	}
	else if (strcmp(team_name, "GostareshFoolad") == 0)
	{
		j = 3;
	}
	else if (strcmp(team_name, "MachineSazi") == 0)
	{
		j = 4;
	}
	else if (strcmp(team_name, "NaftTehran") == 0)
	{
		j = 5;
	}
	else if (strcmp(team_name, "PadidehKhorasan") == 0)
	{
		j = 6;
	}
	else if (strcmp(team_name, "Paykan") == 0)
	{
		j = 7;
	}
	else if (strcmp(team_name, "Persepolis") == 0)
	{
		j = 8;
	}
	else if (strcmp(team_name, "SabaQom") == 0)
	{
		j = 9;
	}
	else if (strcmp(team_name, "Saipa") == 0)
	{
		j = 10;
	}
	else if (strcmp(team_name, "SanatNaft") == 0)
	{
		j = 11;
	}
	else if (strcmp(team_name, "Sepahan") == 0)
	{
		j = 12;
	}
	else if (strcmp(team_name, "SiahjameganMashhad") == 0)
	{
		j = 13;
	}
	else if (strcmp(team_name, "TractorSazi") == 0)
	{
		j = 14;
	}
	else if (strcmp(team_name, "ZobAhan") == 0)
	{
		j = 15;
	}
	else
	{
		printf("Invalid Name!");
		exit(-1);
	}
	if (!fh) {
		perror("Can't Open File: ");
		exit(-1);
	}
	char tmp[200];
	char * ptr;
	int k = 0;
	int i;
	while (fgets(tmp, 200, fh) != NULL)
	{
		ptr = tmp;
		sscanf(tmp, "%d,", &Teams[j].players[k].number);
		for (i = 0; tmp[i] != ','; i++);
		ptr += (i + 1);
		char fullname[100];
		for (i = 0; ptr[i] != ','; i++) {
			fullname[i] = ptr[i];
		}
		fullname[i] = '\0';
		strcpy(Teams[j].players[k].name, fullname);
		ptr += (i + 1);
		sscanf(ptr, "%d,%c,%d,%d,%d", &Teams[j].players[k].age, &Teams[j].players[k].original_post, &Teams[j].players[k].skill, &Teams[j].players[k].form, &Teams[j].players[k].fitness);
		k++;
	}
	fclose(fh);
}
