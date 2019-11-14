#include <Router.hxx>
#include <RoomController.hxx>


int main(){

    vector<Route> routes;

    Route r("^/info$", "GET", handler);

    routes.push_back(r);

    Router router(routes);
    router.start();
}