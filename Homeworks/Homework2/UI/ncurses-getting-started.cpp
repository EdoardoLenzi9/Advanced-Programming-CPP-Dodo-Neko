#include <curses.h>
#include <iostream>

using namespace std; 

int main(){
	//init 
	initscr(); //initialise the terminal window
	cbreak(); //take control of the keyboard without buffering, except control sequences
	noecho(); //disable the echoing of characters
	keypad(stdscr, TRUE); //take control of the function keys and arrow keys

	//main
	printw("Type a character:\n");
	int ch = getch(); 

	if(ch == KEY_F(1)) printw("F1 pressed!");
	else{
		printw("Pressed key: %c, in bold:", ch);
		attron(A_BOLD); //set bold to on
		printw("%c", ch);
		attron(A_BOLD); //set bold to off
	}
	refresh();
	getch();

	//end
	endwin();
	return 0;
}
