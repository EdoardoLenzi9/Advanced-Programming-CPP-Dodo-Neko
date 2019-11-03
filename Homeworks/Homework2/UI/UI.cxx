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

	Book* book = br->create( new Book(copies, rentedCopies, title, author, publisher) );


	cout << "Created book with id: " << book->id() << endl;

	return true;
}
bool UICommandBook::update(){
	if (command.size() < 6) return false;

	long id = stol(command.at(0));
	copies = stoi(command.at(1));
	rentedCopies = stoi(command.at(2)); //updating this can potentially cause inconsistencies, prohibiting setting this would be an option
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

	Book* book = br->read(id);

	if (book->rented() > 0){
		cout << "Deleting refused, book is still rent out." << endl;
		return true;
	}

	br->del(id);

	cout << "Deleted book" << endl;

	return true;
}

UICommandUser::UICommandUser(vector<string> vs) : Command(vs){
	name = "";
	surname = "";
	ur = new Repository<User>();
	br = new Repository<Book>();
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

	User* user = ur->create( new User(name, surname, role) );

	cout << "Created user with id: " << user->id() << endl;

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

	Role* role = rr->create( new Role(description) );

	cout << "Created role with id: " << role->id() << endl;

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
	br = new Repository<Book>();

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

	Book* book = br->read(book_id);
	int availableCopies = (book->copies()-book->rented());
	cout << "copies avail:" << availableCopies << endl; 
	if (availableCopies > 0){ 
		book->rented(book->rented()+1); // increase the amount of rented copies when at least 1 is available
		
		br->update(book);
		
		UserBook* rent = ubr->create( new UserBook(user_id, book_id, timestamp) );
		cout << "Created rent with id: " << rent->id() << endl;
	} else {
		cout << "Renting refused, no copies available" << endl;
	}

	return true;
}

bool UICommandRent::update(){
	if (command.size() < 4) return false;
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

	UserBook* userbook = ubr->read(id);

	Book* book = br->read(userbook->book_id());

	int availableCopies = (book->copies()-book->rented());
	book->rented(book->rented()-1); // decrease the amount of rented copies
	
	br->update(book);

	ubr->del(id);

	cout << "Returned rent" << endl;

	return true;
}

Command* Action::getCommand(string type, vector<string> vs){
	if 	    (type.compare("book") == 0) return new UICommandBook(vs);
	else if (type.compare("role") == 0) return new UICommandRole(vs);
	else if (type.compare("user") == 0) return new UICommandUser(vs);
	else if (type.compare("rent") == 0) return new UICommandRent(vs);
	else return NULL;
}


///////////////////////////////////////////
///////////CLI Implementation /////////////
///////////////////////////////////////////

CLI::CLI(){
	running = 1;
	delim = ' ';
	/*
	cout << R"(	Welcome to...)" << R"(
	 |     _)  |                              
	 |      |  __ \    __|  _` |   __|  |   | 
	 |      |  |   |  |    (   |  |     |   | 
	_____| _| _.__/  _|   \__,_| _|    \__, | 
	                                   ____/  v0.01)"
		 << R"(
		      by dodo-neko-soft inc.)" << endl;
	*/

	cout << R"(Welcome to...

[38;5;83m [0m[38;5;83m|[0m[38;5;83m [0m[38;5;83m [0m[38;5;83m [0m[38;5;119m [0m[38;5;118m [0m[38;5;118m_[0m[38;5;118m)[0m[38;5;118m [0m[38;5;118m [0m[38;5;118m|[0m[38;5;118m [0m[38;5;118m [0m[38;5;118m [0m[38;5;154m [0m[38;5;154m [0m[38;5;154m [0m[38;5;154m [0m[38;5;154m [0m[38;5;154m [0m[38;5;154m [0m[38;5;154m [0m[38;5;154m [0m[38;5;148m [0m[38;5;184m [0m[38;5;184m [0m[38;5;184m [0m[38;5;184m [0m[38;5;184m [0m[38;5;184m [0m[38;5;184m [0m[38;5;184m [0m[38;5;184m [0m[38;5;184m [0m[38;5;184m [0m[38;5;178m [0m[38;5;214m [0m[38;5;214m [0m[38;5;214m [0m[38;5;214m [0m[38;5;214m [0m
[38;5;83m [0m[38;5;83m|[0m[38;5;119m [0m[38;5;118m [0m[38;5;118m [0m[38;5;118m [0m[38;5;118m [0m[38;5;118m [0m[38;5;118m|[0m[38;5;118m [0m[38;5;118m [0m[38;5;118m_[0m[38;5;154m_[0m[38;5;154m [0m[38;5;154m\[0m[38;5;154m [0m[38;5;154m [0m[38;5;154m [0m[38;5;154m [0m[38;5;154m_[0m[38;5;154m_[0m[38;5;148m|[0m[38;5;184m [0m[38;5;184m [0m[38;5;184m_[0m[38;5;184m`[0m[38;5;184m [0m[38;5;184m|[0m[38;5;184m [0m[38;5;184m [0m[38;5;184m [0m[38;5;184m_[0m[38;5;184m_[0m[38;5;178m|[0m[38;5;214m [0m[38;5;214m [0m[38;5;214m|[0m[38;5;214m [0m[38;5;214m [0m[38;5;214m [0m[38;5;214m|[0m[38;5;214m [0m
[38;5;118m [0m[38;5;118m|[0m[38;5;118m [0m[38;5;118m [0m[38;5;118m [0m[38;5;118m [0m[38;5;118m [0m[38;5;118m [0m[38;5;118m|[0m[38;5;154m [0m[38;5;154m [0m[38;5;154m|[0m[38;5;154m [0m[38;5;154m [0m[38;5;154m [0m[38;5;154m|[0m[38;5;154m [0m[38;5;154m [0m[38;5;148m|[0m[38;5;184m [0m[38;5;184m [0m[38;5;184m [0m[38;5;184m [0m[38;5;184m([0m[38;5;184m [0m[38;5;184m [0m[38;5;184m [0m[38;5;184m|[0m[38;5;184m [0m[38;5;184m [0m[38;5;178m|[0m[38;5;214m [0m[38;5;214m [0m[38;5;214m [0m[38;5;214m [0m[38;5;214m [0m[38;5;214m|[0m[38;5;214m [0m[38;5;214m [0m[38;5;214m [0m[38;5;208m|[0m[38;5;208m [0m
[38;5;118m_[0m[38;5;118m_[0m[38;5;118m_[0m[38;5;118m_[0m[38;5;118m_[0m[38;5;118m|[0m[38;5;154m [0m[38;5;154m_[0m[38;5;154m|[0m[38;5;154m [0m[38;5;154m_[0m[38;5;154m.[0m[38;5;154m_[0m[38;5;154m_[0m[38;5;154m/[0m[38;5;148m [0m[38;5;184m [0m[38;5;184m_[0m[38;5;184m|[0m[38;5;184m [0m[38;5;184m [0m[38;5;184m [0m[38;5;184m\[0m[38;5;184m_[0m[38;5;184m_[0m[38;5;184m,[0m[38;5;184m_[0m[38;5;178m|[0m[38;5;214m [0m[38;5;214m_[0m[38;5;214m|[0m[38;5;214m [0m[38;5;214m [0m[38;5;214m [0m[38;5;214m [0m[38;5;214m\[0m[38;5;214m_[0m[38;5;208m_[0m[38;5;208m,[0m[38;5;208m [0m[38;5;208m|[0m[38;5;208m [0m
[38;5;118m [0m[38;5;118m [0m[38;5;118m [0m[38;5;154m [0m[38;5;154m [0m[38;5;154m [0m[38;5;154m [0m[38;5;154m [0m[38;5;154m [0m[38;5;154m [0m[38;5;154m [0m[38;5;154m [0m[38;5;148m [0m[38;5;184m [0m[38;5;184m [0m[38;5;184m [0m[38;5;184m [0m[38;5;184m [0m[38;5;184m [0m[38;5;184m [0m[38;5;184m [0m[38;5;184m [0m[38;5;184m [0m[38;5;184m [0m[38;5;178m [0m[38;5;214m [0m[38;5;214m [0m[38;5;214m [0m[38;5;214m [0m[38;5;214m [0m[38;5;214m [0m[38;5;214m [0m[38;5;214m [0m[38;5;214m [0m[38;5;208m [0m[38;5;208m_[0m[38;5;208m_[0m[38;5;208m_[0m[38;5;208m_[0m[38;5;208m/[0m[38;5;208m [0m[38;5;208m [0m v0.01
	by dodo-neko-soft inc.)" << endl;
}

string CLI::getCommand(){
	string s;
	if(getline(cin, s)){
		return s;
	} else {
		running = false;
		return "ending";
	}
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
		} else if (command.front().compare("help") == 0){
			cout << R"(
Command help: 		(dont use spaces inside parameters, 
Book commands:		 every id is a number, timestamp is a number)
	create book copies rented_copies title author publisher
	update book bookid copies rented_copies title author publisher
	read book bookid
	delete book bookid
User commands: 
	create user name surname roleid
	update user userid name surname roleid
	read user userid
	delete user userid	
Role commands: 
	create role description
	update role roleid description
	read role roleid
	delete role roleid
Rent commands: 
	create rent userid bookid timestamp
	update rent id userid bookid timestamp
	read rent rentid 
	delete rent rentid
)" << endl;
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
		try {
			if(! parseCommand(s)) cout << "failed command!" << endl;
		} catch (odb::object_not_persistent	e){
			cout << "ERROR: tried accessing missing object, continuing" << endl;
		}
		s.clear(); //empty the command buffer
	}
}
