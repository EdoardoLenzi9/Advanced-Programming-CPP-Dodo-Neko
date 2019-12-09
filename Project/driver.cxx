#include <Router.hxx>
#include <RoomController.hxx>
#include <LoginController.hxx>


//TODO this is the program entry point, I use this in order to set-up the end points
// and start the Router
// * the static files are exposed here: http://localhost:8080
// * the endpoint is here: http://localhost:8080/info


int main(){

    vector<Route> routes;

    Route r1("^/info$", "GET", handler);
    Route r2("^/login$", "POST", login);

    routes.push_back(r1);
    routes.push_back(r2);

    Router router(routes);
    router.start();
}