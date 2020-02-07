#include "Route.hxx"
#include <DtoException.hxx>

void Route::handle(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, Route obj) {
    Env* env = new Env();
    
    try {
        string content = request->content.string(); 
        json j = json::parse(content);

        if(env->getDebugMode()){
            cout << "REQUEST:" << content << endl << endl;
        }

        for(function<bool(shared_ptr<HttpServer::Response>, shared_ptr<HttpServer::Request>, json)> middleware : obj.middlewares) {
            if(!middleware(response, request, j))
                return;
        }

        obj.handler(response, request, j);
        
    } catch (DtoException dtoe) {
        json res;
        res["status"]["code"] = dtoe.getCode();
        res["status"]["description"] = dtoe.getDescription();
        res["data"] = "";
        string statusCode = to_string(dtoe.getCode());
        string statusCodeLabel = CodeLabels[statusCode];
        string dump = res.dump();
        *response << "HTTP/1.1 " + statusCode + " " + statusCodeLabel +"\r\n" + "Content-Length: " + to_string(dump.length()) + "\r\n" + "Content-Type: application/json\r\n\r\n" + dump;
    } catch (exception e) {
        json res;
        res["status"]["code"] = 501;
        res["status"]["description"] = e.what();
        res["data"] = "";
        response->write(res.dump());
    }

}