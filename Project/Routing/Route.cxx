#include "Route.hxx"
#include <DtoException.hxx>

void Route::handle(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, Route obj) {
    Env* env = new Env();
    
    try {
        json j;
        string content = request->content.string(); 

        if(obj.httpMethod != "GET"){
            j = json::parse(content);
        }

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
        *response << BaseController::serialize(res);
    } catch (std::exception e) {
        json res;
        res["status"]["code"] = Code::InternalServerError;
        res["status"]["description"] = e.what();
        res["data"] = "";
        *response << BaseController::serialize(res);
    }
}