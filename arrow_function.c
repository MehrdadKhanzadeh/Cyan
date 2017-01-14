
#include <stdio.h> 
#include <limits.h> 
#include <stdlib.h> 
#include <windows.h> 
int arrow_counter = 0;
void arrow(int page_items)
{
	if ( GetAsyncKeyState ( VK_UP ) & SHRT_MAX )
	{
		puts ( "Up arrow is pressed" );
    	arrow_counter = (arrow_counter + page_items - 1) % page_items;
		printf("Counter = %d\n",arrow_counter);	
	}
	else if ( GetAsyncKeyState ( VK_DOWN ) & SHRT_MAX )
	{
    	puts ( "Down arrow is pressed" );
    	arrow_counter = (arrow_counter + page_items + 1) % page_items;
		printf("Counter = %d\n",arrow_counter);
	}
	/*else if ( GetAsyncKeyState ( VK_LEFT ) & SHRT_MAX )
      puts ( "Left arrow is pressed" );
    else if ( GetAsyncKeyState ( VK_RIGHT ) & SHRT_MAX )
      puts ( "Right arrow is pressed" );	
	*/
}
int main ( void )
{
  short esc = 0;

  while ( !esc ) {
    esc = GetAsyncKeyState ( VK_RETURN );
    arrow(2);
  }
switch (arrow_counter){
	case 0 :
		puts ("New Game");
		break;
	case 1 :
		puts ("Load Game");
		break;
}

  return EXIT_SUCCESS;
}
