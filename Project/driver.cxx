#include <Router.hxx>
#include <RoomController.hxx>
#include <AuthMiddleware.hxx>

#include "InitData.hxx"
#include "Env.hxx"


//TODO this is the program entry point, I use this in order to set-up the end points
// and start the Router
// * the static files are exposed here: http://localhost:8080
// * the endpoint is here: http://localhost:8080/info


int main(){
    Env * env = new Env();
    if(env->getInitData()){
        InitData();
    }

    vector<Route> routes;

    Route r("^/info$", "GET", RoomController::info);
    Route rb("^/test$", "POST", RoomController::test);
    Route a("^/auth/test$", "POST", RoomController::authTest, { AuthMiddleware::handle });
    Route hotel("^/hotel$", "GET", RoomController::hotel);
    Route room("^/room/([0-9]+)$", "GET", RoomController::room);

    routes.push_back(rb);
    routes.push_back(r);
    routes.push_back(a);
    routes.push_back(hotel);
    routes.push_back(room);

    Router router(routes);
    router.start();
}