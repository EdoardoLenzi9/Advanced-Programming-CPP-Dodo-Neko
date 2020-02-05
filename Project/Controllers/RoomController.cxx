#include "RoomController.hxx"

#include "Services/RoomService.hxx"

void RoomController::create(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, json content)
{
	json res;
	res["status"]["code"] = 501;
	res["status"]["description"] = "Not Implemented";
	res["data"] = "";
	response->write(SimpleWeb::StatusCode::server_error_not_implemented, res.dump());
}

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
	json res;
	res["status"]["code"] = 501;
	res["status"]["description"] = "Not Implemented";
	res["data"] = "";
	response->write(SimpleWeb::StatusCode::server_error_not_implemented, res.dump());

	/*RoomService service;
        vector<Room> rooms = service.getList();

        json res;
        res["status"]["code"] = 200;
        res["status"]["description"] = "OK";

        int index = 0;

        for(Room r : rooms) {
                 res["data"]["rooms"][index]["roomID"] = r.id();
                 res["data"]["rooms"][index]["coordinates"]["tlx"] = r.tlx();
                 res["data"]["rooms"][index]["coordinates"]["tly"] = r.tly();
                 res["data"]["rooms"][index]["coordinates"]["brx"] = r.brx();
                 res["data"]["rooms"][index]["coordinates"]["bry"] = r.bry();      
        }

        response->write(res.dump());*/
}

void RoomController::update(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, json content)
{
	json res;
	res["status"]["code"] = 501;
	res["status"]["description"] = "Not Implemented";
	res["data"] = "";
	response->write(SimpleWeb::StatusCode::server_error_not_implemented, res.dump());
}

void RoomController::del(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, json content)
{
	json res;
	res["status"]["code"] = 501;
	res["status"]["description"] = "Not Implemented";
	res["data"] = "";
	response->write(SimpleWeb::StatusCode::server_error_not_implemented, res.dump());
}
