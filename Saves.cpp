#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>

int main()
{
    return 0;
}

void save(char* i)
{
	FILE* save;
	if (strcmp(i, "auto") == 0)
	{
		save = fopen("Saves/Autosave.dat", "w");
	}
	else
	{
		save = fopen(strcat(strcat("Saves/Save", "i "), ".dat"), "w");
	}
	//fprintf : buncha stuff in some lines
	fclose(save);
}

void load(char* i)
{
	FILE* load;
	//three save slots
	if (strcmp(i, "1") == 0)
	{
		//saveslot no. 1
	}
	else if (strcmp(i, "2") == 0)
	{
		//saveslot no. 2
	}
	else if (strcmp(i, "3") == 0)
	{
		//saveslot no. 3
	}
	else
	{
		//autosave case
	}
	//fopen a file
	//fgets the lines and store them into the current structs
	fclose(load);
}

void autosave()
{
	//every 5 minutes , the game calls the save function:
	save("auto");
}