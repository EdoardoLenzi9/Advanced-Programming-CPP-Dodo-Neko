#include <Router.hxx>
#include <RoomController.hxx>
#include <HotelController.hxx>
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

    Route hotel("^/hotel$", "GET", HotelController::get);
    routes.push_back(hotel);


    //Route roomList("^/room/list$", "GET", RoomController::list);
    //routes.push_back(roomList);


    

    Router router(routes);
    router.start();
}