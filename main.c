#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <limits.h>

int arrow_counter = 0;

void init();
void start();
void print(char *, int, int);
int windowsWindowWidth();
int arrow(int);

int main()
{
    init();
    start();
    return 0;
}

void init()
{
    system("color 60");
    print("In The Name Of God", 0, 1);
    print("Ultimate Football Manager\n", 0, 1);
    print("\"Cyan\" Team Project", 0, 1);
    print("By:", 0, 1);
    print("Arian Tashakor", 0, 1);
    print("Mehrdad Khanzadeh", 0, 1);
    print("Hessam Hashemizadeh\n", 0, 1);
    print("Press Any Key To Start Game...", 0, 1);
    //Watch Out!
    getch();
    system("cls");
    return;
}

void start()
{
    short esc = 0;
	int counter_temp = 9;
    while (arrow(2))
    {
        if(counter_temp != arrow_counter){
			system("cls");
        	switch (arrow_counter)
        	{
            	case 0 :
            	    puts("\n\n\n\n");
            	    print("                        ", 1, 1);
                	print("        New Game        ", 1, 1);
            	    print("                        ", 1, 1);
            	    print("                        ", 0, 1);
                	print(" Continue Previous Save ", 0, 1);
            	    print("                        ", 0, 1);
                	break;
            	case 1 :
            	    puts("\n\n\n\n");
            	    print("                        ", 0, 1);
                	print("        New Game        ", 0, 1);
            	    print("                        ", 0, 1);
            	    print("                        ", 1, 1);
                	print(" Continue Previous Save ", 1, 1);
            	    print("                        ", 1, 1);
                	break;
        	}
		}
		counter_temp = arrow_counter;
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
    }

    printf("%s\n", s);
    SetConsoleTextAttribute(hConsole, saved_attributes);
    return;
}

int arrow(int page_items)
{
	if (GetAsyncKeyState(VK_UP) & SHRT_MAX)
    	arrow_counter = (arrow_counter + page_items - 1) % page_items;
	else if (GetAsyncKeyState(VK_DOWN) & SHRT_MAX)
    	arrow_counter = (arrow_counter + page_items + 1) % page_items;
    else if (GetAsyncKeyState(VK_RETURN))
        return 0;
    return 1;
	/*else if ( GetAsyncKeyState ( VK_LEFT ) & SHRT_MAX )
      puts ( "Left arrow is pressed" );
    else if ( GetAsyncKeyState ( VK_RIGHT ) & SHRT_MAX )
      puts ( "Right arrow is pressed" );
	*/
}
