#include "AuthorizationService.hxx"


string AuthorizationService::createSession(long user_id_){
    long currentTime = time(0);
    long expirationTime = currentTime + env->getSessionTime();
    Authorization* auth = au->create(new Authorization(user_id_, 
                                                       sha256(to_string(currentTime)),
                                                       expirationTime));
    return auth->session_id();
}


long AuthorizationService::getSession(string session_id){

    vector<Authorization> sessions = au->read(odb::query<Authorization>::session_id == session_id);
    long currentTime = time(0);
    
    if(sessions.size() > 0){
        if(currentTime < sessions[0].expiration_time()){
            return sessions[0].user_id();
        }
    }
    
    throw DtoException(Code::Unauthorized, UNAUTHORIZED);
}


void AuthorizationService::deleteSession(string session_id){

    vector<Authorization> sessions = au->read(odb::query<Authorization>::session_id == session_id);

    for(Authorization session : sessions){
        au->archive(session.id());
    }
}