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

//for gnu readline
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h> 

struct RequiredAuthLevel{
	unsigned long read;
	unsigned long create;
	unsigned long update;
	unsigned long del;
};

// currently only used to differ between personal and everyone's entries in the rent mechanic
struct RequiredAuthLevelPersonal{
	unsigned long read;
	unsigned long create;
	unsigned long update;
	unsigned long del;
};

class Auth{

public:
	Auth(unsigned long uid);
	User* getUser();
	Role* getRole();
private:
	User* user;
	Role* role;
	Repository<User>* ur;
	Repository<Role>* rr;
};

class Command {
public:
	Command(std::vector<std::string> vs, Auth* a){
		command = vs;
		auth = a;
	}
	virtual bool read() = 0;
	virtual bool create() = 0;
	virtual bool update() = 0;
	virtual bool del() = 0;

protected:
	std::vector<std::string> command;
	Auth* auth;
};

class UICommandBook : public Command{

public:
	UICommandBook(std::vector<std::string> vs, Auth* a);
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
	// read, create, update, delete
	RequiredAuthLevel ral = { 1, 2, 2, 2 };
};

class UICommandUser : public Command{

public:
	UICommandUser(std::vector<std::string> vs, Auth* a);
	bool read();
	bool create();
	bool update();
	bool del();

private:
	std::string name;
	std::string surname;
	long role;
	Repository<Book>* br;
	Repository<User>* ur;
	// read, create, update, delete
	RequiredAuthLevel ral = { 1, 2, 2, 2};
};

class UICommandRole : public Command{

public:
	UICommandRole(std::vector<std::string> vs, Auth* a);
	bool read();
	bool create();
	bool update();
	bool del();

private:
	std::string description;
	Repository<Role>* rr;
	// read, create, update, delete
	RequiredAuthLevel ral = { 1, 2, 2, 2};
};

class UICommandRent : public Command{

public:
	UICommandRent(std::vector<std::string> vs, Auth* a);
	bool read();
	bool create();
	bool update();
	bool del();
	// read, create, update, delete
	RequiredAuthLevel ral = { 2, 2, 2, 2};

	// read, create, update, delete
	RequiredAuthLevelPersonal ralp = {1, 1, 1, 1};

private:
	long user_id;
	long book_id;
	long timestamp;
	Repository<Book>* br;
	Repository<UserBook>* ubr;
};


class Action{

public:
	static Command* getCommand(std::string type, std::vector<std::string> vs, Auth* auth);
};

class CLI{

private:
	std::string getCommand(std::string prompt);
	//void printPrompt();
	bool parseCommand(std::string s);	
	void printCommand();
	void authenticate();

	std::vector<std::string> command;
	//this must be a char array since this is used by rl_gets()
	const char* prompt = string("$ > ").c_str();
	Auth* auth;
	bool running;
	char delim;

public:
	CLI();
	void start();
};

char * rl_gets();

#endif
