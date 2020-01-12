#include <string>
#include <iostream>
#include "AuthorizationService.hxx"
#include "Repository.hxx"


long AuthorizationService::getToken(long id){
    return au->read(id)->session_id();
}


long AuthorizationService::createSession(long user_id_, long session_id_){
    Authorization* auth = au->create(new Authorization(user_id_, session_id_));
    cout<< "Session created"<<auth->id()<<endl;
    return auth->id();
}

long AuthorizationService::getUserID(long id){
    return au->read(id)->user_id();
}
long AuthorizationService::getSession(long session_id){
    if(getToken(session_id)!=0){
        return getUserID(session_id);
    }
    cerr << "Auth level exception" << endl;
    return 0;
}


