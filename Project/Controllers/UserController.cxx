#include "UserController.hxx"
#include "Const.hxx"

#include <UserService.hxx>
#include <AuthorizationService.hxx>
#include <DtoException.hxx>

void UserController::create(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, json content){

	try{
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

	} catch (DtoException e) {
		json res;
		res["status"]["code"] = e.getCode();
		res["status"]["description"] = e.getDescription();
		res["data"] = "";
		response->write(SimpleWeb::StatusCode::server_error_internal_server_error, res.dump());
	}


}

void UserController::get(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, json content){
    json res;
	res["status"]["code"] = 501;
	res["status"]["description"] = "Not Implemented";
	res["data"] = "";
	response->write(SimpleWeb::StatusCode::server_error_not_implemented, res.dump());
}

void UserController::update(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, json content){
    json res;
	res["status"]["code"] = 501;
	res["status"]["description"] = "Not Implemented";
	res["data"] = "";
	response->write(SimpleWeb::StatusCode::server_error_not_implemented, res.dump());
}

void UserController::del(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, json content){
    json res;
	res["status"]["code"] = 501;
	res["status"]["description"] = "Not Implemented";
	res["data"] = "";
	response->write(SimpleWeb::StatusCode::server_error_not_implemented, res.dump());
}


void UserController::login(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, json content){
	try{
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
		  
	} catch (DtoException e) {
		json res;
		res["status"]["code"] = e.getCode();
		res["status"]["description"] = e.getDescription();
		res["data"] = "";
		response->write(SimpleWeb::StatusCode::server_error_internal_server_error, res.dump());
	} 
	/*catch {

	}*/
}

void UserController::logout(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, json content){
    json res;
	res["status"]["code"] = 501;
	res["status"]["description"] = "Not Implemented";
	res["data"] = "";
	response->write(SimpleWeb::StatusCode::server_error_not_implemented, res.dump());
}
