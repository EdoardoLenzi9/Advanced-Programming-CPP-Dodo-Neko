#include "UserController.hxx"
#include "Const.hxx"

#include <UserService.hxx>
#include <AuthorizationService.hxx>
#include <DtoException.hxx>

void UserController::create(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, json content){

	UserService service;

	long id = service.create(content["data"]["firstName"].get<string>(), 
		content["data"]["lastName"].get<string>(),
		content["data"]["email"].get<string>(),
		content["data"]["password"].get<string>(),
		content["data"]["address"].get<string>(),
		content["data"]["birthdate"].get<long>(),
		1);

	if(id > 0){
		json res;
		res["status"]["code"] = 200;
		res["status"]["description"] = "OK";
		res["data"] = "";
		response->write(SimpleWeb::StatusCode::success_ok, res.dump());
	} else {
		json res;
		res["status"]["code"] = 400;
		res["status"]["description"] = "Bad Request";
		res["data"] = "";
		response->write(SimpleWeb::StatusCode::client_error_bad_request, res.dump());
	}

}

void UserController::get(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, json content){
	json res;
	res["status"]["code"] = Code::InternalServerError;
	res["status"]["description"] = NOT_IMPLEMENTED;
	res["data"] = "";
	*response << serialize(res);
}

void UserController::update(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, json content){
    json res;
	res["status"]["code"] = Code::InternalServerError;
	res["status"]["description"] = NOT_IMPLEMENTED;
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
