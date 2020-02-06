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


long UserService::getRole(long id){
    return ur->read(id)->role();
}


long UserService::create(string firstname, string lastname, string email,
                    	 string password, string address, long birthdate, long role){
    
    if(role > 1){
        // a normal user cannot create an admin profile!
        throw DtoException(Code::Unauthorized, UNAUTHORIZED);
    }

    User* user = ur->create(new User(firstname, lastname, email, password, address, birthdate, role));
    return user->id();
}


string UserService::getPassword(string email){
    vector<User> users = ur->read(odb::query<User>::email == email);
    if(users.size() > 0){
        return users[0].password();
    }
    throw DtoException(Code::WrongPassword, WRONG_PASSWORD);
}