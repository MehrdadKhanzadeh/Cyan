#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>

int team_number = 0;
int random = 0;
int week = 0;

typedef struct Player
{
	char name[100];
	int age;
	int number;

	int base_skill;
	int form;
	int fitness;

	char original_post;
	char post;
} Player;

typedef struct Team
{
	char name[100];

	int formation;

	int goals_for;
	int goals_against;

	int win;
	int lose;
	int draw;

	int point;

	int player_count;
	Player players[40];
	int is_player_selected[40];
	Player fix_players[11];
} Team;

Team teams[16];

int main()
{
	return 0;
}

void save(char* i)
{
	void encode(char*);
	FILE* save;
	if (strcmp(i, "auto") == 0)
	{
		save = fopen("Saves/Autosave.dat", "w+");
		//fprintf : buncha stuff in some lines
		fprintf(save, "%d,%d,%d\n", team_number, random, week);
		for (int i = 0; i < 16; i++)
		{
			fprintf(save, "%s\n", teams[i].name);
			fprintf(save, "%d,%d,%d,%d,%d,%d,%d,%d\n", teams[i].formation, teams[i].goals_for, teams[i].goals_against, teams[i].win, teams[i].lose, teams[i].draw, teams[i].point, teams[i].player_count);
			for (int j = 0; j < teams[i].player_count; j++)
			{
				fprintf(save, "%s\n", teams[i].players[j].name);
				fprintf(save, "%d,%d,%d,%d,%d,%c,%c\n", teams[i].players[j].age, teams[i].players[j].number, teams[i].players[j].base_skill, teams[i].players[j].form, teams[i].players[j].fitness, teams[i].players[j].original_post, teams[i].players[j].post);
				fprintf(save, "%d\n", teams[i].is_player_selected[j]);
			}
			for (int j = 0; j < 11; j++)
			{
				fprintf(save, "%s\n", teams[i].fix_players[j].name);
				fprintf(save, "%d,%d,%d,%d,%d,%c,%c", teams[i].fix_players[j].age, teams[i].fix_players[j].number, teams[i].fix_players[j].base_skill, teams[i].fix_players[j].form, teams[i].fix_players[j].fitness, teams[i].fix_players[j].original_post, teams[i].fix_players[j].post);
			}
		}
		encode("Autosave.dat");
	}
	else
	{
		char path[100];
		strcpy(path, "Saves/Save");
		strcat(strcat(path, i), ".dat");
		save = fopen(path, "w+");
		//fprintf : buncha stuff in some lines
		fprintf(save, "%d,%d,%d\n", team_number, random, week);
		for (int i = 0; i < 16; i++)
		{
			fprintf(save, "%s\n", teams[i].name);
			fprintf(save, "%d,%d,%d,%d,%d,%d,%d,%d\n", teams[i].formation, teams[i].goals_for, teams[i].goals_against, teams[i].win, teams[i].lose, teams[i].draw, teams[i].point, teams[i].player_count);
			for (int j = 0; j < teams[i].player_count; j++)
			{
				fprintf(save, "%s\n", teams[i].players[j].name);
				fprintf(save, "%d,%d,%d,%d,%d,%c,%c\n", teams[i].players[j].age, teams[i].players[j].number, teams[i].players[j].base_skill, teams[i].players[j].form, teams[i].players[j].fitness, teams[i].players[j].original_post, teams[i].players[j].post);
				fprintf(save, "%d\n", teams[i].is_player_selected[j]);
			}
			for (int j = 0; j < 11; j++)
			{
				fprintf(save, "%s\n", teams[i].fix_players[j].name);
				fprintf(save, "%d,%d,%d,%d,%d,%c,%c", teams[i].fix_players[j].age, teams[i].fix_players[j].number, teams[i].fix_players[j].base_skill, teams[i].fix_players[j].form, teams[i].fix_players[j].fitness, teams[i].fix_players[j].original_post, teams[i].fix_players[j].post);
			}
		}
		char tmp_encode[100];
		strcpy(tmp_encode, "Save");
		strcat(strcat(tmp_encode, i), ".dat");
		encode(tmp_encode);
	}
	fclose(save);
}

void load(char* i)
{
	void decode(char*);
	FILE* load;
	//three save slots
	if (strcmp(i, "1") == 0)
	{
		//saveslot no. 1
		decode("Save1.dat");
		load = fopen("Saves/Save1.dat", "r+");
	}
	else if (strcmp(i, "2") == 0)
	{
		//saveslot no. 2
		decode("Save2.dat");
		load = fopen("Saves/Save2.dat", "r+");
	}
	else if (strcmp(i, "3") == 0)
	{
		//saveslot no. 3
		decode("Save3.dat");
		load = fopen("Saves/Save3.dat", "r+");
	}
	else
	{
		//autosave case
		decode("Autosave.dat");
		load = fopen("Saves/Autosave.dat", "r+");
	}
	//fopen a file
	//fgets the lines and store them into the current structs
	char buffer[100];
	fgets(buffer, 100, load);
	sscanf(buffer, "%d,%d,%d", &team_number, &random, &week);
	for (int i = 0; i < 16; i++)
	{
		fgets(buffer, 100, load);
		strcpy(teams[i].name, buffer);
		fgets(buffer, 100, load);
		sscanf(buffer, "%d,%d,%d,%d,%d,%d,%d,%d", &teams[i].formation, &teams[i].goals_for, &teams[i].goals_against, &teams[i].win, &teams[i].lose, &teams[i].draw, &teams[i].point, &teams[i].player_count);
		for (int j = 0; j < teams[i].player_count; j++)
		{
			fgets(buffer, 100, load);
			strcpy(teams[i].players[j].name , buffer);
			fgets(buffer, 100, load);
			sscanf(buffer, "%d,%d,%d,%d,%d,%c,%c", &teams[i].players[j].age, &teams[i].players[j].number, &teams[i].players[j].base_skill, &teams[i].players[j].form, &teams[i].players[j].fitness, &teams[i].players[j].original_post, &teams[i].players[j].post);
			fgets(buffer, 100, load);
			sscanf(buffer, "%d", &teams[i].is_player_selected[j]);
		}
		for (int j = 0; j < 11; j++)
		{
			fgets(buffer, 100, load);
			strcpy(teams[i].fix_players[j].name, buffer);
			fgets(buffer, 100, load);
			sscanf(buffer, "%d,%d,%d,%d,%d,%c,%c", &teams[i].fix_players[j].age, &teams[i].fix_players[j].number, &teams[i].fix_players[j].base_skill, &teams[i].fix_players[j].form, &teams[i].fix_players[j].fitness, &teams[i].fix_players[j].original_post, &teams[i].fix_players[j].post);
		}
	}
	fclose(load);
}

void autosave()
{
	//ATTENTION MEHRDAD!!! : after each proceed , the game automatically saves itself, cool?
	save("auto");
}

void encode(char* file_name)
{
	char path[100];
	strcpy(path, "Saves/");
	strcat(path, file_name);
	FILE* fh = fopen(path, "r+");
	char tmp[100];
	while (fgets(tmp, 100, fh) != NULL)
	{
		for (int i = 0; tmp[i] != '\0'; i++)
		{
			tmp[i] += 10;
		}
		fprintf(fh, "%s", tmp);
	}
	fclose(fh);
}

void decode(char* file_name)
{
	char path[100];
	strcpy(path, "Saves/");
	strcat(path, file_name);
	FILE* fh = fopen(path, "r+");
	char tmp[100];
	while (fgets(tmp, 100, fh) != NULL)
	{
		for (int i = 0; tmp[i] != '\0'; i++)
		{
			tmp[i] -= 10;
		}
		fprintf(fh, "%s", tmp);
	}
	fclose(fh);
}
