//ITNOG

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <limits.h>

int arrow_counter = 0;
int team_number = 0;
int random = 0;
int week = 0;

void init();
void start();
void teamLists();
void game();
void lineup();
void saveUI();
void loadUI();
void table();
void print(char *, int, int);
int windowsWindowWidth();
void arrow(int);
void importTeam(char *);
void teamSort(int);
void leagueImport();
void tableSort();

typedef struct Player
{
    char name[100];
    int age;
    int number;

    int base_skill;
    int skill;
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

    int points;

    int player_count;
    Player players[50];
    int is_player_selected[50];
    Player fix_players[11];
} Team;

Team user;
Team teams[16];
Team sorted_teams[16];
int home[128];
int away[128];

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
    if (arrow_counter == 0)
    {
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
        int j;
        for (j = 0; j < 16; j++)
        {
            teams[j].formation = 0;
            teamSort(j);
        }
    }
    else
        loadUI();
}

void game()
{
    autosave();
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
        case 2 :
            table();
            break;
        case 3 :
            saveUI();
            break;
    }
}

void teamLists()
{
    FILE *f = fopen("teams/teams.csv", "r");
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
                print("                           ", 2, 0);
                print("      Select Your Team     ", 2, 0);
                print("                           ", 2, 0);
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
            user.player_count = teams[team_number].player_count;
            //printf("%s", user.name);
            counter_temp = arrow_counter;
            int j;
            for (j = 0; j < 16; j++)
            {
                if (strcmp(user.name, teams[j].name) == 0)
                    team_number = j;
            }
            for (j = 0; j < 40; j++)
                teams[team_number].is_player_selected[j] = 0;
            int isReturnPressed = GetAsyncKeyState(VK_RETURN) & 0x8000;
            if (isReturnPressed)
                break;
        }
    }
}

void lineup()
{
    int j;
    arrow_counter = 0;
    int counter_temp = 1;
    while (TRUE)
    {
        arrow(4);
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
                print("        4 - 3 - 3          ", 0, 1);
                print("                           ", 0, 1);
                print("                           ", 0, 1);
                print("        5 - 4 - 1          ", 0, 1);
                print("                           ", 0, 1);
                print("                           ", 0, 1);
                print("        3 - 5 - 2          ", 0, 1);
                print("                           ", 0, 1);
                break;
            case 1 :
                print("                           ", 0, 1);
                print("        4 - 4 - 2          ", 0, 1);
                print("                           ", 0, 1);
                print("                           ", 1, 1);
                print("        4 - 3 - 3          ", 1, 1);
                print("                           ", 1, 1);
                print("                           ", 0, 1);
                print("        5 - 4 - 1          ", 0, 1);
                print("                           ", 0, 1);
                print("                           ", 0, 1);
                print("        3 - 5 - 2          ", 0, 1);
                print("                           ", 0, 1);
                break;
            case 2 :
                print("                           ", 0, 1);
                print("        4 - 4 - 2          ", 0, 1);
                print("                           ", 0, 1);
                print("                           ", 0, 1);
                print("        4 - 3 - 3          ", 0, 1);
                print("                           ", 0, 1);
                print("                           ", 1, 1);
                print("        5 - 4 - 1          ", 1, 1);
                print("                           ", 1, 1);
                print("                           ", 0, 1);
                print("        3 - 5 - 2          ", 0, 1);
                print("                           ", 0, 1);
                break;
            case 3 :
                print("                           ", 0, 1);
                print("        4 - 4 - 2          ", 0, 1);
                print("                           ", 0, 1);
                print("                           ", 0, 1);
                print("        4 - 3 - 3          ", 0, 1);
                print("                           ", 0, 1);
                print("                           ", 0, 1);
                print("        5 - 4 - 1          ", 0, 1);
                print("                           ", 0, 1);
                print("                           ", 1, 1);
                print("        3 - 5 - 2          ", 1, 1);
                print("                           ", 1, 1);
                break;
        }
        }
        counter_temp = arrow_counter;
        user.formation = arrow_counter;
        teams[team_number].formation = arrow_counter;
        int isReturnPressed = GetAsyncKeyState(VK_RETURN) & 0x8000;
        if (isReturnPressed)
            break;
    }
    int k;
    for (k = 0; k < teams[team_number].player_count; k++)
            teams[team_number].is_player_selected[k] = 0;
    arrow_counter = 0;
    for (j = 0; j < 11; j++){
    counter_temp = 1;
    int i, counter = 0;
    while (TRUE)
    {
        int k;
        arrow(teams[team_number].player_count);
        if(counter_temp != arrow_counter){
        system("cls");
        puts("");
        print("                           ", 2, 1);
        print(" Ultimate Football Manager ", 2, 1);
        print("                           ", 2, 1);
        puts("");
        print("                           ", 2, 0);
        print("    Select Your Players    ", 2, 0);
        print("                           ", 2, 0);
        puts("");
        for (i = 0; i < teams[team_number].player_count; i++)
        {
            /*int j, k;
            for (j = 0; j < (27 - strlen(team[i])) / 2; j++)
            {
                print(" ", 1, 0);
                for (k = 0; k < windowsWindowWidth(); k++)
                    printf("\b");
            }*/
            if (teams[team_number].is_player_selected[i] == 0){
            if (arrow_counter == i)
            {
                char str[100];
                print("Name:", 1, 0);
                sprintf(str, "%s", teams[team_number].players[i].name);
                print(str, 1, 0);
                print("Number:", 1, 0);
                sprintf(str, "%d", teams[team_number].players[i].number);
                print(str, 1, 0);
                print("Age:", 1, 0);
                sprintf(str, "%d", teams[team_number].players[i].age);
                print(str, 1, 0);
                print("Skill:", 1, 0);
                sprintf(str, "%d", teams[team_number].players[i].base_skill);
                print(str, 1, 0);
                print("Fitness:", 1, 0);
                sprintf(str, "%d", teams[team_number].players[i].fitness);
                print(str, 1, 0);
                print("Form:", 1, 0);
                sprintf(str, "%d", teams[team_number].players[i].form);
                print(str, 1, 0);
                print("Post:", 1, 0);
                sprintf(str, "%c", teams[team_number].players[i].original_post);
                print(str, 1, 0);
            }
            else
            {
                print(teams[team_number].players[i].name, 0, 0);
            }}
            else
            if (arrow_counter == i)
            {
                //char str[100];
                print(teams[team_number].players[i].name, 1, 0);
                //print("Post:", 1, 0);
                //sprintf(str, "%c", teams[team_number].players[i].post);
                //print(str, 1, 0);
            }
            else
            {
                //char str[100];
                print(teams[team_number].players[i].name, 2, 0);
                //print("Post That You Selected For This Player:", 2, 0);
                //sprintf(str, "%c", teams[team_number].players[i].post);
                //print(str, 1, 0);
            }
        }
        }
        counter_temp = arrow_counter;
        //int isSpacePressed = GetAsyncKeyState(VK_SPACE) & 0x8000;
        int isReturnPressed = GetAsyncKeyState(VK_RETURN) & 0x8000;
        if (isReturnPressed && teams[team_number].is_player_selected[arrow_counter] == 0)
        {
            teams[team_number].fix_players[j].age = teams[team_number].players[arrow_counter].age;
            teams[team_number].fix_players[j].fitness = teams[team_number].players[arrow_counter].fitness;
            teams[team_number].fix_players[j].form = teams[team_number].players[arrow_counter].form;
            strcpy(teams[team_number].fix_players[j].name, teams[team_number].players[arrow_counter].name);
            teams[team_number].fix_players[j].number = teams[team_number].players[arrow_counter].number;
            teams[team_number].fix_players[j].original_post = teams[team_number].players[arrow_counter].original_post;
            teams[team_number].fix_players[j].post = teams[team_number].players[arrow_counter].post;
            teams[team_number].fix_players[j].base_skill = teams[team_number].players[arrow_counter].base_skill;
            teams[team_number].is_player_selected[arrow_counter] = 1;
            break;
        }
    }
    }
    game();
}

void saveUI()
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
        print("   Ultimate Team Manager   ", 2, 1);
        print("                           ", 2, 1);
        puts("");
        switch (arrow_counter)
        {
            case 0 :
                print("                           ", 1, 1);
                print("        Save Slot 1        ", 1, 1);
                print("                           ", 1, 1);
                print("                           ", 0, 1);
                print("        Save Slot 2        ", 0, 1);
                print("                           ", 0, 1);
                print("                           ", 0, 1);
                print("        Save Slot 3        ", 0, 1);
                print("                           ", 0, 1);
                break;
            case 1 :
                print("                           ", 0, 1);
                print("        Save Slot 1        ", 0, 1);
                print("                           ", 0, 1);
                print("                           ", 1, 1);
                print("        Save Slot 2        ", 1, 1);
                print("                           ", 1, 1);
                print("                           ", 0, 1);
                print("        Save Slot 3        ", 0, 1);
                print("                           ", 0, 1);
                break;
            case 2 :
                print("                           ", 0, 1);
                print("        Save Slot 1        ", 0, 1);
                print("                           ", 0, 1);
                print("                           ", 0, 1);
                print("        Save Slot 2        ", 0, 1);
                print("                           ", 0, 1);
                print("                           ", 1, 1);
                print("        Save Slot 3        ", 1, 1);
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
            save("1");
            break;
        case 1 :
            save("2");
            break;
        case 2 :
            save("3");
            break;
    }
    game();
}

void loadUI()
{
    arrow_counter = 0;
    int counter_temp = 1;
    while (TRUE)
    {
        arrow(4);
        if(counter_temp != arrow_counter){
        system("cls");
        puts("");
        print("                           ", 2, 1);
        print("   Ultimate Team Manager   ", 2, 1);
        print("                           ", 2, 1);
        puts("");
        switch (arrow_counter)
        {
            case 0 :
                print("                           ", 1, 1);
                print("       Load Autosave       ", 1, 1);
                print("                           ", 1, 1);
                print("                           ", 0, 1);
                print("        Load Slot 1        ", 0, 1);
                print("                           ", 0, 1);
                print("                           ", 0, 1);
                print("        Load Slot 2        ", 0, 1);
                print("                           ", 0, 1);
                print("                           ", 0, 1);
                print("        Load Slot 3        ", 0, 1);
                print("                           ", 0, 1);
                break;
            case 1 :
                print("                           ", 0, 1);
                print("       Load Autosave       ", 0, 1);
                print("                           ", 0, 1);
                print("                           ", 1, 1);
                print("        Load Slot 1        ", 1, 1);
                print("                           ", 1, 1);
                print("                           ", 0, 1);
                print("        Load Slot 2        ", 0, 1);
                print("                           ", 0, 1);
                print("                           ", 0, 1);
                print("        Load Slot 3        ", 0, 1);
                print("                           ", 0, 1);
                break;
            case 2 :
                print("                           ", 0, 1);
                print("       Load Autosave       ", 0, 1);
                print("                           ", 0, 1);
                print("                           ", 0, 1);
                print("        Load Slot 1        ", 0, 1);
                print("                           ", 0, 1);
                print("                           ", 1, 1);
                print("        Load Slot 2        ", 1, 1);
                print("                           ", 1, 1);
                print("                           ", 0, 1);
                print("        Load Slot 3        ", 0, 1);
                print("                           ", 0, 1);
                break;
            case 3:
                print("                           ", 0, 1);
                print("       Load Autosave       ", 0, 1);
                print("                           ", 0, 1);
                print("                           ", 0, 1);
                print("        Load Slot 1        ", 0, 1);
                print("                           ", 0, 1);
                print("                           ", 0, 1);
                print("        Load Slot 2        ", 0, 1);
                print("                           ", 0, 1);
                print("                           ", 1, 1);
                print("        Load Slot 3        ", 1, 1);
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
            load("Autosave");
            break;
        case 1 :
            load("1");
            break;
        case 2 :
            load("2");
            break;
        case 3 :
            load("3");
            break;
    }
}

void table()
{
    tableSort();
    arrow_counter = 0;
    int counter_temp = 1;
    while (TRUE)
    {
        arrow(16);
        if(counter_temp != arrow_counter){
        system("cls");
        puts("");
        print("                           ", 2, 1);
        print("   Ultimate Team Manager   ", 2, 1);
        print("                           ", 2, 1);
        puts("");
        int i;
        for (i = 0; i < 16; i++)
        {
            if (arrow_counter == i){
            char str[100];
            print("Name:", 1, 0);
            sprintf(str, "%s", teams[i].name);
            print(str, 1, 0);
            print("Points:", 1, 0);
            sprintf(str, "%d", teams[i].points);
            print(str, 1, 0);
            print("Wins:", 1, 0);
            sprintf(str, "%d", teams[i].win);
            print(str, 1, 0);
            print("Draw:", 1, 0);
            sprintf(str, "%d", teams[i].draw);
            print(str, 1, 0);
            print("Lose:", 1, 0);
            sprintf(str, "%d", teams[i].lose);
            print(str, 1, 0);
            print("Goals For:", 1, 0);
            sprintf(str, "%d", teams[i].goals_for);
            print(str, 1, 0);
            print("Goals Against:", 1, 0);
            sprintf(str, "%d", teams[i].goals_against);
            print(str, 1, 0);
            print("Goal Difference:", 1, 0);
            sprintf(str, "%d", teams[i].goals_for - teams[i].goals_against);
            print(str, 1, 0);}
            else
                print(teams[i].name, 0, 0);
        }
        }
        counter_temp = arrow_counter;
        int isReturnPressed = GetAsyncKeyState(VK_RETURN) & 0x8000;
        if (isReturnPressed)
            break;
    }
    game();
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
	strcpy(teams[j].name , team_name);
	char tmp[200];
	char * ptr;
	int k = 0;
	int i;
	while (fgets(tmp, 200, fh) != NULL)
	{
		ptr = tmp;
		sscanf(tmp, "%d,", &teams[j].players[k].number);
		for (i = 0; tmp[i] != ','; i++);
		ptr += (i + 1);
		char fullname[100];
		for (i = 0; ptr[i] != ','; i++) {
			fullname[i] = ptr[i];
		}
		fullname[i] = '\0';
		strcpy(teams[j].players[k].name, fullname);
		ptr += (i + 1);
		sscanf(ptr, "%d,%c,%d,%d,%d", &teams[j].players[k].age, &teams[j].players[k].original_post, &teams[j].players[k].base_skill, &teams[j].players[k].form, &teams[j].players[k].fitness);
		teams[j].players[k].post = teams[j].players[k].original_post;
		k++;
	}
	//sets the player_count field of teams[j] equal to k , which shows the "exact" number of players on each team
	teams[j].player_count = k;
	fclose(fh);
}

void save(char* n)
{
	void encode(char*);
	FILE* save;
	if (strcmp(n, "auto") == 0)
	{
		save = fopen("Saves/Autosave.dat", "w+");
		//fprintf : buncha stuff in some lines
		fprintf(save, "%d,%d,%d\n", team_number, random, week);
		int i, j;
		for (i = 0; i < 16; i++)
		{
			fprintf(save, "%s\n", teams[i].name);
			fprintf(save, "%d,%d,%d,%d,%d,%d,%d,%d\n", teams[i].formation, teams[i].goals_for, teams[i].goals_against, teams[i].win, teams[i].lose, teams[i].draw, teams[i].points, teams[i].player_count);
			for (j = 0; j < teams[i].player_count; j++)
			{
				fprintf(save, "%s\n", teams[i].players[j].name);
				fprintf(save, "%d,%d,%d,%d,%d,%c,%c\n", teams[i].players[j].age, teams[i].players[j].number, teams[i].players[j].base_skill, teams[i].players[j].form, teams[i].players[j].fitness, teams[i].players[j].original_post, teams[i].players[j].post);
				fprintf(save, "%d\n", teams[i].is_player_selected[j]);
			}
            int k;
			for (k = 0; k < 11; k++)
			{
				fprintf(save, "%s\n", teams[i].fix_players[k].name);
				fprintf(save, "%d,%d,%d,%d,%d,%c,%c\n", teams[i].fix_players[k].age, teams[i].fix_players[k].number, teams[i].fix_players[k].base_skill, teams[i].fix_players[k].form, teams[i].fix_players[k].fitness, teams[i].fix_players[k].original_post, teams[i].fix_players[k].post);
			}
			fprintf(save, "\n");
		}
		encode("Autosave.dat");
	}
	else
	{
		char path[100];
		strcpy(path, "Saves/Save");
		strcat(strcat(path, n), ".dat");
		save = fopen(path, "w+");
		//fprintf : buncha stuff in some lines
		fprintf(save, "%d,%d,%d\n", team_number, random, week);
		int i;
		for (i = 0; i < 16; i++)
		{
			fprintf(save, "%s\n", teams[i].name);
			fprintf(save, "%d,%d,%d,%d,%d,%d,%d,%d\n", teams[i].formation, teams[i].goals_for, teams[i].goals_against, teams[i].win, teams[i].lose, teams[i].draw, teams[i].points, teams[i].player_count);
			int j;
			for (j = 0; j < teams[i].player_count; j++)
			{
				fprintf(save, "%s\n", teams[i].players[j].name);
				fprintf(save, "%d,%d,%d,%d,%d,%c,%c\n", teams[i].players[j].age, teams[i].players[j].number, teams[i].players[j].base_skill, teams[i].players[j].form, teams[i].players[j].fitness, teams[i].players[j].original_post, teams[i].players[j].post);
				fprintf(save, "%d\n", teams[i].is_player_selected[j]);
			}
			for (j = 0; j < 11; j++)
			{
				fprintf(save, "%s\n", teams[i].fix_players[j].name);
				fprintf(save, "%d,%d,%d,%d,%d,%c,%c\n", teams[i].fix_players[j].age, teams[i].fix_players[j].number, teams[i].fix_players[j].base_skill, teams[i].fix_players[j].form, teams[i].fix_players[j].fitness, teams[i].fix_players[j].original_post, teams[i].fix_players[j].post);
			}
		}
		char tmp_encode[100];
		strcpy(tmp_encode, "Save");
		strcat(tmp_encode, n);
		strcat(tmp_encode, ".dat");
		encode(tmp_encode);
	}
	fclose(save);
}

void load(char* n)
{
	void decode(char*);
	FILE* load;
	//three save slots
	if (strcmp(n, "1") == 0)
	{
		//saveslot no. 1
		decode("Save1.dat");
		load = fopen("Saves/Save1.dat", "r+");
	}
	else if (strcmp(n, "2") == 0)
	{
		//saveslot no. 2
		decode("Save2.dat");
		load = fopen("Saves/Save2.dat", "r+");
	}
	else if (strcmp(n, "3") == 0)
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
	int i, j;
	for (i = 0; i < 16; i++)
	{
		fgets(buffer, 100, load);
		strcpy(teams[i].name, buffer);
		teams[i].name[strlen(teams[i].name) - 1] = '\0';
		fgets(buffer, 100, load);
		sscanf(buffer, "%d,%d,%d,%d,%d,%d,%d,%d", &teams[i].formation, &teams[i].goals_for, &teams[i].goals_against, &teams[i].win, &teams[i].lose, &teams[i].draw, &teams[i].points, &teams[i].player_count);
		for (j = 0; j < teams[i].player_count; j++)
		{
			fgets(buffer, 100, load);
			strcpy(teams[i].players[j].name, buffer);
            teams[i].players[j].name[strlen(teams[i].players[j].name) - 1] = '\0';
			fgets(buffer, 100, load);
			sscanf(buffer, "%d,%d,%d,%d,%d,%c,%c", &teams[i].players[j].age, &teams[i].players[j].number, &teams[i].players[j].base_skill, &teams[i].players[j].form, &teams[i].players[j].fitness, &teams[i].players[j].original_post, &teams[i].players[j].post);
			fgets(buffer, 100, load);
			sscanf(buffer, "%d", &teams[i].is_player_selected[j]);
		}
		for (j = 0; j < 11; j++)
		{
			fgets(buffer, 100, load);
			strcpy(teams[i].fix_players[j].name, buffer);
            teams[i].fix_players[j].name[strlen(teams[i].fix_players[j].name)- 1] = '\0';
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
		int i;
		for (i = 0; tmp[i] != '\0'; i++)
		{
			tmp[i] += 10;
		}
		fprintf(fh, "%s", tmp);
		fseek(fh, 0, SEEK_END);
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
		int i;
		for (i = 0; tmp[i] != '\0'; i++)
		{
			tmp[i] -= 10;
		}
		fprintf(fh, "%s", tmp);
		fseek(fh, 0, SEEK_END);
	}
	fclose(fh);
}

void swapPlayers(int team_num, int player1, int player2)//swap 2 players attributes
{
	char name_temp[100], post_temp;
	int int_temp;
	//name change
	strcpy(name_temp, teams[team_num].players[player1].name);
	strcpy(teams[team_num].players[player1].name, teams[team_num].players[player2].name);
	strcpy(teams[team_num].players[player2].name, name_temp);
	//post change
	post_temp = teams[team_num].players[player1].original_post;
	teams[team_num].players[player1].original_post = teams[team_num].players[player2].original_post;
	teams[team_num].players[player2].original_post = post_temp;

	post_temp = teams[team_num].players[player1].post;
	teams[team_num].players[player1].post = teams[team_num].players[player2].post;
	teams[team_num].players[player2].post = post_temp;

	//age change
	int_temp = teams[team_num].players[player1].age;
	teams[team_num].players[player1].age = teams[team_num].players[player2].age;
	teams[team_num].players[player2].age = int_temp;
	//number change
	int_temp = teams[team_num].players[player1].number;
	teams[team_num].players[player1].number = teams[team_num].players[player2].number;
	teams[team_num].players[player2].number = int_temp;
	//skill change
	int_temp = teams[team_num].players[player1].skill;
	teams[team_num].players[player1].skill = teams[team_num].players[player2].skill;
	teams[team_num].players[player2].skill = int_temp;
	//base skill change
	int_temp = teams[team_num].players[player1].base_skill;
	teams[team_num].players[player1].base_skill = teams[team_num].players[player2].base_skill;
	teams[team_num].players[player2].base_skill = int_temp;
	//fitness
	int_temp = teams[team_num].players[player1].fitness;
	teams[team_num].players[player1].fitness = teams[team_num].players[player2].fitness;
	teams[team_num].players[player2].fitness = int_temp;
	//form
	int_temp = teams[team_num].players[player1].form;
	teams[team_num].players[player1].form = teams[team_num].players[player2].form;
	teams[team_num].players[player2].form = int_temp;
}
int playerOverall(int team_num, int player_num)//calculates player overall
{
	return (0.5 * teams[team_num].players[player_num].base_skill + 0.3 * teams[team_num].players[player_num].form + 0.2 * teams[team_num].players[player_num].fitness);
}
void teamSort(int team_num)//sort the team
{
	int i, j;
	for (i = 0; i < teams[team_num].player_count; i++)
	{
		for(j = i + 1; j < teams[team_num].player_count; j++)
		{
			if(playerOverall(team_num, i) < playerOverall(team_num, j))
				swapPlayers(team_num, i, j);
		}
	}
	switch(teams[team_num].formation)
	{
		case 0 ://4-4-2
			for(i = 0 ; i < teams[team_num].player_count ; i++)
			{
				if(teams[team_num].players[i].post == 'G')
				{
					strcpy(teams[team_num].fix_players[0].name, teams[team_num].players[i].name);
					teams[team_num].fix_players[0].original_post = teams[team_num].players[i].post;
					teams[team_num].fix_players[0].post = teams[team_num].players[i].post;
					teams[team_num].fix_players[0].age = teams[team_num].players[i].age;
				 	teams[team_num].fix_players[0].skill = teams[team_num].players[i].skill;
					teams[team_num].fix_players[0].base_skill = teams[team_num].players[i].base_skill;
					teams[team_num].fix_players[0].fitness = teams[team_num].players[i].fitness;
					teams[team_num].fix_players[0].form = teams[team_num].players[i].form;
					teams[team_num].fix_players[0].number = teams[team_num].players[i].number;
					break;
				}
			}
			j = 1;
			for(i = 0 ; i < teams[team_num].player_count ; i++)
			{
				if(teams[team_num].players[i].post == 'D')
				{
				    strcpy(teams[team_num].fix_players[j].name, teams[team_num].players[i].name);
					teams[team_num].fix_players[j].original_post = teams[team_num].players[i].post;
					teams[team_num].fix_players[j].post = teams[team_num].players[i].post;
					teams[team_num].fix_players[j].age = teams[team_num].players[i].age;
				 	teams[team_num].fix_players[j].skill = teams[team_num].players[i].skill;
					teams[team_num].fix_players[j].base_skill = teams[team_num].players[i].base_skill;
					teams[team_num].fix_players[j].fitness = teams[team_num].players[i].fitness;
					teams[team_num].fix_players[j].form = teams[team_num].players[i].form;
					teams[team_num].fix_players[j].number = teams[team_num].players[i].number;
					j++;
					if (j == 5)
						break;
				}
			}
			for(i = 0 ; i < teams[team_num].player_count ; i++)
			{
				if(teams[team_num].players[i].post == 'M')
				{
				    strcpy(teams[team_num].fix_players[j].name, teams[team_num].players[i].name);
					teams[team_num].fix_players[j].original_post = teams[team_num].players[i].post;
					teams[team_num].fix_players[j].post = teams[team_num].players[i].post;
					teams[team_num].fix_players[j].age = teams[team_num].players[i].age;
				 	teams[team_num].fix_players[j].skill = teams[team_num].players[i].skill;
					teams[team_num].fix_players[j].base_skill = teams[team_num].players[i].base_skill;
					teams[team_num].fix_players[j].fitness = teams[team_num].players[i].fitness;
					teams[team_num].fix_players[j].form = teams[team_num].players[i].form;
					teams[team_num].fix_players[j].number = teams[team_num].players[i].number;
					j++;
					if (j == 9)
						break;
				}
			}
			for(i = 0 ; i < teams[team_num].player_count ; i++)
			{
				if(teams[team_num].players[i].post == 'A')
				{
				    strcpy(teams[team_num].fix_players[j].name, teams[team_num].players[i].name);
					teams[team_num].fix_players[j].original_post = teams[team_num].players[i].post;
					teams[team_num].fix_players[j].post = teams[team_num].players[i].post;
					teams[team_num].fix_players[j].age = teams[team_num].players[i].age;
				 	teams[team_num].fix_players[j].skill = teams[team_num].players[i].skill;
					teams[team_num].fix_players[j].base_skill = teams[team_num].players[i].base_skill;
					teams[team_num].fix_players[j].fitness = teams[team_num].players[i].fitness;
					teams[team_num].fix_players[j].form = teams[team_num].players[i].form;
					teams[team_num].fix_players[j].number = teams[team_num].players[i].number;
					j++;
					if (j == 11)
						break;
				}
			}
			break;
		case 1 ://4-3-3
			for(i = 0 ; i < teams[team_num].player_count ; i++)
			{
				if(teams[team_num].players[i].post == 'G')
				{
				    strcpy(teams[team_num].fix_players[j].name, teams[team_num].players[i].name);
					teams[team_num].fix_players[0].original_post = teams[team_num].players[i].post;
					teams[team_num].fix_players[0].post = teams[team_num].players[i].post;
					teams[team_num].fix_players[0].age = teams[team_num].players[i].age;
				 	teams[team_num].fix_players[0].skill = teams[team_num].players[i].skill;
					teams[team_num].fix_players[0].base_skill = teams[team_num].players[i].base_skill;
					teams[team_num].fix_players[0].fitness = teams[team_num].players[i].fitness;
					teams[team_num].fix_players[0].form = teams[team_num].players[i].form;
					teams[team_num].fix_players[0].number = teams[team_num].players[i].number;
					break;
				}
			}
			j = 1;
			for(i = 0 ; i < teams[team_num].player_count ; i++)
			{
				if(teams[team_num].players[i].post == 'D')
				{
				    strcpy(teams[team_num].fix_players[j].name, teams[team_num].players[i].name);
					teams[team_num].fix_players[j].original_post = teams[team_num].players[i].post;
					teams[team_num].fix_players[j].post = teams[team_num].players[i].post;
					teams[team_num].fix_players[j].age = teams[team_num].players[i].age;
				 	teams[team_num].fix_players[j].skill = teams[team_num].players[i].skill;
					teams[team_num].fix_players[j].base_skill = teams[team_num].players[i].base_skill;
					teams[team_num].fix_players[j].fitness = teams[team_num].players[i].fitness;
					teams[team_num].fix_players[j].form = teams[team_num].players[i].form;
					teams[team_num].fix_players[j].number = teams[team_num].players[i].number;
					j++;
					if (j == 5)
						break;
				}
			}
			for(i = 0 ; i < teams[team_num].player_count ; i++)
			{
				if(teams[team_num].players[i].post == 'M')
				{
				    strcpy(teams[team_num].fix_players[j].name, teams[team_num].players[i].name);
					teams[team_num].fix_players[j].original_post = teams[team_num].players[i].post;
					teams[team_num].fix_players[j].post = teams[team_num].players[i].post;
					teams[team_num].fix_players[j].age = teams[team_num].players[i].age;
				 	teams[team_num].fix_players[j].skill = teams[team_num].players[i].skill;
					teams[team_num].fix_players[j].base_skill = teams[team_num].players[i].base_skill;
					teams[team_num].fix_players[j].fitness = teams[team_num].players[i].fitness;
					teams[team_num].fix_players[j].form = teams[team_num].players[i].form;
					teams[team_num].fix_players[j].number = teams[team_num].players[i].number;
					j++;
					if (j == 8)
						break;
				}
			}
			for(i = 0 ; i < teams[team_num].player_count ; i++)
			{
				if(teams[team_num].players[i].post == 'A')
				{
				    strcpy(teams[team_num].fix_players[j].name, teams[team_num].players[i].name);
					teams[team_num].fix_players[j].original_post = teams[team_num].players[i].post;
					teams[team_num].fix_players[j].post = teams[team_num].players[i].post;
					teams[team_num].fix_players[j].age = teams[team_num].players[i].age;
				 	teams[team_num].fix_players[j].skill = teams[team_num].players[i].skill;
					teams[team_num].fix_players[j].base_skill = teams[team_num].players[i].base_skill;
					teams[team_num].fix_players[j].fitness = teams[team_num].players[i].fitness;
					teams[team_num].fix_players[j].form = teams[team_num].players[i].form;
					teams[team_num].fix_players[j].number = teams[team_num].players[i].number;
					j++;
					if (j == 11)
						break;
				}
			}
			break;
		case 2 ://5-4-1
			for(i = 0 ; i < teams[team_num].player_count ; i++)
			{
				if(teams[team_num].players[i].post == 'G')
				{
				    strcpy(teams[team_num].fix_players[j].name, teams[team_num].players[i].name);
					teams[team_num].fix_players[0].original_post = teams[team_num].players[i].post;
					teams[team_num].fix_players[0].post = teams[team_num].players[i].post;
					teams[team_num].fix_players[0].age = teams[team_num].players[i].age;
				 	teams[team_num].fix_players[0].skill = teams[team_num].players[i].skill;
					teams[team_num].fix_players[0].base_skill = teams[team_num].players[i].base_skill;
					teams[team_num].fix_players[0].fitness = teams[team_num].players[i].fitness;
					teams[team_num].fix_players[0].form = teams[team_num].players[i].form;
					teams[team_num].fix_players[0].number = teams[team_num].players[i].number;
					break;
				}
			}
			j = 1;
			for(i = 0 ; i < teams[team_num].player_count ; i++)
			{
				if(teams[team_num].players[i].post == 'D')
				{
				    strcpy(teams[team_num].fix_players[j].name, teams[team_num].players[i].name);
					teams[team_num].fix_players[j].original_post = teams[team_num].players[i].post;
					teams[team_num].fix_players[j].post = teams[team_num].players[i].post;
					teams[team_num].fix_players[j].age = teams[team_num].players[i].age;
				 	teams[team_num].fix_players[j].skill = teams[team_num].players[i].skill;
					teams[team_num].fix_players[j].base_skill = teams[team_num].players[i].base_skill;
					teams[team_num].fix_players[j].fitness = teams[team_num].players[i].fitness;
					teams[team_num].fix_players[j].form = teams[team_num].players[i].form;
					teams[team_num].fix_players[j].number = teams[team_num].players[i].number;
					j++;
					if (j == 5)
						break;
				}
			}
			for(i = 0 ; i < teams[team_num].player_count ; i++)
			{
				if(teams[team_num].players[i].post == 'M')
				{
				    strcpy(teams[team_num].fix_players[j].name, teams[team_num].players[i].name);
					teams[team_num].fix_players[j].original_post = teams[team_num].players[i].post;
					teams[team_num].fix_players[j].post = teams[team_num].players[i].post;
					teams[team_num].fix_players[j].age = teams[team_num].players[i].age;
				 	teams[team_num].fix_players[j].skill = teams[team_num].players[i].skill;
					teams[team_num].fix_players[j].base_skill = teams[team_num].players[i].base_skill;
					teams[team_num].fix_players[j].fitness = teams[team_num].players[i].fitness;
					teams[team_num].fix_players[j].form = teams[team_num].players[i].form;
					teams[team_num].fix_players[j].number = teams[team_num].players[i].number;
					j++;
					if (j == 10)
						break;
				}
			}
			for(i = 0 ; i < teams[team_num].player_count ; i++)
			{
				if(teams[team_num].players[i].post == 'A')
				{
				    strcpy(teams[team_num].fix_players[j].name, teams[team_num].players[i].name);
					teams[team_num].fix_players[j].original_post = teams[team_num].players[i].post;
					teams[team_num].fix_players[j].post = teams[team_num].players[i].post;
					teams[team_num].fix_players[j].age = teams[team_num].players[i].age;
				 	teams[team_num].fix_players[j].skill = teams[team_num].players[i].skill;
					teams[team_num].fix_players[j].base_skill = teams[team_num].players[i].base_skill;
					teams[team_num].fix_players[j].fitness = teams[team_num].players[i].fitness;
					teams[team_num].fix_players[j].form = teams[team_num].players[i].form;
					teams[team_num].fix_players[j].number = teams[team_num].players[i].number;
					j++;
					if (j == 11)
						break;
				}
			}
			break;
		case 3 ://3-5-2
			for(i = 0 ; i < teams[team_num].player_count ; i++)
			{
				if(teams[team_num].players[i].post == 'G')
				{
				    strcpy(teams[team_num].fix_players[j].name, teams[team_num].players[i].name);
					teams[team_num].fix_players[0].original_post = teams[team_num].players[i].post;
					teams[team_num].fix_players[0].post = teams[team_num].players[i].post;
					teams[team_num].fix_players[0].age = teams[team_num].players[i].age;
				 	teams[team_num].fix_players[0].skill = teams[team_num].players[i].skill;
					teams[team_num].fix_players[0].base_skill = teams[team_num].players[i].base_skill;
					teams[team_num].fix_players[0].fitness = teams[team_num].players[i].fitness;
					teams[team_num].fix_players[0].form = teams[team_num].players[i].form;
					teams[team_num].fix_players[0].number = teams[team_num].players[i].number;
					break;
				}
			}
			j = 1;
			for(i = 0 ; i < teams[team_num].player_count ; i++)
			{
				if(teams[team_num].players[i].post == 'D')
				{
				    strcpy(teams[team_num].fix_players[j].name, teams[team_num].players[i].name);
					teams[team_num].fix_players[j].original_post = teams[team_num].players[i].post;
					teams[team_num].fix_players[j].post = teams[team_num].players[i].post;
					teams[team_num].fix_players[j].age = teams[team_num].players[i].age;
				 	teams[team_num].fix_players[j].skill = teams[team_num].players[i].skill;
					teams[team_num].fix_players[j].base_skill = teams[team_num].players[i].base_skill;
					teams[team_num].fix_players[j].fitness = teams[team_num].players[i].fitness;
					teams[team_num].fix_players[j].form = teams[team_num].players[i].form;
					teams[team_num].fix_players[j].number = teams[team_num].players[i].number;
					j++;
					if (j == 4)
						break;
				}
			}
			for(i = 0 ; i < teams[team_num].player_count ; i++)
			{
				if(teams[team_num].players[i].post == 'M')
				{
				    strcpy(teams[team_num].fix_players[j].name, teams[team_num].players[i].name);
					teams[team_num].fix_players[j].original_post = teams[team_num].players[i].post;
					teams[team_num].fix_players[j].post = teams[team_num].players[i].post;
					teams[team_num].fix_players[j].age = teams[team_num].players[i].age;
				 	teams[team_num].fix_players[j].skill = teams[team_num].players[i].skill;
					teams[team_num].fix_players[j].base_skill = teams[team_num].players[i].base_skill;
					teams[team_num].fix_players[j].fitness = teams[team_num].players[i].fitness;
					teams[team_num].fix_players[j].form = teams[team_num].players[i].form;
					teams[team_num].fix_players[j].number = teams[team_num].players[i].number;
					j++;
					if (j == 9)
						break;
				}
			}
			for(i = 0 ; i < teams[team_num].player_count ; i++)
			{
				if(teams[team_num].players[i].post == 'A')
				{
				    strcpy(teams[team_num].fix_players[j].name, teams[team_num].players[i].name);
					teams[team_num].fix_players[j].original_post = teams[team_num].players[i].post;
					teams[team_num].fix_players[j].post = teams[team_num].players[i].post;
					teams[team_num].fix_players[j].age = teams[team_num].players[i].age;
				 	teams[team_num].fix_players[j].skill = teams[team_num].players[i].skill;
					teams[team_num].fix_players[j].base_skill = teams[team_num].players[i].base_skill;
					teams[team_num].fix_players[j].fitness = teams[team_num].players[i].fitness;
					teams[team_num].fix_players[j].form = teams[team_num].players[i].form;
					teams[team_num].fix_players[j].number = teams[team_num].players[i].number;
					j++;
					if (j == 11)
						break;
				}
			}
			break;
	}
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

void tableSort()
{
	int i,j,int_temp;
	char name_temp[100];
	for (i = 0 ; i < 16 ; i++)
	{
		strcpy(sorted_teams[i].name, teams[i].name);
		sorted_teams[i].win = teams[i].win;
		sorted_teams[i].draw = teams[i].draw;
		sorted_teams[i].lose = teams[i].lose;
		sorted_teams[i].goals_for = teams[i].goals_against;
		sorted_teams[i].goals_against = teams[i].goals_against;
		sorted_teams[i].points = teams[i].points;
	}
	for (i = 0 ; i < 16 ; i++)
	{
		for (j = i + 1 ; j < 16 ; j++)
		{
			if(sorted_teams[i].points < sorted_teams[j].points)
			{
					strcpy(name_temp, sorted_teams[i].name);
					strcpy(sorted_teams[i].name, sorted_teams[j].name);
					strcpy(sorted_teams[j].name, name_temp);

					int_temp = sorted_teams[i].win;
					sorted_teams[i].win = sorted_teams[j].win;
					sorted_teams[j].win = int_temp;

					int_temp = sorted_teams[i].draw;
					sorted_teams[i].draw = sorted_teams[j].draw;
					sorted_teams[j].draw = int_temp;

					int_temp = sorted_teams[i].lose;
					sorted_teams[i].lose = sorted_teams[j].lose;
					sorted_teams[j].lose = int_temp;

					int_temp = sorted_teams[i].goals_for;
					sorted_teams[i].goals_for = sorted_teams[j].goals_for;
					sorted_teams[j].goals_for = int_temp;

					int_temp = sorted_teams[i].goals_against;
					sorted_teams[i].goals_against = sorted_teams[j].goals_against;
					sorted_teams[j].goals_against = int_temp;

					int_temp = sorted_teams[i].points;
					sorted_teams[i].points = sorted_teams[j].points;
					sorted_teams[j].points = int_temp;
			}
			if(sorted_teams[i].points == sorted_teams[j].points && ((sorted_teams[i].goals_for - sorted_teams[i].goals_against) < (sorted_teams[j].goals_for - sorted_teams[j].goals_against)))
			{
                    strcpy(name_temp, sorted_teams[i].name);
					strcpy(sorted_teams[i].name, sorted_teams[j].name);
					strcpy(sorted_teams[j].name, name_temp);

					int_temp = sorted_teams[i].win;
					sorted_teams[i].win = sorted_teams[j].win;
					sorted_teams[j].win = int_temp;

					int_temp = sorted_teams[i].draw;
					sorted_teams[i].draw = sorted_teams[j].draw;
					sorted_teams[j].draw = int_temp;

					int_temp = sorted_teams[i].lose;
					sorted_teams[i].lose = sorted_teams[j].lose;
					sorted_teams[j].lose = int_temp;

					int_temp = sorted_teams[i].goals_for;
					sorted_teams[i].goals_for = sorted_teams[j].goals_for;
					sorted_teams[j].goals_for = int_temp;

					int_temp = sorted_teams[i].goals_against;
					sorted_teams[i].goals_against = sorted_teams[j].goals_against;
					sorted_teams[j].goals_against = int_temp;

					int_temp = sorted_teams[i].points;
					sorted_teams[i].points = sorted_teams[j].points;
					sorted_teams[j].points = int_temp;
			}
		}
	}
}
