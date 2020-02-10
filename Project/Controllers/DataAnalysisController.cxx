#include "DataAnalysisController.hxx"

void DataAnalysisController::averageDays(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, json content){
    DataAnalysisService service;
	
	json res;
	res["status"]["code"] = Code::Ok;
	res["status"]["description"] = OK;
	res["data"]["avgdays"] = service.averageDays();
	*response << serialize(res);
}

void DataAnalysisController::averagePrice(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, json content){
    DataAnalysisService service;
	
	json res;
	res["status"]["code"] = Code::Ok;
	res["status"]["description"] = OK;
	res["data"]["avgprice"] = service.averagePrice();
	*response << serialize(res);
}

void DataAnalysisController::mostValuableRooms(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, json content){
    DataAnalysisService service;
	
	json res = serialize(service.mostValuableRooms());
	res["status"]["code"] = Code::Ok;
	res["status"]["description"] = OK;
	*response << serialize(res);
}

void DataAnalysisController::mostValuableCustomers(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, json content){
    DataAnalysisService service;
	
	json res = serialize(service.mostValuableCustomers());
	res["status"]["code"] = Code::Ok;
	res["status"]["description"] = OK;
	*response << serialize(res);
}

void DataAnalysisController::mostValuableFeatures(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, json content){
    DataAnalysisService service;
	
	json res = serialize(service.mostValuableFeatures());
	res["status"]["code"] = Code::Ok;
	res["status"]["description"] = OK;
	*response << serialize(res);
}