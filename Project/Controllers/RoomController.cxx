#include "RoomController.hxx"

void RoomController::get(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, json content)
{
	json res;
	res["status"]["code"] = 501;
	res["status"]["description"] = "Not Implemented";
	res["data"] = "";
	response->write(SimpleWeb::StatusCode::server_error_not_implemented, res.dump());
}

void RoomController::list(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, json content)
{
	RoomService service;
	
	long startdate = content["data"]["startdate"].get<long>();
	long enddate = content["data"]["enddate"].get<long>();

	vector<RoomDto> rooms = service.getAvailableRooms(startdate, enddate);
	
	json res = serialize(rooms);
	res["status"]["code"] = Code::Ok;
	res["status"]["description"] = OK;

	*response << serialize(res);

}