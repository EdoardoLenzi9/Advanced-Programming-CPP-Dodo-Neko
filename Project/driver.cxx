#include <Router.hxx>
#include <RoomController.hxx>
#include <AuthMiddleware.hxx>


//TODO this is the program entry point, I use this in order to set-up the end points
// and start the Router
// * the static files are exposed here: http://localhost:8080
// * the endpoint is here: http://localhost:8080/info


int main(){

    vector<Route> routes;

    Route r("^/info$", "GET", RoomController::info);
    Route a("^/test$", "POST", RoomController::authTest, { AuthMiddleware::handle });
    Route rb("^/room/get$", "POST", RoomController::get);

    routes.push_back(r);
    routes.push_back(a);
    routes.push_back(rb);

    Router router(routes);
    router.start();
}