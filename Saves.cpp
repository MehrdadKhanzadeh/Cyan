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
		char path[100];
		strcpy(path, "Saves/Save");
		strcat(strcat(path, i), ".dat");
		save = fopen(path , "w");
		//fprintf : buncha stuff in some lines
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
	char path[100];
	strcpy(path, "Saves/");
	strcat(path, file_name);
	FILE* fh = fopen(path, "r+");
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
	char path[100];
	strcpy(path, "Saves/");
	strcat(path, file_name);
	FILE* fh = fopen(path , "r+");
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
