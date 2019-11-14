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


long UserService::getRole(long id){
    return ur->read(id)->role();
}


long UserService::create(long auth, string name, string surname, long role){
    if( getRole(auth) == 2 ){
        User* tmp = ur->create(new User(name, surname, role));
        cout << "User created" << tmp->id() << endl;
        return tmp->id();
    } 
    cerr << "Auth level exception" << endl;
    return 0;
}