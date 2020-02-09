/**
    @author Edoardo Lenzi
    @author Patrick Tschuchnig
    
    @version 1.0 01/11/19 
    @license WTFPL v2  
**/


#ifndef USER_SERVICE_HPP
#define USER_SERVICE_HPP

#include <iostream>
#include <string>
#include <vector>

#include "AuthorizationService.hxx"
#include "Repository.hxx"
#include "UserDto.hxx"


class UserService { 
    
    public:
        UserService(){
            ur = new Repository<User>();
            as = new AuthorizationService();
        }

        long getRole(long id);
        long create(string firstname, string lastname, string email,
                    string password, string address, long birthdate, long role);
        string loginUser(string email, string password);
        void del(long id);
        void update(long issuerId, long issuerRole, long id, string firstname, string lastname, 
                    string email, string password, string address, long birthdate, long role);
        UserDto get(long id);
        vector<UserDto> list();

    private:
        Repository<User>* ur;
        AuthorizationService* as;

};


#endif