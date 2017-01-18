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
	void encode(char*);
	FILE* save;
	if (strcmp(i, "auto") == 0)
	{
		save = fopen("Saves/Autosave.dat", "w");
		//fprintf : buncha stuff in some lines
		encode("Autosave.dat");
	}
	else
	{
		save = fopen(strcat(strcat("Saves/Save", i), ".dat"), "w");
		//fprintf : buncha stuff in some lines
		encode(strcat(strcat("Save", i), ".dat"));
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
	}
	else if (strcmp(i, "2") == 0)
	{
		//saveslot no. 2
		decode("Save2.dat");
	}
	else if (strcmp(i, "3") == 0)
	{
		//saveslot no. 3
		decode("Save3.dat");
	}
	else
	{
		//autosave case
		decode("Autosave.dat");
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

void encode(char* file_name)
{
	FILE* fh = fopen(strcat("Saves/", file_name), "r+");
	char tmp[100];
	while (fgets(tmp, 100, fh) != NULL)
	{
		for (int i = 0; tmp[i]!='\0' ; i++)
		{
			tmp[i] += 3;
		}
		fprintf(fh, "%s", tmp);
	}
	fclose(fh);
}

void decode(char* file_name)
{
	FILE* fh = fopen(strcat("Saves/", file_name), "r+");
	char tmp[100];
	while (fgets(tmp , 100 , fh)!= NULL)
	{
		for (int i = 0; tmp[i]!='\0' ; i++)
		{
			tmp[i] -= 3;
		}
		fprintf(fh, "%s", tmp);
	}
	fclose(fh);
}
