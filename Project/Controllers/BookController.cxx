#include "BookController.hxx"

void BookController::create(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, json content){
    json res;
	res["status"]["code"] = 501;
	res["status"]["description"] = "Not Implemented";
	res["data"] = "";
	response->write(SimpleWeb::StatusCode::server_error_not_implemented, res.dump());
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
