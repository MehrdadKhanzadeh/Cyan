#include <stdio.h>
#include <windows.h>

int main() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Save current attributes */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
	SetConsoleTextAttribute(hConsole, BACKGROUND_RED | FOREGROUND_GREEN);
    printf("                                          \n");
	printf("This is some nice COLORFUL text, isn't it?\n");
	printf("                                          \n");
	SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE | FOREGROUND_GREEN);
    printf("                                          \n");
	printf("This is some nice COLORFUL text, isn't it?\n");
	printf("                                          ");
	
    SetConsoleTextAttribute(hConsole, saved_attributes); //reset to default
    return 0;
}
