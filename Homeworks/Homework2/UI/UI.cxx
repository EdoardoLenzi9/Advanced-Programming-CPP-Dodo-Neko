#ifndef UI_H
#include "UI.hxx"
#endif

using namespace std;

UICommandBook::Book(vector<string> vs) : Command(vs){
	id = -1;
	copies = -1;
	rentedCopies = -1;
	title = "";
	author = "";
	publisher = "";
}

string UICommandBook::read(){
	if (command.size() < 1) return NULL;
	id = stoi(command.at(0));

	cout << "read command for a book with par: " << id << endl;
	return NULL; //placeholder
}

int UICommandBook::create(){
	//create something
	if (command.size() < 5) return -1;
	else {

		copies = stoi(command.at(0));
		rentedCopies = stoi(command.at(1));
		title = command.at(2);
		author = command.at(3);
		publisher = command.at(4);

	//create book
		cout << "create command for a book with: copies: " 
			<< copies << " rentedCopies: "
			<< rentedCopies << " title: "
			<< title << " author: "
			<< author << " publisher: "
			<< publisher << " "
			<< endl; 

		return id;
	}
}
int UICommandBook::update(){
	if (command.size() < 6) return -1;

	id = stoi(command.at(0));
	copies = stoi(command.at(1));
	rentedCopies = stoi(command.at(2));
	title = command.at(3);
	author = command.at(4);
	publisher = command.at(5);

	//create book
	cout << "update command for a book with: id: " 
		<< id << " copies: " 
		<< copies << " rentedCopies: "
		<< rentedCopies << " title: "
		<< title << " author: "
		<< author << " publisher: "
		<< publisher << " "
		<< endl; 

	return id;
}

bool UICommandBook::del(){
	if (command.size() < 1) return NULL;
	id = stoi(command.at(0));

	cout << "delete command for a book with par: " << id << endl;
	return NULL; //placeholder
}

UICommandUser::User(vector<string> vs) : Command(vs){
	id = -1;
	name = "";
	surname = "";
}

string UICommandUser::read(){
	if (command.size() < 1) return NULL;
	id = stoi(command.at(0));

	cout << "read command for a user with par: " << id << endl;
	return NULL; //placeholder
}

int UICommandUser::create(){
	//create something
	if (command.size() < 2) return -1;
	else {

		name = command.at(0);
		surname = command.at(1);

	//create book
		cout << "create command for a user with: name: " 
			<< name << " surname: "
			<< surname << endl; 

		return id;
	}
}

int UICommandUser::update(){
	if (command.size() < 3) return -1;
	else {
		id = stoi(command.at(0));
		name = command.at(1);
		surname = command.at(2);

	//create book
		cout << "update command for a user with: id: " 
			<< id << " name: "
			<< name << " surname: " 
			<< surname << endl; 

		return id;
	}
}

bool UICommandUser::del(){
	if (command.size() < 1) return NULL;
	id = stoi(command.at(0));

	cout << "delete command for a user with par: " << id << endl;
	return NULL; //placeholder
}

UICommandRole::Role(vector<string> vs) : Command(vs){
	id = -1;
	name = "";
}

string UICommandRole::read(){
	if (command.size() < 1) return NULL;
	id = stoi(command.at(0));

	cout << "read command for a role with par: " << id << endl;
	return NULL; //placeholder
}

int UICommandRole::create(){
	//create something
	if (command.size() < 1) return -1;
	else {

		name = command.at(0);

	//create book
		cout << "create command for a role with: name: " 
			<< name << endl; 

		return id;
	}
}

int UICommandRole::update(){
	if (command.size() < 2) return -1;
	else {
		id = stoi(command.at(0));
		name = command.at(1);

	//create book
		cout << "update command for a role with: id: " 
			<< id << " name: "
			<< name << endl; 

		return id;
	}
}

bool UICommandRole::del(){
	if (command.size() < 1) return false;
	id = stoi(command.at(0));

	cout << "delete command for a role with par: " << id << endl;
	return NULL; //placeholder
}

CLI::CLI(){
	running = 1;
	delim = ' ';
}

string CLI::getCommand(){
	string s;
	getline(cin, s);
	return s;
}

void CLI::printPrompt(){
	cout << "$ > ";
}

bool CLI::parseCommand(string s){
	stringstream ss(s); // make a string stream from the string
	string temp = "";

	string com = ""; 
	string cont = ""; 

	command.clear();
	while (getline(ss, temp, delim)){
		command.push_back(temp);
	}

	cout << "command: " << command.at(1) << endl;

	if (command.size() < 2){
		if (command.front().compare("auth") == 0){
			//auth
			return true;

		} else if (command.front().compare("exit") == 0){
			running = false;
			return true;

		} else return false;
	} else {

	com = command.at(0); // first element is the command
	cont = command.at(1); // second element is the context

	command.erase(command.begin(), command.begin()+2); // delete first and second element

	Command *b = Action::getCommand(cont, command); // returns a book, a role or a user object
	if (b == NULL) return false; 

	if (com.compare("create") == 0) {
		if (b->create() == -1) return false;
	}
	else if (com.compare("update") == 0) {
		if (b->update() == -1) return false;
	}
	else if (com.compare("read") == 0){
		if (b->read().empty()) return false;
	}
	else if (com.compare("delete") == 0) {
		if (b->del() == false) return false;
	}
	else return false;

	return true;
	}
}	

Command* Action::getCommand(string type, vector<string> vs){
	if (type.compare("book") == 0) return new Book(vs);
	else if (type.compare("role") == 0) return new Role(vs);
	else if (type.compare("user") == 0) return new User(vs);

	return NULL;
}

void CLI::printCommand(){
	for (string s: command){
		cout << s << endl;
	}
}

void CLI::start(){

	string s;

	while (running){
		while (s.empty()){
			printPrompt();
			s = getCommand();
		}
		if(! parseCommand(s)) cout << "invalid command!" << endl;
		//printCommand();
		s.clear(); //empty the command buffer
	}
}
