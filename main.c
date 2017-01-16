#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <limits.h>

int arrow_counter = 0;
char *team_name;

void init();
void start();
void teamLists();
void game();
void print(char *, int, int);
void printSpace(int, int, int);
int windowsWindowWidth();
void arrow(int);

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
}

void game()
{
    if (arrow_counter == 0)
    {
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
    }
}

void teamLists()
{
    FILE *f = fopen("teams\teams.csv", "r");
    char *team[16];
    int i, j;
    for (i = 0; i < 16; i++)
        fgets(team[i], 100, f);
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
                for (i = 0; i < 16; i++)
                {
                    if (arrow_counter == i)
                    {
                        //printSpace((27 - strlen(team[i])) / 2, 1, 1);
                        print(team[i], 1, 1);
                        //printSpace(27 - (27 - strlen(team[i])) / 2, 1, 1);
                    }
                    else
                    {
                        //printSpace((27 - strlen(team[i])) / 2, 1, 0);
                        print(team[i], 1, 0);
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

    printf("%s\n", s);
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
