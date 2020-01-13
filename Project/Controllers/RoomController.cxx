#include "RoomController.hxx"

#include "Services/RoomService.hxx"


// TODO simple example of an handler, here u can define how many handlers u need 
// and pass them in driver.cxx to the Router in order to set-up the routes
// if u want to test this handler go to http://localhost:8080/info

void RoomController::info(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, string content) {
        stringstream stream;
        stream << "<h1>Request from " << request->remote_endpoint_address() << ":" << request->remote_endpoint_port() << "</h1>";

        stream << request->method << " " << request->path << " HTTP/" << request->http_version;

        stream << "<h2>Query Fields</h2>";
        auto query_fields = request->parse_query_string();
        for(auto &field : query_fields)
        stream << field.first << ": " << field.second << "<br>";

        stream << "<h2>Header Fields</h2>";
        for(auto &field : request->header)
        stream << field.first << ": " << field.second << "<br>";

        response->write(stream);
}

void RoomController::authTest(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, string content) {
        string json_test = "{\"status\": {\"code\": \"200\",\"description\": \"Ok\"},\"data\": {\"Room\": {\"id\": 1,\"beds\" : 2,\"tlx\" : 10,\"tly\" : 20,\"brx\" : 50,\"bry\" : 60}}}";
        response->write(SimpleWeb::StatusCode::success_ok, json_test);
}

void RoomController::test(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, string content) {
        RoomService service;

        std::stringstream sContent;
        sContent << content;

        ptree pt;
        read_json(sContent, pt);
        int roomId = pt.get<int>("data.roomID");        
        
        cout << roomId << endl;

        //service.list();
        /*Room* room = service.get(roomId);
        string json = "{\"status\": {\"code\": \"200\",\"description\": \"Ok\"},\"data\": {";
        json.append("\"roomID\": ");
        json.append(to_string(room->id()));
        json.append(",\"beds\" : ");
        json.append(to_string(room->beds()));
        json.append(",\"tlx\" : ");
        json.append(to_string(room->tlx()));
        json.append(",\"tly\" : ");
        json.append(to_string(room->tly()));
        json.append(",\"brx\" : ");
        json.append(to_string(room->brx()));
        json.append(",\"bry\" : ");
        json.append(to_string(room->bry()));
        json.append("}}");
        response->write(SimpleWeb::StatusCode::success_ok, json);*/

        response->write(SimpleWeb::StatusCode::success_ok, "OK");
        
}