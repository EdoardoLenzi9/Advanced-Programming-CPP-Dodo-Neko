#include <Router.hxx>

#include <AuthMiddleware.hxx>

#include <RoomController.hxx>
#include <HotelController.hxx>
#include <UserController.hxx>
#include <BookController.hxx>
#include <Console.hxx>
#include <DataAnalysisController.hxx>

#include "InitData.hxx"
#include "Env.hxx"


int main(){
    Env * env = new Env();
    if(env->getInitData()){
        InitData();
    }

    Console console;
    console.start();

    vector<Route> routes;

    Route hotelGet("^/hotel$", "GET", HotelController::get);
    Route apiVersion("^/meta/api_ver$", "GET", HotelController::apiVersion);

    Route userGet("^/user$", "POST", UserController::get, { AuthMiddleware::user }); //Maybe change to HTTP GET
    Route userRegister("^/user/register$", "POST", UserController::create);
    Route userUpdate("^/user/update$", "POST", UserController::update, { AuthMiddleware::user });
    Route userLogout("^/user/logout$", "POST", UserController::logout, { AuthMiddleware::user });
    Route userList("^/user/list$", "POST", UserController::list, { AuthMiddleware::staff });
    Route userLogin("^/user/auth$", "POST", UserController::login);

    Route roomGet("^/room/([0-9]+)$", "POST", RoomController::get);
    Route roomList("^/room/list$", "POST", RoomController::list);

    Route bookConfirmPayment("^/book/confirmpayment$", "POST", BookController::confirmPayment, { AuthMiddleware::staff });
    Route bookCreate("^/book/create$", "POST", BookController::create, { AuthMiddleware::user });
    Route bookList("^/book/list$", "POST", BookController::list, { AuthMiddleware::user });
    Route bookUpdate("^/book/update$", "POST", BookController::update, { AuthMiddleware::user });
    Route bookDelete("^/book/delete$", "POST", BookController::del, { AuthMiddleware::user });

    Route averageDays("^/data/averagedays$", "POST", DataAnalysisController::averageDays, { AuthMiddleware::staff });
    Route averagePrice("^/data/averageprice$", "POST", DataAnalysisController::averagePrice, { AuthMiddleware::staff });
    Route mostValuableRooms("^/data/mostvaluablerooms$", "POST", DataAnalysisController::mostValuableRooms, { AuthMiddleware::staff });
    Route mostValuableCustomers("^/data/mostvaluablecustomers$", "POST", DataAnalysisController::mostValuableCustomers, { AuthMiddleware::staff });
    Route mostValuableFeatures("^/data/mostvaluablefeatures$", "POST", DataAnalysisController::mostValuableFeatures, { AuthMiddleware::staff });

    routes.push_back(averageDays);
    routes.push_back(averagePrice);
    routes.push_back(mostValuableRooms);
    routes.push_back(mostValuableCustomers);
    routes.push_back(mostValuableFeatures);

    routes.push_back(hotelGet);
    routes.push_back(apiVersion);

    routes.push_back(userGet);
    routes.push_back(userRegister);
    routes.push_back(userUpdate);
    routes.push_back(userLogout);
    routes.push_back(userLogin);
    routes.push_back(userList);

    routes.push_back(roomGet);
    routes.push_back(roomList);

    routes.push_back(bookConfirmPayment);
    routes.push_back(bookCreate);
    routes.push_back(bookList);
    routes.push_back(bookUpdate);
    routes.push_back(bookDelete);

    Router router(routes);
    router.start();

    console.stop();
}