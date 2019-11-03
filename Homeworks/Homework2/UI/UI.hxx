#ifndef UI_H
#define UI_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include <odb/database.hxx>
#include <odb/transaction.hxx>
#include <odb/schema-catalog.hxx>
#include <odb/sqlite/database.hxx>

#include "Repository.hxx"
#include "Book.hxx"
#include "Book-odb.hxx"
#include "Role.hxx"
#include "Role-odb.hxx"
#include "User.hxx"
#include "User-odb.hxx"
#include "UserBook.hxx"
#include "UserBook-odb.hxx"

#include "UserService.hxx"
#include "BookService.hxx"
#include "UserBookService.hxx"


class Command {
public:
	Command(std::vector<std::string> vs){
		command = vs;
	}
	virtual bool read() = 0;
	virtual bool create() = 0;
	virtual bool update() = 0;
	virtual bool del() = 0;

protected:
	std::vector<std::string> command;
};

class UICommandBook : public Command{

public:
	UICommandBook(std::vector<std::string> vs);
	bool read();
	bool create();
	bool update();
	bool del();

private:
	int copies;
	int rentedCopies;
	std::string title;
	std::string author;
	std::string publisher;
	Repository<Book>* br;
};

class UICommandUser : public Command{

public:
	UICommandUser(std::vector<std::string> vs);
	bool read();
	bool create();
	bool update();
	bool del();

private:
	std::string name;
	std::string surname;
	long role;
	Repository<User>* ur;
};

class UICommandRole : public Command{

public:
	UICommandRole(std::vector<std::string> vs);
	bool read();
	bool create();
	bool update();
	bool del();

private:
	std::string description;
	Repository<Role>* rr;
};

class UICommandRent : public Command{

public:
	UICommandRent(std::vector<std::string> vs);
	bool read();
	bool create();
	bool update();
	bool del();

private:
	long user_id;
	long book_id;
	long timestamp;
	Repository<Book>* br;
	Repository<UserBook>* ubr;
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