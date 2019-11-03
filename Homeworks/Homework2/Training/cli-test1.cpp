#include <ncurses.h> 
#include <string>
#include <vector>

using namespace std;

class CursesWindow{
public: 

	int getRows() {
		return rows;
	}

	int getCols() {
		return cols;
	}
	
	virtual void print(string s, int x, int y){
		mvprintw(y, x, s.c_str());
		updatePos();
	}

	virtual void print(char c, int x, int y){
		string s;
		s.push_back(c);
		print(s, x, y);
	}

	void addAttr(int attr){
		attron(attr);
	}

	void disAttr(int attr){
		attroff(attr);
	}

	int getCurrentRow(){
		return curRow;
	}

	int getCurrentCol(){
		return curCol;
	}

	void moveCursor(int x, int y){
		move(y,x);
		updatePos();
	}

	virtual void printChoices(vector<string> s){
		int i = 1;
		for (string text: s){
			print(text, 1, i++);
		}
	}



protected:
	int rows;
	int cols;
	int curCol;
	int curRow;

	void updatePos(){
		getyx(stdscr, curCol, curRow);
	}
};

class StandardScreen : public CursesWindow {

public: 
	
	StandardScreen(){
		initscr();
		raw();
		noecho();
		getmaxyx(stdscr, rows, cols); //set the current window dimensions
		updatePos();
		keypad(stdscr, TRUE);
		box(stdscr, 0, 0);

	}

	~StandardScreen(){
		endwin();
	}

	void refreshScreen(){
		refresh();
	}

	void clearWindow(){
		clear();
		box(stdscr, 0, 0);
	}


};

class Window : public CursesWindow {

public:
	
	Window(int height, int width, int startx, int starty){
		localWindow = newwin(width, height, starty, startx);
		rows = height;
		cols = width;
		curCol = 0;
		curRow = 0;
		box(localWindow, 0, 0);
		refreshWindow();
	}
	
	~Window(){
		destroy();
	}

	void print(string s, int x , int y){
		mvwprintw(localWindow, y, x, s.c_str());
		refreshWindow();
		updatePos();
	}

	void destroy(){
		wborder(localWindow, ' ', ' ', ' ',' ',' ',' ',' ',' ');
		refreshWindow();
		delwin(localWindow);
	
	}

	void refreshWindow(){ 
		wrefresh(localWindow); 
	}

private: 
	WINDOW *localWindow;
};

class Menu : public Window {

public:
	Menu(vector<string> s, int height, int width, int startx, int starty) : Window(height, width, startx, starty) {
		for (string i: s){
			choices.push_back(i);
		}
		choice = 0;
		choicesAmount = choices.size();
		highlight = 1;
		running = true;
	}

	int getChoice(){
		c = wgetch(localWindow);

		switch (c)
		{
			case KEY_UP:
				if (highlight == 1) highlight = choicesAmount; //to the bottom
				else highlight--; //down
				break;
			case KEY_DOWN:
				if (highlight == choicesAmount) highlight = 1; //back to 1
				else highlight++;
				break;
			case 10: // enter
				choice = highlight;
				break;
			default: 
				attron(A_BOLD);
				print(to_string(c), 5, choicesAmount+2);
				attroff(A_BOLD);
				refreshWindow();
		}

		return choice;

	}

	void printMenu(int hl){
		int x = 2;
		int y = 2;

		for (int i = 0; i < choicesAmount; i++){
			if (hl == i+1){
				attron(A_STANDOUT);
				print(choices[i], x, y);
				attroff(A_STANDOUT);	
			} else {
				print(choices[i], x, y);
			}
			y++;
		}

		refreshWindow();
	}



private:
	int c;
	int highlight;
	int choice;
	int choicesAmount;
	bool running;
	vector<string> choices;
};

class CommandLineInterface{
public: 
	CommandLineInterface(){

		screen = new StandardScreen();
		screen->refreshScreen();
		running = true;
		choicesAmount = choices.size();
		highlight = 1;

	}

	void start(){
		while (running == true){
			
			printMenu(highlight);

			c = wgetch(stdscr);
			
			switch (c)
			{
				case KEY_UP:
					if (highlight == 1) highlight = choicesAmount; //to the bottom
					else highlight--; //down
					break;
				case KEY_DOWN:
					if (highlight == choicesAmount) highlight = 1; //back to 1
					else highlight++;
					break;
				case 10: // enter
					choice = highlight;
					break;
				default: 
					attron(A_BOLD);
					screen->print(to_string(c), 5, choicesAmount+2);
					attroff(A_BOLD);
					screen->refreshScreen();
			}


			switch (choice){
				case 1: 
					Menu *m = new Menu(Users, 10, 5, 5, 5);
					screen->print(to_string(m->getChoice()), 5, choicesAmount+3);

			}


		}

	}

	void printMenu(int hl){
		int x = 2;
		int y = 2;

		for (int i = 0; i < choicesAmount; i++){
			if (hl == i+1){
				attron(A_STANDOUT);
				screen->print(choices[i], x, y);
				attroff(A_STANDOUT);	
			} else {
				screen->print(choices[i], x, y);
			}
			y++;
		}

		screen->refreshScreen();
	}

private:
	int c;
	bool running;
	StandardScreen *screen;
	int choicesAmount;
	int highlight;
	int choice;

	vector<string> choices = {
		"Choice 1", 
		"Choice 2",
		"Choice 3",
		"Exit",
	};

	vector<string> Users = {
		"A",
		"B",
		"C",
		"D",
		"back..",
	};

};

int main(){
	/*	
	StandardScreen *win = new StandardScreen();
	win->refreshScreen();

	bool running = true;

	while (running == true){
		vector<string> choices = {"(1) Menu 1", "(2) Menu 2", "(3) Menu 3"};
		win->printChoices(choices);

		char input = wgetch(stdscr);

		win->print(input, 10,5);

		switch(input){
			case 1: 
				win->clearWindow();
				win->print("You selected 1", 1, 1);
				break;
			case 2:
				win->clearWindow();
				win->print("You selected 2", 1, 1);
				break;
			case 3: 
				win->clearWindow();
				win->print("You selected 3", 1, 1);
				break;
			default: 
				win->clearWindow();
				win->print("fucked up", 1,1);
				running = false;
		}
	}
	*/

	CommandLineInterface* main = new CommandLineInterface();
	main->start();

	endwin();
	return 0;
	//Window *menu = new Window(30,10,5,5);


	/*
	vector<string> choices = {"Selection 1", "Selection 2", "Selection 3"};	
	menu->printChoices(choices);	

	char selection = getch();
	win->clearWindow();
	switch (selection)
	{
		case 1: win->print("Selected 1", win->getCurrentCol()+1, win->getCurrentRow());
			break;
		case 2: win->print("Selected 2", win->getCurrentCol()+1, win->getCurrentRow());
			break;
		case 3: win->print("Selected 3", win->getCurrentCol()+1, win->getCurrentRow());
			break;
		default: win->print("invalid", win->getCurrentCol()+1, win->getCurrentRow());
	}

	win->refreshScreen();
	getch();
	*/
}
