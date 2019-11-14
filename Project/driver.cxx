#include <Router.hxx>
#include <RoomController.hxx>


//TODO this is the program entry point, I use this in order to set-up the end points
// and start the Router
// * the static files are exposed here: http://localhost:8080
// * the endpoint is here: http://localhost:8080/info


int main(){

    vector<Route> routes;

    Route r("^/info$", "GET", handler);

    routes.push_back(r);

    Router router(routes);
    router.start();
}