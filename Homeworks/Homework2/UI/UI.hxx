#ifndef UI_H
#define UI_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>


class Command {
public:
	Command(std::vector<std::string> vs){
		command = vs;
	}
	virtual std::string read() = 0;
	virtual int create() = 0;
	virtual int update() = 0;
	virtual bool del() = 0;

protected:
	std::vector<std::string> command;
};

class UICommandBook : public Command{

public:
	UICommandBook(std::vector<std::string> vs);
	std::string read();
	int create();
	int update();
	bool del();

private:
	int id;
	int copies;
	int rentedCopies;
	std::string title;
	std::string author;
	std::string publisher;
};

class UICommandUser : public Command{

public:
	UICommandUser(std::vector<std::string> vs);
	std::string read();
	int create();
	int update();
	bool del();

private:
	int id;
	std::string name;
	std::string surname;
};

class UICommandRole : public Command{

public:
	UICommandRole(std::vector<std::string> vs);
	std::string read();
	int create();
	int update();
	bool del();

private:
	int id;
	std::string name;
};


class Action{

public:
	static Command* getCommand(std::string type, std::vector<std::string> vs);
};

class CLI{

private:
	std::string getCommand();
	void printPrompt();
	bool parseCommand(std::string s);	
	void printCommand();

	std::vector<std::string> command;
	bool running;
	char delim;

public:
	CLI();
	void start();
};

#endif