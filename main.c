#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void init();
void alignCenter(char *);
int windowsWindowWidth();

int main()
{
    init();

    return 0;
}

void init()
{
    alignCenter("In The Name Of God");
    alignCenter("Ultimate Football Manager\n");
    alignCenter("\"Cyan\" Team Project");
    alignCenter("By:");
    alignCenter("Arian Tashakor");
    alignCenter("Mehrdad Khanzadeh");
    alignCenter("Hessam Hashemizadeh\n");
    alignCenter("Press Any Key To Start Game...");
    //Watch Out!
    getch();
    system("cls");


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

void alignCenter(char *s)
{
    const int total_width = windowsWindowWidth();
    const int s_width = strlen(s);
    const int field_width = (total_width - s_width) / 2 + s_width;

    printf("%*s\n", field_width, s);

    return;
}
