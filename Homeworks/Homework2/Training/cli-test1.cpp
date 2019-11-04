#include <ncurses.h> 
#include <string>

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
		getmaxyx(stdscr, rows, cols); //set the current window dimensions
		updatePos();
		box(stdscr, 0, 0);
	}

	~StandardScreen(){
		endwin();
	}

	void refreshScreen(){
		refresh();
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

int main(){
	string test; 
	//initscr();
	StandardScreen *win = new StandardScreen();
	win->addAttr(A_BOLD);
	win->print("Enter something:", 1, 1);
	win->moveCursor(1, 2);
	win->refreshScreen();

	Window *menu = new Window(30,10,5,5);
	menu->print("another test", 0, 0);

	getch();

}
