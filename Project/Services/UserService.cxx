/**
    @author Edoardo Lenzi
    @author Patrick Tschuchnig
    
    @version 1.0 01/11/19 
    @license WTFPL v2  
**/

#include <string>
#include <iostream>
#include "UserService.hxx"
#include "Repository.hxx"
#include "DtoException.hxx"
#include "Const.hxx"
#include "sha256.hxx"


long UserService::getRole(long id){
    return ur->read(id)->role();
}


long UserService::create(string firstname, string lastname, string email,
                    	 string password, string address, long birthdate, long role){
    
    if(role > 1){
        // a normal user cannot create an admin profile!
        throw DtoException(Code::Unauthorized, UNAUTHORIZED);
    }

    User* user = ur->create(new User(firstname, lastname, email, sha256(password), address, birthdate, role));
    return user->id();
}


string UserService::loginUser(string email, string password){

    vector<User> users = ur->read(odb::query<User>::email == email);
    if(users.size() > 0){
        string pw1 = users[0].password();
        string pw2 = sha256(password);
		if(pw1.compare(pw2) == 0) {    
            return as->createSession(users[0].id());
		}
    }

    throw DtoException(Code::Unauthorized, WRONG_PASSWORD);
}


void UserService::del(long id_user){
    ur->archive(id_user);
    cout<<"User is deleted!"<<endl;
}


void UserService::update(long id, string firstname, string lastname, string email,
                    	 string password, string address, long birthdate, long role){
    User * user = new User(id, firstname, lastname, email, password, address, birthdate, role);
    ur->update(user);
}