#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <limits.h>

int arrow_counter = 0;

void init();
void start();
void print(char *, int);
int windowsWindowWidth();
int arrow(int);
int color(int);

int main()
{
    init();
    start();
    return 0;
}

void init()
{

    print("In The Name Of God", color(0));
    print("Ultimate Football Manager\n", color(0));
    print("\"Cyan\" Team Project", color(0));
    print("By:", color(0));
    print("Arian Tashakor", color(0));
    print("Mehrdad Khanzadeh", color(0));
    print("Hessam Hashemizadeh\n", color(0));
    print("Press Any Key To Start Game...", color(0));
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
                	print("New Game", color(1));
                	print("Continue Previous Save", color(0));
                	break;
            	case 1 :
                	print("New Game", color(0));
                	print("Continue Previous Save", color(1));
                	break;
        	}
		}
		counter_temp = arrow_counter;
    }
}

int windowsWindowWidth()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns, rows;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    return columns;
}

void print(char *s, int clr)
{
    const int total_width = windowsWindowWidth();
    const int s_width = strlen(s);
    const int field_width = (total_width - s_width) / 2 + s_width;

    printf("%*s\n", field_width, s);

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

int color(int type)
{
    return 0;
}

