#ifndef UI_H
#include "UI.hxx"
#endif

using namespace std;

UICommandBook::UICommandBook(vector<string> vs) : Command(vs){
	copies = -1;
	rentedCopies = -1;
	title = "";
	author = "";
	publisher = "";
	br = new Repository<Book>();
}

bool UICommandBook::read(){
	if (command.size() < 1) return false;
	long id = stol(command.at(0));

	Book* book = br->read(id);

	if (book == NULL) return false;

	cout << "Book ID: " << book->id() << endl
		 << "Title: " << book->title() << endl
		 << "Author: " << book->author() << endl
		 << "Publisher: " << book->publisher() << endl
		 << "Copies available: " << (book->copies())-(book->rented())
		 << endl;

	return true; 
}

bool UICommandBook::create(){
	if (command.size() < 5) return false;
	
	copies = stoi(command.at(0));
	rentedCopies = stoi(command.at(1));
	title = command.at(2);
	author = command.at(3);
	publisher = command.at(4);

	br->create( new Book(copies, rentedCopies, title, author, publisher) );

	cout << "Created book" << endl;

	return true;
}
bool UICommandBook::update(){
	if (command.size() < 6) return false;

	long id = stol(command.at(0));
	copies = stoi(command.at(1));
	rentedCopies = stoi(command.at(2));
	title = command.at(3);
	author = command.at(4);
	publisher = command.at(5);

	Book* book = br->read(id);

	cout << "old book:" << endl;

	cout << "Book ID: " << book->id() << endl
		 << "Title: " << book->title() << endl
		 << "Author: " << book->author() << endl
		 << "Publisher: " << book->publisher() << endl
		 << "Copies available: " << (book->copies())-(book->rented())
		 << endl;

	book->copies(copies);
	book->rented(rentedCopies);
	book->title(title);
	book->author(author);
	book->publisher(publisher);

	br->update(book);

	book = br->read(id);

	cout << endl << "changed book:" << endl << endl;

	cout << "Book ID: " << book->id() << endl
		 << "Title: " << book->title() << endl
		 << "Author: " << book->author() << endl
		 << "Publisher: " << book->publisher() << endl
		 << "Copies available: " << (book->copies())-(book->rented())
		 << endl;

	return true;
}

bool UICommandBook::del(){
	if (command.size() < 1) return false;
	long id = stol(command.at(0));

	br->del(id);

	cout << "Deleted book" << endl;

	return true;
}

UICommandUser::UICommandUser(vector<string> vs) : Command(vs){
	name = "";
	surname = "";
	ur = new Repository<User>();
}

bool UICommandUser::read(){
	if (command.size() < 1) return false;
	long id = stol(command.at(0));

	User* user = ur->read(id);

	if (user == NULL) return false;

	cout << "User ID: " << user->id() << endl
		 << "Name:" << user->name() << endl
		 << "Surname:" << user->surname() << endl
		 << "Role:" << user->role()
		 << endl;

	return true;
}

bool UICommandUser::create(){
	if (command.size() < 3) return false;
	name = command.at(0);
	surname = command.at(1);
	role = stol(command.at(2));

	ur->create( new User(name, surname, role) );

	cout << "Created user" << endl;

	return true;
}

bool UICommandUser::update(){
	if (command.size() < 3) return false;

	long id = stol(command.at(0));
	name = command.at(1);
	surname = command.at(2);

	User* user = ur->read(id);

	user->name(name);
	user->surname(surname);

	ur->update(user);

	cout << "Changed user" << endl;

	return true;
}

bool UICommandUser::del(){
	if (command.size() < 1) return false;
	long id = stol(command.at(0));

	ur->del(id);

	cout << "Deleted user" << endl;

	return true;
}

UICommandRole::UICommandRole(vector<string> vs) : Command(vs){
	description = "";
	rr = new Repository<Role>();
}

bool UICommandRole::read(){
	if (command.size() < 1) return false;
	long id = stol(command.at(0));

	Role* role = rr->read(id);

	if (role == NULL) return false;

	cout << "Role ID: " << role->id() << endl
		 << "Description: " << role->description()
		 << endl;

	return true;
}

bool UICommandRole::create(){
	if (command.size() < 1) return false;
	description = command.at(0);

	rr->create( new Role(description) );

	cout << "Created role" << endl;

	return true;
}

bool UICommandRole::update(){
	if (command.size() < 2) return -1;
	long id = stol(command.at(0));
	description = command.at(1);

	Role* role = rr->read(id);

	role->description(description);

	rr->update(role);

	cout << "Role updated" << endl;

	return true;
}

bool UICommandRole::del(){
	if (command.size() < 1) return false;
	long id = stol(command.at(0));

	rr->del(id);

	cout << "Deleted role" << endl;

	return true;
}


UICommandRent::UICommandRent(std::vector<std::string> vs) : Command(vs){
	long user_id = -1;
	long book_id = -1;
	long timestamp = -1;
	ubr = new Repository<UserBook>();

}

bool UICommandRent::read(){
	if (command.size() < 1) return false;
	long id = stol(command.at(0));

	UserBook* userbook = ubr->read(id);

	if (userbook == NULL) return false;

	cout << "User ID: " << userbook->user_id() << endl
		 << "Book ID: " << userbook->book_id() << endl
		 << "Timestamp: " << userbook->timestamp()
		 << endl;

	return true;
}

bool UICommandRent::create(){
	if (command.size() < 3) return false;
	user_id = stol(command.at(0));
	book_id = stol(command.at(1));
	timestamp = stol(command.at(2));

	ubr->create( new UserBook(user_id, book_id, timestamp) );

	cout << "Created rent" << endl;

	return true;
}

bool UICommandRent::update(){
	if (command.size() < 4) return -1;
	long id = stol(command.at(0));
	user_id = stol(command.at(1));
	book_id = stol(command.at(2));
	timestamp = stol(command.at(3));

	UserBook* userbook = ubr->read(id);

	userbook->user_id(user_id);
	userbook->book_id(book_id);
	userbook->timestamp(timestamp);

	ubr->update(userbook);

	cout << "Rent updated" << endl;

	return true;
}

bool UICommandRent::del(){
	if (command.size() < 1) return false;
	long id = stol(command.at(0));

	ubr->del(id);

	cout << "Deleted rent" << endl;

	return true;
}


///////////////////////////////////////////
///////////CLI Implementation /////////////
///////////////////////////////////////////

CLI::CLI(){
	running = 1;
	delim = ' ';

	cout << R"(	Welcome to...)" << R"(
	 |     _)  |                              
	 |      |  __ \    __|  _` |   __|  |   | 
	 |      |  |   |  |    (   |  |     |   | 
	_____| _| _.__/  _|   \__,_| _|    \__, | 
	                                   ____/  v0.01)"
		 << R"(
		      by dodo-neko-soft inc.)" << endl;
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

	//cout << "command: " << command.at(1) << endl;

	if (command.size() < 2){
		if (command.front().compare("auth") == 0){
			//auth not implemented
			return true;
		} else if (command.front().compare("exit") == 0){
			running = false;
			return true;
		} else if (command.front().compare("quit") == 0){
			running = false;
			return true;
		} else {
			return false;
		}
	} else {

	com = command.at(0); // first element is the command
	cont = command.at(1); // second element is the context

	command.erase(command.begin(), command.begin()+2); // delete first and second element

	Command *b = Action::getCommand(cont, command); // returns a book, a role or a user object
	if (b == NULL) return false; 

	if (com.compare("create") == 0) {
		return b->create();
	}
	else if (com.compare("update") == 0) {
		return b->update();
	}
	else if (com.compare("read") == 0){
		return b->read();
	}
	else if (com.compare("delete") == 0) {
		return b->del();
	}
	else return false;
	}
}	

Command* Action::getCommand(string type, vector<string> vs){
	if (type.compare("book") == 0) return new UICommandBook(vs);
	else if (type.compare("role") == 0) return new UICommandRole(vs);
	else if (type.compare("user") == 0) return new UICommandUser(vs);
	else if (type.compare("rent") == 0) return new UICommandRent(vs);
	else return NULL;
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
		if(! parseCommand(s)) cout << "failed command!" << endl;
		//printCommand();
		s.clear(); //empty the command buffer
	}
}
