#include "BookController.hxx"

void BookController::create(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, json content){
    RoomService service;
	AuthorizationService authService;
	
	long roomid = content["data"]["roomid"].get<long>();
	long arrival = content["data"]["arrival"].get<long>();
	long departure = content["data"]["departure"].get<long>();
	long userid = authService.getSession(content["auth"]["sid"].get<string>());   

	service.bookRoom(userid, roomid, arrival, departure);

	json res;
	res["status"]["code"] = Code::Ok;
	res["status"]["description"] = OK;
	res["data"] = "";
	*response << serialize(res);
}

void BookController::get(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, json content){
    json res;
	res["status"]["code"] = 501;
	res["status"]["description"] = "Not Implemented";
	res["data"] = "";
	response->write(SimpleWeb::StatusCode::server_error_not_implemented, res.dump());
}

void BookController::list(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, json content){
    json res;
	res["status"]["code"] = 501;
	res["status"]["description"] = "Not Implemented";
	res["data"] = "";
	response->write(SimpleWeb::StatusCode::server_error_not_implemented, res.dump());
}

void BookController::update(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, json content){
    json res;
	res["status"]["code"] = 501;
	res["status"]["description"] = "Not Implemented";
	res["data"] = "";
	response->write(SimpleWeb::StatusCode::server_error_not_implemented, res.dump());
}

void BookController::del(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, json content){
    json res;
	res["status"]["code"] = 501;
	res["status"]["description"] = "Not Implemented";
	res["data"] = "";
	response->write(SimpleWeb::StatusCode::server_error_not_implemented, res.dump());
}

void BookController::check(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, json content){
    json res;
	res["status"]["code"] = 501;
	res["status"]["description"] = "Not Implemented";
	res["data"] = "";
	response->write(SimpleWeb::StatusCode::server_error_not_implemented, res.dump());
}
