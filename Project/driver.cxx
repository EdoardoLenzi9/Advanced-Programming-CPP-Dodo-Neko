#include <Router.hxx>

#include <AuthMiddleware.hxx>

#include <RoomController.hxx>
#include <HotelController.hxx>
#include <UserController.hxx>
#include <BookController.hxx>

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

    Route hotelGet("^/hotel$", "GET", HotelController::get);

    Route userGet("^/user$", "POST", UserController::get, { AuthMiddleware::user }); //Maybe change to HTTP GET
    Route userRegister("^/user/register$", "POST", UserController::create);
    Route userUpdate("^/user/update$", "POST", UserController::update);
    Route userLogout("^/user/logout$", "POST", UserController::logout);
    Route userLogin("^/user/auth$", "POST", UserController::login);

    Route roomGet("^/room/([0-9]+)$", "GET", RoomController::get);
    Route roomList("^/room/list$", "GET", RoomController::list);
    Route roomUpdate("^/room/update$", "POST", RoomController::update);

    Route bookCheck("^/book/check$", "POST", BookController::check);
    Route bookCreate("^/book/create$", "POST", BookController::create);
    Route bookList("^/book/list$", "POST", BookController::list);
    Route bookUpdate("^/book/update$", "POST", BookController::update);
    Route bookDelete("^/book/delete$", "POST", BookController::del);

    routes.push_back(hotelGet);

    routes.push_back(userGet);
    routes.push_back(userRegister);
    routes.push_back(userUpdate);
    routes.push_back(userLogout);
    routes.push_back(userLogin);

    routes.push_back(roomGet);
    routes.push_back(roomList);
    routes.push_back(roomUpdate);

    routes.push_back(bookCheck);
    routes.push_back(bookCreate);
    routes.push_back(bookList);
    routes.push_back(bookUpdate);
    routes.push_back(bookDelete);

    Router router(routes);
    router.start();
}