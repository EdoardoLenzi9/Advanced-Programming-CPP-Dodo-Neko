#include "UserController.hxx"


void UserController::create(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, json content){

	UserService service;

	long id = service.create( content["data"]["firstname"].get<string>(), 
							  content["data"]["lastname"].get<string>(),
							  content["data"]["email"].get<string>(),
							  content["data"]["password"].get<string>(),
							  content["data"]["address"].get<string>(),
							  content["data"]["birthdate"].get<long>(), 
							  1 );

	json res;
	res["status"]["code"] = Code::Ok;
	res["status"]["description"] = OK;
	res["data"] = "";
	*response << serialize(res);
}


void UserController::get(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, json content){
	AuthorizationService authService;
	UserService userService;

	long userId = authService.getSession(content["auth"]["sid"].get<string>());    
	UserDto user = userService.get(userId);

	json res = serialize(user);

	res["status"]["code"] = Code::Ok;
	res["status"]["description"] = OK;

	*response << serialize(res);
}


void UserController::update(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, json content){
	AuthorizationService authService;
	UserService service;

	long issuerid = authService.getSession(content["auth"]["sid"].get<string>());
	long issuerRole = service.getRole(issuerid);

	long userid = content["data"]["userid"].get<long>();
	long roleid = content["data"]["roleid"].get<long>();
	long birthdate = content["data"]["birthdate"].get<long>(); 

	string firstname = content["data"]["firstname"].get<string>();
	string lastname = content["data"]["lastname"].get<string>();
	string email = content["data"]["email"].get<string>();
	string address = content["data"]["address"].get<string>();
	string password = content["data"]["password"].get<string>();

	service.update(issuerid, issuerRole, userid, firstname, lastname, email, password, address, birthdate, roleid);

	json res;
	res["status"]["code"] = Code::Ok;
	res["status"]["description"] = OK;
	res["data"] = "";

	*response << serialize(res);
}


void UserController::del(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, json content){
    json res;
	res["status"]["code"] = Code::InternalServerError;
	res["status"]["description"] = NOT_IMPLEMENTED;
	res["data"] = "";
	*response << serialize(res);
}


void UserController::login(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, json content){
	UserService service;
	AuthorizationService authService;
	json res;

	string email = content["data"]["email"].get<string>();
	string password = content["data"]["password"].get<string>();

	string session = service.loginUser(email, password);
	
	res["status"]["code"] = Code::Ok;
	res["status"]["description"] = Ok;
	res["data"]["sid"] = session;
	*response << serialize(res);
}


void UserController::logout(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, json content){
	AuthorizationService service;
	
	string sid = content["auth"]["sid"].get<string>();
	service.deleteSession(sid);

	json res;
	res["status"]["code"] = Code::Ok;
	res["status"]["description"] = Ok;
	*response << serialize(res);
}


void UserController::list(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, json content)
{
	UserService service;
	vector<UserDto> users = service.list();
	
	json res = serialize(users);
	res["status"]["code"] = Code::Ok;
	res["status"]["description"] = OK;

	*response << serialize(res);
}