#include <string>
#include <iostream>
#include <time.h>

#include "AuthorizationService.hxx"
#include "Repository.hxx"
#include "sha256.hxx"


string AuthorizationService::createSession(long user_id_){
    Authorization* auth = au->create(new Authorization(user_id_, sha256(to_string(clock()))));
    cout<< "Session created"<<auth->id()<<endl;
    return auth->session_id();
}

long AuthorizationService::getSession(string session_id){

    vector<Authorization> sessions = au->read(odb::query<Authorization>::session_id == session_id);

    if(sessions.size() > 0){
        return sessions[0].user_id();
    }
    cerr << "Auth level exception" << endl;
    return 0;
}