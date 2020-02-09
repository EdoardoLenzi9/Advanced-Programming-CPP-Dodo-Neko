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


UserDto UserService::get(long id){
    User * user = ur->read(id);
    return UserDto(user->firstname(), user->lastname(), user->email(), 
                   user->birthdate(), user->address(), user->id(), user->role());
}

vector<UserDto> UserService::list(){
    vector<User> users = ur -> read();
    vector<UserDto> result;

    for(User u: users){
        result.push_back(UserDto(u.firstname(), u.lastname(), u.email(), 
                                 u.birthdate(), u.address(), u.id(), u.role()));
    }

    return result;
}


long UserService::create(string firstname, string lastname, string email,
                    	 string password, string address, long birthdate, long role){
    
    if(role > 1){
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


void UserService::update(long issuerId, long issuerRole, long id, string firstname, string lastname, string email,
                    	 string password, string address, long birthdate, long role){

    if(issuerRole == 1 && (issuerRole != role || issuerId != id)){
        throw DtoException(Code::Unauthorized, UNAUTHORIZED);
    }

    User* user = ur->read(id);

    user->firstname(firstname != "" ? firstname : user->firstname());
    user->lastname(lastname != "" ? lastname : user->lastname());
    user->email(email != "" ? email : user->email());
    user->password(password != "" ? sha256(password) : user->password());
    user->address(address != "" ? address : user->address());
    user->birthdate(birthdate > 0 ? birthdate : user->birthdate());
    user->role(role > 0 ? role : user->role());

    ur->update(user);
}