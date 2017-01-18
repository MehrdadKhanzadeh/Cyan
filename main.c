#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <limits.h>

int arrow_counter = 0;
int team_number = 0;

void init();
void start();
void teamLists();
void game();
void lineup();
void print(char *, int, int);
void printSpace(int, int, int);
int windowsWindowWidth();
void arrow(int);
void importTeam(char *);

typedef struct Player
{
    char name[100];
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
    char name[100];

    int defence;
    int mid;
    int attack;
    int formation;

    int player_count;
    Player players[40];
    Player fix_players[11];
} Team;

Team user;
Team Teams[16];

int main()
{
    init();
    start();
    teamLists();
    game();
    return 0;
}

void init()
{
    system("color 30");
    system("mode 650");
    print("", 0, 1);
    print("                                ", 0, 1);
    print("      In The Name Of God        ", 0, 1);
    print("   Ultimate Football Manager    ", 0, 1);
    print("                                ", 0, 1);
    print("      \"Cyan\" Team Project       ", 0, 1);
    print("              By:               ", 0, 1);
    print("         Arian Tashakor         ", 0, 1);
    print("        Mehrdad Khanzadeh       ", 0, 1);
    print("       Hessam Hashemizadeh      ", 0, 1);
    print("                                ", 0, 1);
    print(" Press Any Key To Start Game... ", 0, 1);
    //Watch Out!
    getch();
    system("cls");
    return;
}

void start()
{
	int counter_temp = 1;
    while (TRUE)
    {
        arrow(2);
        if(counter_temp != arrow_counter)
        {
			system("cls");
			puts("");
            print("                           ", 2, 1);
            print(" Ultimate Football Manager ", 2, 1);
            print("                           ", 2, 1);
            puts("");
        	switch (arrow_counter)
        	{
            	case 0 :
            	    print("                           ", 1, 1);
                	print("         New Game          ", 1, 1);
            	    print("                           ", 1, 1);
            	    print("                           ", 0, 1);
                	print("  Continue Previous Save   ", 0, 1);
            	    print("                           ", 0, 1);
                	break;
            	case 1 :
            	    print("                           ", 0, 1);
                	print("         New Game          ", 0, 1);
            	    print("                           ", 0, 1);
            	    print("                           ", 1, 1);
                	print("  Continue Previous Save   ", 1, 1);
            	    print("                           ", 1, 1);
                	break;
        	}
		}
		counter_temp = arrow_counter;
		int isReturnPressed = GetAsyncKeyState(VK_RETURN) & 0x8000;
        if (isReturnPressed)
            break;
    }
    importTeam("Esteghlal");
    importTeam("EsteghlalKhuzestan");
    importTeam("FooladKhuzestan");
    importTeam("GostareshFoolad");
    importTeam("MachineSazi");
    importTeam("NaftTehran");
    importTeam("PadidehKhorasan");
    importTeam("Paykan");
    importTeam("Persepolis");
    importTeam("SabaQom");
    importTeam("Saipa");
    importTeam("SanatNaft");
    importTeam("Sepahan");
    importTeam("SiahjameganMashhad");
    importTeam("TractorSazi");
    importTeam("ZobAhan");
}

void game()
{
    //printf("%s", team_name);
    arrow_counter = 0;
    int counter_temp = 1;
    while (TRUE)
    {
        arrow(5);
        if(counter_temp != arrow_counter){
        system("cls");
        puts("");
        print("                           ", 2, 1);
        print(" Ultimate Football Manager ", 2, 1);
        print("                           ", 2, 1);
        puts("");
        switch (arrow_counter)
        {
            case 0 :
                print("                           ", 1, 1);
                print("          Lineup           ", 1, 1);
                print("                           ", 1, 1);
                print("                           ", 0, 1);
                print("          Proceed          ", 0, 1);
                print("                           ", 0, 1);
                print("                           ", 0, 1);
                print("           Table           ", 0, 1);
                print("                           ", 0, 1);
                print("                           ", 0, 1);
                print("           Save            ", 0, 1);
                print("                           ", 0, 1);
                print("                           ", 0, 1);
                print("           Exit            ", 0, 1);
                print("                           ", 0, 1);
                break;
            case 1 :
                print("                           ", 0, 1);
                print("          Lineup           ", 0, 1);
                print("                           ", 0, 1);
                print("                           ", 1, 1);
                print("          Proceed          ", 1, 1);
                print("                           ", 1, 1);
                print("                           ", 0, 1);
                print("           Table           ", 0, 1);
                print("                           ", 0, 1);
                print("                           ", 0, 1);
                print("           Save            ", 0, 1);
                print("                           ", 0, 1);
                print("                           ", 0, 1);
                print("           Exit            ", 0, 1);
                print("                           ", 0, 1);
                break;
            case 2 :
                print("                           ", 0, 1);
                print("          Lineup           ", 0, 1);
                print("                           ", 0, 1);
                print("                           ", 0, 1);
                print("          Proceed          ", 0, 1);
                print("                           ", 0, 1);
                print("                           ", 1, 1);
                print("           Table           ", 1, 1);
                print("                           ", 1, 1);
                print("                           ", 0, 1);
                print("           Save            ", 0, 1);
                print("                           ", 0, 1);
                print("                           ", 0, 1);
                print("           Exit            ", 0, 1);
                print("                           ", 0, 1);
                break;
            case 3 :
                print("                           ", 0, 1);
                print("          Lineup           ", 0, 1);
                print("                           ", 0, 1);
                print("                           ", 0, 1);
                print("          Proceed          ", 0, 1);
                print("                           ", 0, 1);
                print("                           ", 0, 1);
                print("           Table           ", 0, 1);
                print("                           ", 0, 1);
                print("                           ", 1, 1);
                print("           Save            ", 1, 1);
                print("                           ", 1, 1);
                print("                           ", 0, 1);
                print("           Exit            ", 0, 1);
                print("                           ", 0, 1);
                break;
            case 4 :
                print("                           ", 0, 1);
                print("          Lineup           ", 0, 1);
                print("                           ", 0, 1);
                print("                           ", 0, 1);
                print("          Proceed          ", 0, 1);
                print("                           ", 0, 1);
                print("                           ", 0, 1);
                print("           Table           ", 0, 1);
                print("                           ", 0, 1);
                print("                           ", 0, 1);
                print("           Save            ", 0, 1);
                print("                           ", 0, 1);
                print("                           ", 1, 1);
                print("           Exit            ", 1, 1);
                print("                           ", 1, 1);
                break;
            }
        }
        counter_temp = arrow_counter;
        int isReturnPressed = GetAsyncKeyState(VK_RETURN) & 0x8000;
        if (isReturnPressed)
            break;
    }
    switch (arrow_counter)
    {
        case 0 :
            lineup();
            break;
    }
}

void teamLists()
{
    FILE *f = fopen("Teams/teams.csv", "r");
    char team[16][30];
    int i, j;
    for (i = 0; i < 16; i++)
    {
        fgets(team[i], 100, f);
        team[i][strlen(team[i]) - 1] = '\0';
    }
    if (arrow_counter == 0)
    {
        int counter_temp = 1;
        while (TRUE)
        {
            arrow(16);
            if(counter_temp != arrow_counter)
            {
                system("cls");
                puts("");
                print("                           ", 2, 1);
                print(" Ultimate Football Manager ", 2, 1);
                print("                           ", 2, 1);
                puts("");
                print("                           ", 2, 1);
                print("      Select Your Team     ", 2, 1);
                print("                           ", 2, 1);
                puts("");
                for (i = 0; i < 16; i++)
                {
                    /*int j, k;
                    for (j = 0; j < (27 - strlen(team[i])) / 2; j++)
                    {
                        print(" ", 1, 0);
                        for (k = 0; k < windowsWindowWidth(); k++)
                            printf("\b");
                    }*/
                    if (arrow_counter == i)
                    {
                        //printSpace((27 - strlen(team[i])) / 2, 1, 1);
                        print(team[i], 1, 0);
                        //printSpace(27 - (27 - strlen(team[i])) / 2, 1, 1);
                    }
                    else
                    {
                        //printSpace((27 - strlen(team[i])) / 2, 1, 0);
                        print(team[i], 0, 0);
                        //printSpace(27 - (27 - strlen(team[i])) / 2, 1, 0);
                    }
                }
            }
            strcpy(user.name, team[arrow_counter]);
            //printf("%s", user.name);
            counter_temp = arrow_counter;
            int j;
            for (j = 0; j < 16; j++)
            {
                if (strcmp(user.name, Teams[j].name) == 0)
                    team_number = j;
            }
            int isReturnPressed = GetAsyncKeyState(VK_RETURN) & 0x8000;
            if (isReturnPressed)
                break;
        }
    }
}

void lineup()
{
    arrow_counter = 0;
    int counter_temp = 1;
    while (TRUE)
    {
        arrow(3);
        if(counter_temp != arrow_counter){
        system("cls");
        puts("");
        print("                           ", 2, 1);
        print(" Ultimate Football Manager ", 2, 1);
        print("                           ", 2, 1);
        puts("");
        switch (arrow_counter)
        {
            case 0 :
                print("                           ", 1, 1);
                print("        4 - 4 - 2          ", 1, 1);
                print("                           ", 1, 1);
                print("                           ", 0, 1);
                print("        5 - 4 - 1          ", 0, 1);
                print("                           ", 0, 1);
                print("                           ", 0, 1);
                print("        4 - 3 - 3          ", 0, 1);
                print("                           ", 0, 1);
                break;
            case 1 :
                print("                           ", 0, 1);
                print("        4 - 4 - 2          ", 0, 1);
                print("                           ", 0, 1);
                print("                           ", 1, 1);
                print("        5 - 4 - 1          ", 1, 1);
                print("                           ", 1, 1);
                print("                           ", 0, 1);
                print("        4 - 3 - 3          ", 0, 1);
                print("                           ", 0, 1);
                break;
            case 2 :
                print("                           ", 0, 1);
                print("        4 - 4 - 2          ", 0, 1);
                print("                           ", 0, 1);
                print("                           ", 0, 1);
                print("        5 - 4 - 1          ", 0, 1);
                print("                           ", 0, 1);
                print("                           ", 1, 1);
                print("        4 - 3 - 3          ", 1, 1);
                print("                           ", 1, 1);
                break;
        }
        }
        counter_temp = arrow_counter;
        user.formation = arrow_counter;
        int isReturnPressed = GetAsyncKeyState(VK_RETURN) & 0x8000;
        if (isReturnPressed)
            break;
    }
    arrow_counter = 0;
    counter_temp = 1;
    int i;
    while (TRUE)
    {
        arrow(Teams[team_number].player_count);
        if(counter_temp != arrow_counter){
        system("cls");
        puts("");
        print("                           ", 2, 1);
        print(" Ultimate Football Manager ", 2, 1);
        print("                           ", 2, 1);
        puts("");
        for (i = 0; i < Teams[team_number].player_count; i++)
        {
            /*int j, k;
            for (j = 0; j < (27 - strlen(team[i])) / 2; j++)
            {
                print(" ", 1, 0);
                for (k = 0; k < windowsWindowWidth(); k++)
                    printf("\b");
            }*/
            if (arrow_counter == i)
            {
                char str[100];
                //printSpace((27 - strlen(team[i])) / 2, 1, 1);
                print("Name:", 1, 0);
                sprintf(str, "%s", Teams[team_number].players[i].name);
                print(str, 1, 0);
                print("Number:", 1, 0);
                sprintf(str, "%d", Teams[team_number].players[i].number);
                print(str, 1, 0);
                print("Age:", 1, 0);
                sprintf(str, "%d", Teams[team_number].players[i].age);
                print(str, 1, 0);
                print("Skill:", 1, 0);
                sprintf(str, "%d", Teams[team_number].players[i].skill);
                print(str, 1, 0);
                print("Fitness:", 1, 0);
                sprintf(str, "%d", Teams[team_number].players[i].fitness);
                print(str, 1, 0);
                print("Form:", 1, 0);
                sprintf(str, "%d", Teams[team_number].players[i].form);
                print(str, 1, 0);
                //printSpace(27 - (27 - strlen(team[i])) / 2, 1, 1);
            }
            else
            {
                //printSpace((27 - strlen(team[i])) / 2, 1, 0);
                print(Teams[team_number].players[i].name, 0, 0);
                //printSpace(27 - (27 - strlen(team[i])) / 2, 1, 0);
            }
        }
        }
        counter_temp = arrow_counter;
        int isReturnPressed = GetAsyncKeyState(VK_RETURN) & 0x8000;
        if (isReturnPressed)
            break;
    }

}

int windowsWindowWidth(int type)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns, rows;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    if (type)
        return columns;
    return rows;
}

void print(char *s, int clr, int align)
{
    const int total_width = windowsWindowWidth(1);
    const int s_width = strlen(s);
    const int field_width = (total_width - s_width) / 2;

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    if (align)
    {
        int i;
        for (i = 0; i < field_width; i++)
            printf(" ");
    }
    switch (clr)
    {
        case 0 :
            SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY | FOREGROUND_GREEN);
            break;
        case 1 :
            SetConsoleTextAttribute(hConsole, BACKGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
            break;
        case 2 :
            SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY / 3| FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
            break;
    }

    printf("%s", s);
    int i;
    if (!align)
        for (i = 0; i < 27 - strlen(s); i++)
            printf(" ");
    puts("");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    return;
}

void printSpace(int n, int clr, int align)
{
    const int total_width = windowsWindowWidth(1);
    const int field_width = (total_width - 27) / 2;

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    int i;
    if (align)
    {
        for (i = 0; i < field_width; i++)
            printf(" ");
    }
    switch (clr)
    {
        case 0 :
            SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY | FOREGROUND_GREEN);
            break;
        case 1 :
            SetConsoleTextAttribute(hConsole, BACKGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
            break;
        case 2 :
            SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY / 3| FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
            break;
    }

    for (i = 0; i < n; i++)
        printf(" ");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    return;
}

void arrow(int page_items)
{
	if (GetAsyncKeyState(VK_UP) & SHRT_MAX)
    	arrow_counter = (arrow_counter + page_items - 1) % page_items;
	else if (GetAsyncKeyState(VK_DOWN) & SHRT_MAX)
    	arrow_counter = (arrow_counter + page_items + 1) % page_items;
    return;
	/*else if ( GetAsyncKeyState ( VK_LEFT ) & SHRT_MAX )
      puts ( "Left arrow is pressed" );
    else if ( GetAsyncKeyState ( VK_RIGHT ) & SHRT_MAX )
      puts ( "Right arrow is pressed" );
	*/
}

void importTeam(char* team_name)
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
	//added this line
	strcpy(Teams[j].name , team_name);
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
	//sets the player_count field of teams[j] equal to k , which shows the "exact" number of players on each team
	Teams[j].player_count = k;
	fclose(fh);
}
